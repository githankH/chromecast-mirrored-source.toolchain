/* Copyright (C) 1995, 1996, 1997, 2005 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ulrich Drepper <drepper@gnu.ai.mit.edu>, 1995.

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

#include <wchar.h>


/* Copy no more than N wide-characters of SRC to DEST.	*/
wchar_t *
__wcsncpy_chk (wchar_t *dest, const wchar_t *src, size_t n, size_t destlen)
{
  if (__builtin_expect (destlen < n, 0))
    __chk_fail ();

  /* This function is not often enough used to justify not using a
     tail call.  */
  return __wcsncpy (dest, src, n);
}
