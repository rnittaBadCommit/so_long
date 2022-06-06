CC = gcc
FLAG = -Wall -Wextra -Werror
SANI = -g -fsanitize=address
FLAGSEC = -L./lib/ -lmlx_Linux -Wall -lXext -lX11 -lm
NAME = miniRT
SRC_FILE=./file/check_file.c ./file/read_file.c
SRC_SCREEN=./screen/make_screen.c ./screen/set_display.c
SRC_UTILS=./utils/image_utils.c ./utils/util1.c
SRC_MAIN=./main/check_args.c ./main/main.c ./main/make_map.c ./main/move.c
SRC_GNL=./gnl/get_next_line.c ./gnl/get_next_line_utils.c
SRC=$(SRC_FILE) $(SRC_SCREEN) $(SRC_UTILS) $(SRC_MAIN)
RM = rm -f
INCS = includes
OJ = $(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) -c $< -o $@ -I $(INCS)

$(NAME): $(OJ)
	$(CC) $(FLAG) -o $(NAME) $(OJ) $(FLAGSEC)

all: $(NAME)

sani: $(NAME)
	$(CC) $(FLAG) $(SANI) -o $(NAME) $(OJ) $(FLAGSEC)

clean:
	$(RM) $(OJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean sani
