
EXAMPLE_DIR = canvas

EXTRA_DIST = \
canvas/Makefile \
canvas/canvas.cc \
canvas/example.png \
canvas/canvas_events.cc \
canvas/canvas_affine.cc \

examples:
	for subdir in $(EXAMPLE_DIR); do \
	(cd $$subdir; make all) ; \
	done

examples-clean:
	for subdir in $(EXAMPLE_DIR); do \
	(cd $$subdir; make clean) ; \
	done
	
