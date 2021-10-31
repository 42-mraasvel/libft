ifndef SETTINGS_MK
SETTINGS_MK = 1

# Naming
NAME := libft.a

# Directories
SDIR := src
IDIR := includes
TDIR := tmp
ODIR := $(TDIR)/obj
DDIR := $(TDIR)/dep

# Compilation
CC := gcc
CFLAGS := -Wall -Wextra -Werror
LINK := ar rcs
IFLAGS := -I$(IDIR) -I.

endif # SETTINGS_MK
