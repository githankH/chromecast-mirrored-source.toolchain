ifeq ($(subdir),csu)
sysdep_routines += hp-timing
elide-routines.os += hp-timing
endif

ifeq ($(subdir),csu)
CFLAGS-initfini.s += -mcpu=v9
endif

ifeq ($(subdir),string)
sysdep_routines += align-cpy
endif
