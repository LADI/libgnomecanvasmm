## Copyright (c) 2001
## The libgnomecanvasmm development team.

SUBDIRS			= private

sublib_name		= libgnomecanvasmm
sublib_namespace	= Gnome
sublib_cflags		= $(LIBGNOMECANVASMM_CFLAGS)

files_extra_h		= affinetrans.h canvas-property.h init.h point.h
files_extra_cc		= affinetrans.cc init.cc point.cc

include $(top_srcdir)/build_shared/Makefile_build_gensrc.am_fragment

lib_LTLIBRARIES			= libgnomecanvasmm-1.3.la
libgnomecanvasmm_1_3_la_SOURCES	= $(files_all_cc)
libgnomecanvasmm_1_3_la_LDFLAGS	= $(common_ldflags)
libgnomecanvasmm_1_3_la_LIBADD	= $(LIBGNOMECANVASMM_LIBS)

