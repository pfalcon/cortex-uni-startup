/*
 * Unified Cortex Startup - C startup file
 *
 * This file is in public domain
 *
 * Put together by Paul Sokolovsky based on article by Vanya Sergeev
 * http://dev.frozeneskimo.com/notes/cortex_cmsis/ , GNU ld documentation
 * and numerous other public resources.
 *
 */

#include <stdint.h>

/* Declare linker-defined symbols. The only thing of interest
   regarding these symbols is their *address*. uint32_t hints
   of alignment. */
extern uint32_t _end_text;
extern uint32_t _start_data;
extern uint32_t _end_data;
extern uint32_t _start_bss;
extern uint32_t _end_bss;
extern uint32_t _start_stack;
extern uint32_t _end_stack;

/* C main function */
extern int main(void);
/* Device-specific initialization function. Optional, any Cortex-M
   should be able to start up in its default mode on its own, though
   some may have errata for some peripherals (including PLL) which
   this function may "patch". */
extern void SystemInit(void);

void Dummy_Handler(void);

/* Cortex-M core interrupt handlers */
#define ALIAS(sym) __attribute__((weak, alias (sym)))

void Reset_Handler(void);
void NMI_Handler(void) ALIAS("Dummy_Handler");
void HardFault_Handler(void) ALIAS("Dummy_Handler");
void MemManage_Handler(void) ALIAS("Dummy_Handler");
void BusFault_Handler(void) ALIAS("Dummy_Handler");
void UsageFault_Handler(void) ALIAS("Dummy_Handler");
void SVC_Handler(void) ALIAS("Dummy_Handler");
void DebugMon_Handler(void) ALIAS("Dummy_Handler");
void PendSV_Handler(void) ALIAS("Dummy_Handler");
void SysTick_Handler(void) ALIAS("Dummy_Handler");


/* 16 standard Cortex-M vectors - these are present in every MCU */
void *core_vector_table[16] __attribute__ ((section(".cortex_vectors"))) = {
    // See http://sourceware.org/binutils/docs/ld/Source-Code-Reference.html
    // why the address is used here (if not intuitive)
    &_end_stack,
    Reset_Handler,
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0,
    0,
    0,
    0,
    SVC_Handler,
    DebugMon_Handler,
    0,
    PendSV_Handler,
    SysTick_Handler,
};

/* Based on http://sourceware.org/binutils/docs/ld/Output-Section-LMA.html */
void Reset_Handler(void) {
    register uint32_t *src, *dst;

    /* Copy data section from flash to RAM */
    src = &_end_text;
    dst = &_start_data;
    while (dst < &_end_data)
        *dst++ = *src++;

    /* Clear the bss section, assumes .bss goes directly after .data */
    dst = &_start_bss;
    while (dst < &_end_bss)
        *dst++ = 0;

    SystemInit();
    main();
    while (1);
}

void Dummy_Handler(void) {
    /* Receiving an unexpected interrupt is considered a bug
       in the program. Let's make it very visible by just
       hanging the processing. Ignoring it by just returning
       may result in very complicated debugging sessions. */
    while (1);
}
