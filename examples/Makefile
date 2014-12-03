# Path to cortex-startup toplevel dir
# You can reuse this Makefile for your projects by just updating this var
CORTEX_STARTUP = ..

CROSS_COMPILE = arm-none-eabi-
GCC_VER =
CC = $(CROSS_COMPILE)gcc$(GCC_VER)
# Target subarch to build for
TARGET = stm32/stm32-smallest
# Name output dir after target. Other alternative for multi-dir projects is
# bin-$(TARGET)
TARGETDIR = bin-$(TARGET)
# Short one-character alias for TARGETDIR
T = $(TARGETDIR)

STARTUP = $(CORTEX_STARTUP)/startup.c
LINKSCRIPT = $(TARGET).ld

# Generic target flags which used for both compiling and linking. We compile
# startup code at linking stage, so this may (and sometimes should) contain
# -D defines
TARGET_FLAGS   = -mthumb -mcpu=cortex-m3 -DNO_SYSTEMINIT
TARGET_CFLAGS  = $(TARGET_FLAGS)
TARGET_LDFLAGS = $(TARGET_FLAGS) --static -nostartfiles -T$(LINKSCRIPT) $(STARTUP)

CFLAGS  = $(TARGET_CFLAGS)
LDFLAGS = $(TARGET_LDFLAGS) -Wl,-Map=$@.map,--cref
# We don't have libs per se, but for includes in linkscripts to work,
# they should be on -L path.
LDLIBS = -L$(CORTEX_STARTUP)

all: $T/example-no-io

# This corresponds to a builtin make rule, except puts object files to TARGETDIR
$T/%.o: %.c
	mkdir -p $T
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $^ -o $@

# Add rules for specific applications here
$T/example-no-io: $T/example-no-io.o
$T/example-no-io.o: example-no-io.c
