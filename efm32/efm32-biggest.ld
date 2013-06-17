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
    flash   :   ORIGIN = 0x00000000, LENGTH = 1M
    sram    :   ORIGIN = 0x20000000, LENGTH = 128K
}

/* Include main link script. Note: it will be searched in -L paths. */
INCLUDE linkscript.ld
