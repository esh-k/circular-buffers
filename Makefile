# Add new projects here
PROJECTS = \
	CCircularBuffer\
	CppCircularBuffer\

BUILDS = $(patsubst %, build_%, $(PROJECTS))
CLEANS = $(patsubst %, clean_%, $(PROJECTS))

# build single component
# make build_<project_name>
# clean single component
# make clean_<project_name>

all: $(BUILDS)

.PHONY: all

# $(PROJECTS): $(PROJECTS)
# 	cd $^ && $(MAKE)

define BUILD_RULE
build_$(1): $(1)
	cd $(1) && $(MAKE)
endef
$(foreach p, $(PROJECTS),$(eval $(call BUILD_RULE,$(p))))

.PHONY: $(BUILDS)

clean: $(CLEANS)

define CLEAN_RULE
clean_$(1): $(1)
	cd $(1) && $(MAKE) clean
endef
$(foreach p, $(PROJECTS),$(eval $(call CLEAN_RULE,$(p))))

.PHONE: $(CLEANS)
