NAME = pipex
SOURCEDIR = src
BUILDDIR = objs
LIBS = libs


# Makes make look for source in this dir
#VPATH = $(SOURCEDIR)

# headers
INCLUDES = -Iincludes

# Lists sources. Manually because of norm...
SRC_LIST = pipex.c \

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
RUN_ARGS = infile "cmd1.com cmd1.arg1 cmd1.arg2" "cmd2.com cmd2.arg1" outfile

$(NAME): $(OBJS)
	$(CC) $(CF) $(OBJS) $(INCLUDES) -o $(NAME)

objs/%.o: src/%.c
	mkdir -p objs
	$(CC) $(CF) $(INCLUDES) -c $< -o $@

all: $(NAME)

clean:
	rm -rf objs

fclean: clean
	rm -f $(NAME)

re: fclean all

# maybe if bonus.
bonus:

# from here on shit ain't mandatory or bonus
run:

git: fclean
	git add -A
	git commit -m "make git"
	git push

PHONY:	all clean fclean re run