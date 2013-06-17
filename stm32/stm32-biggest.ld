/*
 * Unified Cortex Startup - GNU ld linker script file
 *
 * This file is in public domain
 *
 * Put together by Paul Sokolovsky
 *
 */

MEMORY
{
    flash   :   ORIGIN = 0x08000000, LENGTH = 1M /* They say 1M devices have 2 banks of 512K, go figure */
    sram    :   ORIGIN = 0x20000000, LENGTH = 96K
}

/* Include main link script. Note: it will be searched in -L paths. */
INCLUDE linkscript.ld
