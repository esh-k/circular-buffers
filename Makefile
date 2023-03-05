# Add new projects here
PROJECTS = circular-buffer-c

$(PROJECTS)/build: $(PROJECTS)
	cd $^ && $(MAKE)

.PHONY: $(PROJECTS)/build

clean: $(PROJECTS)
	cd $^ && $(MAKE) clean
