CC = gcc
FLAG = -Wall -Wextra -Werror
INCLUDE = -I/usr/include -Imlx_linux -O3 
LINK = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
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
OJ = $(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) $(INCLUDE) -c $< -o $@

$(NAME): $(OJ)
	$(CC) $(OJ) $(LINK) -o $(NAME)

all: $(NAME)

sani: $(NAME)
	$(CC) $(OJ) $(SANI) $(LINK) -o $(NAME)

clean:
	$(RM) $(OJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean sani
