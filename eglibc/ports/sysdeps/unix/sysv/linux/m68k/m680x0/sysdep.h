/* Copyright (C) 2010 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#ifndef _LINUX_M68K_M680X0_SYSDEP_H
#define _LINUX_M68K_M680X0_SYSDEP_H 1

#include <sysdeps/unix/sysdep.h>
#include <sysdeps/m68k/m680x0/sysdep.h>
#include <sysdeps/unix/sysv/linux/m68k/sysdep.h>

#define SYSCALL_ERROR_LOAD_GOT(reg)					      \
    lea (_GLOBAL_OFFSET_TABLE_@GOTPC, %pc), reg

#endif
