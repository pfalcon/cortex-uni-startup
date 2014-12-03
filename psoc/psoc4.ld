/*
 * Unified Cortex Startup - GNU ld linker script file
 *
 * This file is in public domain
 *
 * Put together by Paul Sokolovsky
 *
 * Reference: PSoC4_Architecture_TRM_001-85634_0C_V.pdf
 */

MEMORY
{
    flash   :   ORIGIN = 0x00000000, LENGTH = 32K
    sram    :   ORIGIN = 0x20000000, LENGTH = 4K
}

/* Include main link script. Note: it will be searched in -L paths. */
INCLUDE linkscript.ld
