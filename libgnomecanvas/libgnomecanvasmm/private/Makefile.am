## Copyright (c) 2001
## The libgnomecanvasmm development team.

include $(srcdir)/../../src/Makefile_list_of_hg.am_fragment
files_built_h		= $(files_hg:.hg=_p.h)

private_includedir	= $(includedir)/libgnomecanvasmm-2.0/libgnomecanvasmm/private
private_include_DATA	= $(files_built_h)

distclean-local:
	rm -f $(files_built_h)

