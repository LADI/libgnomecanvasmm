## Copyright (c) 2001
## The libgnomecanvasmm development team.

SUBDIRS			= private

sublib_name		= libgnomecanvasmm
sublib_namespace	= Gnome
sublib_cflags		= $(LIBGNOMECANVASMM_CFLAGS)

files_extra_h =
files_extra_cc =

include $(top_srcdir)/build_shared/Makefile_build_gensrc.am_fragment

lib_LTLIBRARIES		= libgnomecanvasmm.la
libgnomecanvasmm_la_SOURCES	= $(files_all_cc)
libgnomecanvasmm_la_LDFLAGS	= $(common_ldflags)
libgnomecanvasmm_la_LIBADD	= $(LIBGNOMECANVASMM_LIBS)

