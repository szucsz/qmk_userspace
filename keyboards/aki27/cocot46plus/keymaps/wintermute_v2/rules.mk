VIA_ENABLE = no
MOUSEKEY_ENABLE = yes
CAPS_WORD_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
CONSOLE_ENABLE = yes
COMMAND_ENABLE = no
ENCODER_MAP_ENABLE = yes
COMBO_ENABLE = yes

USERSPACE_VERSION_FILE = $(INTERMEDIATE_OUTPUT)/src/userspace_version.h
CURR_GIT_HASH := $(shell git -C "$(QMK_USERSPACE)" rev-parse --short HEAD)
PREV_GIT_HASH := $(shell cat $(USERSPACE_VERSION_FILE) 2>/dev/null | grep -o '[a-f0-9]\{7,40\}')

.PHONY: FORCE
FORCE :

$(USERSPACE_VERSION_FILE): FORCE
	@if [ "$(CURR_GIT_HASH)" != "$(PREV_GIT_HASH)" ]; then \
		echo "#pragma once" > $(USERSPACE_VERSION_FILE); \
		echo "#define USERSPACE_GIT_HASH \"$(CURR_GIT_HASH)\"" >> $(USERSPACE_VERSION_FILE); \
		echo "#define USERSPACE_VERSION  \"$$(git -C "$(QMK_USERSPACE)" describe --abbrev=0 --tags 2>/dev/null)\"" >> $(USERSPACE_VERSION_FILE); \
		echo "#define QMK_VERSION_SHORT  \"$$(git -C "$(TOP_DIR)" describe --abbrev=0 --tags 2>/dev/null)\"" >> $(USERSPACE_VERSION_FILE); \
	fi

generated-files: $(USERSPACE_VERSION_FILE)

POST_CONFIG_H += $(USERSPACE_VERSION_FILE)
