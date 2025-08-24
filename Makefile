# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:   #
#                                                     +:+ +:+         +:+     #
#    By: npremont <npremont@student.42.fr>          +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2024/01/01 00:00:00 by npremont          #+#    #+#             #
#    Updated: 2024/01/01 00:00:00 by npremont         ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

# Variables
NAME =		libft_malloc
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror -fPIC -g

# Check HOSTTYPE
ifeq ($(HOSTTYPE),)
HOSTTYPE :=	$(shell uname -m)_$(shell uname -s)
endif

# Library names
SO_NAME =	$(NAME)_$(HOSTTYPE).so
SYMLINK =	$(NAME).so

# Directories
SRCDIR =	src
INCDIR =	includes
LIBFTDIR =	libft
OBJDIR =	obj

# Source files
SRCS =  $(SRCDIR)/malloc.c \
		$(SRCDIR)/free.c \
		$(SRCDIR)/realloc.c \
		$(SRCDIR)/mmap_utils.c \
		$(SRCDIR)/zones.c \
		$(SRCDIR)/debug.c

# Object files
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Libft
LIBFT = $(LIBFTDIR)/libft.a

# Rules
all: $(LIBFT) $(SO_NAME)

$(LIBFT):
	@make -C $(LIBFTDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -c $< -o $@

$(SO_NAME): $(OBJS)
	$(CC) -shared -o $@ $(OBJS) $(LIBFT)
	ln -sf $(SO_NAME) $(SYMLINK)

clean:
	@make -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	@make -C $(LIBFTDIR) fclean
	rm -f $(SO_NAME) $(SYMLINK)

re: fclean all

# Test rule (pour tes tests)
test: all
	$(CC) $(CFLAGS) -L. -lft_malloc test/test.c -o test/test_malloc

# Debug rule
debug: CFLAGS += -g -fsanitize=address
debug: re

.PHONY: all clean fclean re test debug
