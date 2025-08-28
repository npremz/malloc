# Variables
NAME =			libft_malloc
CC =			gcc
CFLAGS =		-fPIC -g #-Wall -Wextra -Werror
MAKEFLAGS +=	--no-print-directory

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
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -c $< -o $@

$(SO_NAME): $(OBJS)
	@$(CC) -shared $(LDFLAGS) -o $@ $(OBJS) $(LIBFT)
	@ln -sf $(SO_NAME) $(SYMLINK)
	@echo $(SO_NAME) compiled.

clean:
	@make -C $(LIBFTDIR) clean
	@rm -rf $(OBJDIR)

fclean: clean
	@make -C $(LIBFTDIR) fclean
	@rm -f $(SO_NAME) $(SYMLINK)

re: fclean all

# Test rule (pour tes tests)
test: all
	@$(CC) $(CFLAGS) -I$(INCDIR) test/main.c -L. -lft_malloc -o test/test_malloc
	@LD_LIBRARY_PATH=. ./test/test_malloc

test-debug: 
	@$(CC) -g -fsanitize=address -I$(INCDIR) test/main.c src/*.c $(LIBFT) -o test/test_malloc_debug
	@./test/test_malloc_debug

info:
    @echo "HOSTTYPE: $(HOSTTYPE)"
    @echo "Library: $(SO_NAME)"
    @echo "Symlink: $(SYMLINK)"

# Debug rule
debug: CFLAGS += -g -fsanitize=address
debug: LDFLAGS += -fsanitize=address
debug: re

.PHONY: all clean fclean re test debug info
