ifndef SRC_FILES_MK
SRC_FILES_MK = 1

include make_settings/settings.mk

SRC := $(shell find $(SDIR) -name "*.c" -type f)
OBJ := $(patsubst $(SDIR)/%.c,$(ODIR)/%.o,$(SRC))
DEP := $(patsubst $(SDIR)/%.c,$(DDIR)/%.d,$(SRC))

endif # SRC_FILES_MK
