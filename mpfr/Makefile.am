# Copyright 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011 Free Software Foundation, Inc.
# This Makefile.am is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.


AUTOMAKE_OPTIONS = gnu ansi2knr
ACLOCAL_AMFLAGS = -I m4

SUBDIRS = tests

nobase_dist_doc_DATA = AUTHORS BUGS COPYING COPYING.LESSER FAQ.html NEWS TODO \
  examples/ReadMe examples/divworst.c examples/rndo-add.c examples/sample.c \
  examples/version.c

EXTRA_DIST = PATCHES VERSION get_patches.sh round_raw_generic.c gen_inverse.h jyn_asympt.c ieee_floats.h

include_HEADERS = mpfr.h mpf2mpfr.h

BUILT_SOURCES = mparam.h

lib_LTLIBRARIES = libmpfr.la

libmpfr_la_SOURCES = mpfr.h mpf2mpfr.h mpfr-gmp.h mpfr-impl.h		\
mpfr-longlong.h mpfr-thread.h exceptions.c extract.c uceil_exp2.c	\
uceil_log2.c ufloor_log2.c add.c add1.c add_ui.c agm.c clear.c cmp.c	\
cmp_abs.c cmp_si.c cmp_ui.c comparisons.c div_2exp.c div_2si.c		\
div_2ui.c div.c div_ui.c dump.c eq.c exp10.c exp2.c exp3.c exp.c	\
frac.c get_d.c get_exp.c get_str.c init.c inp_str.c isinteger.c		\
isinf.c isnan.c isnum.c const_log2.c log.c modf.c mul_2exp.c mul_2si.c	\
mul_2ui.c mul.c mul_ui.c neg.c next.c out_str.c printf.c vasprintf.c	\
const_pi.c pow.c pow_si.c pow_ui.c print_raw.c print_rnd_mode.c		\
reldiff.c round_prec.c set.c setmax.c setmin.c set_d.c set_dfl_prec.c	\
set_exp.c set_rnd.c set_f.c set_prc_raw.c set_prec.c set_q.c set_si.c	\
set_str.c set_str_raw.c set_ui.c set_z.c sqrt.c sqrt_ui.c sub.c sub1.c	\
sub_ui.c rint.c ui_div.c ui_sub.c urandom.c urandomb.c get_z_exp.c	\
swap.c factorial.c cosh.c sinh.c tanh.c sinh_cosh.c acosh.c asinh.c	\
atanh.c atan.c cmp2.c exp_2.c asin.c const_euler.c cos.c sin.c tan.c	\
fma.c fms.c hypot.c log1p.c expm1.c log2.c log10.c ui_pow.c		\
ui_pow_ui.c minmax.c dim.c signbit.c copysign.c setsign.c gmp_op.c	\
init2.c acos.c sin_cos.c set_nan.c set_inf.c set_zero.c powerof2.c	\
gamma.c set_ld.c get_ld.c cbrt.c volatile.c fits_s.h fits_sshort.c	\
fits_sint.c fits_slong.c fits_u.h fits_ushort.c fits_uint.c		\
fits_ulong.c fits_uintmax.c fits_intmax.c get_si.c get_ui.c zeta.c	\
cmp_d.c erf.c inits.c inits2.c clears.c sgn.c check.c sub1sp.c		\
version.c mpn_exp.c mpfr-gmp.c mp_clz_tab.c sum.c add1sp.c		\
free_cache.c si_op.c cmp_ld.c set_ui_2exp.c set_si_2exp.c set_uj.c	\
set_sj.c get_sj.c get_uj.c get_z.c iszero.c cache.c sqr.c		\
int_ceil_log2.c isqrt.c strtofr.c pow_z.c logging.c mulders.c get_f.c	\
round_p.c erfc.c atan2.c subnormal.c const_catalan.c root.c		\
gen_inverse.h sec.c csc.c cot.c eint.c sech.c csch.c coth.c		\
round_near_x.c constant.c abort_prec_max.c stack_interface.c lngamma.c	\
zeta_ui.c set_d64.c get_d64.c jn.c yn.c rem1.c get_patches.c add_d.c	\
sub_d.c d_sub.c mul_d.c div_d.c d_div.c li2.c rec_sqrt.c min_prec.c	\
buildopt.c digamma.c bernoulli.c isregular.c set_flt.c get_flt.c	\
scale2.c set_z_exp.c ai.c gammaonethird.c

