# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/13 10:06:53 by mraasvel      #+#    #+#                  #
#    Updated: 2020/11/13 21:45:52 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# names
NAME = libft.a
SRC = $(shell find $(SRCDIR) -name "*.c")
OBJ = $(addprefix $(OBJDIR)/, $(shell basename -a $(SRC:.c=.o)))

# directories
OBJDIR = obj
SRCDIR = main_part extra_functions
IDIR = .

#compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I $(IDIR)

#VPATH
VPATH = $(SRCDIR)

.PHONY: all dependencies clean fclean re
all: dependencies $(NAME)

dependencies:
	@mkdir -p obj

$(NAME): $(OBJ) libft.h
	ar rcs $@ $(OBJ)
$(OBJDIR)/%.o: %.c
	$(CC) -o $@ -c $(CFLAGS) $< $(IFLAGS)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
