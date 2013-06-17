#!/usr/bin/env python
import sys
import os


irqs = []
f = open(sys.argv[1])
no = 0
for l in f:
    l = l.strip()
    if l[0] == "#":
        continue
    fields = [f.strip() for f in l.split()]
    assert len(fields) <= 2
    if len(fields) == 2:
        fields[0] = int(fields[0])
    else:
        fields = [no, fields[0]]
        no += 1
    irqs.append(fields)

dir, fname = os.path.split(sys.argv[1])
fout = open(dir + "/startup-" + fname.rsplit('.', 1)[0] + ".c", "w")
print >>fout, '#include "../startup.c"'
print >>fout

for i in irqs:
    print >>fout, 'void %s_IRQHandler(void) ALIAS("Dummy_Handler");' % i[1]


print >>fout

print >>fout, 'void *vendor_vector_table[] __attribute__ ((section(".vendor_vectors"))) = {'
no = 0
for i in irqs:
    if no != i[0]:
        # Gap detected
        assert no < i[0]
        while no < i[0]:
            print >>fout, '0,'
            no += 1

    assert i[0] == no
    print >>fout, '%s_IRQHandler,' % i[1]
    no += 1

print >>fout, '};'
