# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/24 19:18:03 by mraasvel      #+#    #+#                  #
#    Updated: 2020/11/01 21:14:01 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

LIBNAME = libft.a
NORM_SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

ifdef WITH_BONUS
SRC = $(NORM_SRC) $(BONUS_SRC)
else
SRC = $(NORM_SRC)
endif
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re
all: $(LIBNAME)

libft.a: $(OBJ)
	ar rc $(LIBNAME) $^
%.o: %.c
	$(CC) $(CFLAGS) $<

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
fclean: clean
	rm -f $(LIBNAME)
re: fclean all

bonus:
	$(MAKE) WITH_BONUS=1 all
