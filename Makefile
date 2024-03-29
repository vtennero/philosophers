# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Isrc/
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -Isrc/
TFLAG = -lpthread 

# Directories
SRC_DIR = src
OBJ_DIR = obj

# New source files
COMMON_SRC = philosophers.c \
genesis.c \
jericho.c \
psalms.c \
revelation.c \
routine.c \
god.c \
utils.c

# Object files for the program, including common functionalities
OBJ = $(addprefix $(OBJ_DIR)/, $(COMMON_SRC:.c=.o))

# Executable name
EXEC = philo

.PHONY: all clean fclean re

# Default rule to build the program
all: $(EXEC)

# Program executable rule
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $^ $(TFLAG) -o $@

# Generic rule for object files, now correctly handles all sources in SRC_DIR
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all
