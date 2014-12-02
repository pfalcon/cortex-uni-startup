/*
 * This is simple example file which does do any I/O and thus
 * can be compiled and run on any Cortex-M MCU. However, to see
 * its effect, you'll need to use debugger.
 */

volatile int var;

void main()
{
    while (1) {
        var ^= 0x55;
    }
}