libmpfr_la_LIBADD = @LIBOBJS@

# Libtool -version-info CURRENT[:REVISION[:AGE]] for libmpfr.la
#
# 1. No interfaces changed, only implementations (good):
#    ==> Increment REVISION.
# 2. Interfaces added, none removed (good):
#    ==> Increment CURRENT, increment AGE, set REVISION to 0.
# 3. Interfaces removed or changed (BAD, breaks upward compatibility):
#    ==> Increment CURRENT, set AGE and REVISION to 0.
#
#         MPFR     -version-info
#        2.1.x      -
#        2.2.x    1:x:0
#        2.3.x    2:x:1
#        2.4.x    3:x:2
#        3.0.x    4:x:0
libmpfr_la_LDFLAGS = -version-info 4:1:0

info_TEXINFOS = mpfr.texi

mpfr_TEXINFOS = fdl.texi

MAKEINFOFLAGS = --enable-encoding

# Important note: If for some reason, srcdir is read-only at build time
# (and you use objdir != srcdir), then you need to rebuild get_patches.c
# (with "make get_patches.c") just after patching the MPFR source. This
# should not be a problem in practice, in particular because "make dist"
# automatically rebuilds get_patches.c before generating the archives.
$(srcdir)/get_patches.c: PATCHES get_patches.sh
	(cd $(srcdir) && ./get_patches.sh) > $@ || rm -f $@

# Do not add get_patches.c to CLEANFILES so that this file doesn't
# need to be (re)built as long as no patches are applied. Anyway the
# update of this file should be regarded as part of the patch process,
# and "make clean" shouldn't remove it, just like it doesn't remove
# what has been changed by "patch".
#CLEANFILES = get_patches.c

# Tune program
EXTRA_PROGRAMS = tuneup speed

tuneup_SOURCES = tuneup.c
tuneup_LDADD = -lspeed libmpfr.la
tuneup_LDFLAGS = -static

speed_SOURCES = speed.c
speed_LDADD = -lspeed libmpfr.la
speed_LDFLAGS = -static

tune:
	$(MAKE) $(AM_MAKEFLAGS) tuneup$(EXEEXT)
	./tuneup -v
	$(MAKE) $(AM_MAKEFLAGS) clean
	$(MAKE) $(AM_MAKEFLAGS) libmpfr.la

# In a "make dist", check that libtool -version-info value is up-to-date.
# But if the VERSION file contains "-dev", this is not checked.
# Note: this is a heuristic, to detect some mistakes.
dist-hook:
	grep -q -e -dev $(srcdir)/VERSION || { \
	  mv=`sed -n "s/^\([0-9][0-9]*\)\.\([0-9][0-9]*\)\..*/\1\\\\\\.\2/p" $(srcdir)/VERSION` && \
	  pl=`sed -n "s/^$$mv\.\([0-9][0-9]*\).*/\1/p" $(srcdir)/VERSION` && \
	  printf "mv=%s / pl=%s\n" "$$mv" "$$pl" && \
	  vinfo=`sed -n "s/^# *$$mv\.x *\([0-9][0-9]*\):x:\([0-9][0-9]*\)/\1:$$pl:\2/p" $(srcdir)/Makefile.am` && \
	  printf "vinfo=%s\n" "$$vinfo" && \
	  grep -q -e "-version-info $$vinfo$$" $(srcdir)/Makefile.am; }
