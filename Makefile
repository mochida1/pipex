NAME = pipex
SOURCEDIR = src
BUILDDIR = objs
LIBS = libs


# Makes make look for source in this dir
#VPATH = $(SOURCEDIR)

# headers
INCLUDES = -I /includes

# Lists sources. Manually because of norm...
SRC_LIST = pipex.c \
create_child.c \
create_pipe.c \
exec_cmdx.c \
init_data.c \
ft_strlen.c \
ft_putstr_fd.c \
ft_strdup.c \
ft_split.c \
check_argc.c \
get_command.c \
get_path.c \
get_exec_error.c \
get_commands_utils.c \

# Names sources
SOURCES = $(addprefix $(SOURCEDIR)/,$(SRC_LIST))

# Names objects
OBJS := $(subst $(SOURCEDIR),$(BUILDDIR),$(SOURCES:.c=.o))

# Compiler
CC = gcc
CF = -Wall -Wextra -Werror
GDB = -ggdb
VAL = valgrind ./$(NAME)

# Arguments to test the program with
RUN_ARGS = infile "ls -la" "grep file" outfile

$(NAME): $(OBJS)
	@$(CC) $(CF) $(OBJS) $(INCLUDES) -o $(NAME)

objs/%.o: src/%.c
	@mkdir -p objs
	@$(CC) $(CF) $(INCLUDES) -c $< -o $@

all: $(NAME)

clean:
	@rm -rf objs

fclean: clean
	@rm -f $(NAME)

re: fclean all

# maybe if bonus.
bonus:

# from here on shit ain't mandatory or bonus
run: all
	./$(NAME)

git: fclean
	git add -A
	git commit -m "make git"
	git push

PHONY:	all clean fclean re run
