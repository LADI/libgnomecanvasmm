
doxygen_configfile = Doxyfile
web_path_reference = /home/groups/g/gt/gtkmm/htdocs/gtkmm2/reference

EXTRA_DIST	= README $(doxygen_configfile)


gtkmm-reference: $(doxygen_configfile)
	doxygen $(doxygen_configfile)

gtkmm-reference-html: gtkmm-reference

gtkmm-reference-html.tar.gz: gtkmm-reference-html
	tar -cf - $< | gzip > $@


post-html: gtkmm-reference
	(cd html && tar -cf - *.html *.gif *.css | gzip -3 | \
	 ssh $$SSH_OPT $$USER@gtkmm.sourceforge.net "cd $(web_path_reference)/html ; gunzip | tar -xvf - ; chmod a+r,g+w * ; chgrp gtkmm *")


all-local: gtkmm-reference

clean-local:
	-rm -rf html
	-rm -f gtkmm-reference-html.tar.gz

