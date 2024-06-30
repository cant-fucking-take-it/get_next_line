SRC_FILES = get_next_line.c get_next_line_utils.c
OBJ_FILES = $(patsubst %.c,%.o,$(SRC_FILES))
HDR_FILES = get_next_line.h

SRC_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ_BONUS = $(patsubst %.c,%.o,$(SRC_BONUS))
HDR_BONUS = get_next_line_bonus.h

SRC_TEST = $(wildcard $(TEST_DIR)/*.c)
OBJ_TEST = $(patsubst %.c,%.o,$(SRC_TEST))
TEST_DIR = tests

NAME = get_next_line

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I.

all: $(NAME) Makefile $(HDR_FILES)

$(NAME): main.o $(OBJ_FILES)

$(NAME)_bonus: main_bonus.o $(OBJ_BONUS) 

bonus: $(NAME)_bonus Makefile $(HDR_BONUS)

test: CFLAGS += -fsanitize=address
test: all tests.o Makefile

tests.o: $(OBJ_TEST) $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

clean reclean:
	rm -rf $(OBJ_FILES) $(OBJ_BONUS) 

fclean: clean
	rm -f $(NAME)

re: fclean all reclean

rebonus: fclean bonus reclean

info:
	$(info $(SRC_FILES))
	$(info $(SRC_BONUS))

.PHONY: all fclean reclean re bonus rebonus info test
