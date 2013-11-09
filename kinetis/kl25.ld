/*
 * Unified Cortex Startup - GNU ld linker script file
 *
 * This file is in public domain
 *
 * Put together by Paul Sokolovsky
 *
 */

/* KL25P80M48SF0RM.pdf p.72, p.105 */
MEMORY
{
    flash   :   ORIGIN = 0x00000000, LENGTH = 128K
    sram    :   ORIGIN = 0x20000000, LENGTH = 16K
}

/* Include main link script. Note: it will be searched in -L paths. */
INCLUDE linkscript.ld
