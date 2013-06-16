import sys


irqs = []
f = open(sys.argv[1])
for l in f:
    l = l.strip()
    if l[0] == "#":
        continue
    irqs.append(l)

print '#include "startup.c"'
print

for i in irqs:
    print 'void %s_IRQHandler(void) ALIAS("Dummy_Handler");' % i


print

print 'void *vendor_vector_table[] __attribute__ ((section(".vendor_vectors"))) = {'
for i in irqs:
    print '%s_IRQHandler,' % i
print '};'
