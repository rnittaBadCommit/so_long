CC = gcc
FLAG = -g3 -Wall -Wextra -Werror
INCLUDE = -I/usr/include -Imlx_linux -O3
LINK = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
SANI = -g -fsanitize=address
FLAGSEC = -L./lib/ -lmlx_Linux -Wall -lXext -lX11 -lm
NAME = so_long
SRC_ERR=./err/err.c
SRC_EXIT=./exit/exit.c
SRC_FILE=./file/check_file.c ./file/read_file.c ./file/is_valid_char.c
SRC_SCREEN_INI=./screen/screen_ini/load_texture.c ./screen/screen_ini/set_display.c ./screen/screen_ini/set_image_buffer.c ./screen/screen_ini/set_initial_image.c ./screen/screen_ini/set_me.c
SRC_SCREEN_MAIN=./screen/screen_main/screen_main.c
SRC_SCREEN_UTILS=./screen/screen_utils/mlx_utils.c ./screen/screen_utils/set_block.c
SRC_SCREEN=$(SRC_SCREEN_INI) $(SRC_SCREEN_MAIN) $(SRC_SCREEN_UTILS)
SRC_UTILS=./utils/util1.c ./utils/util2.c ./utils/util3.c
SRC_MAIN=./main/check_args.c ./main/main.c ./main/make_map.c
SRC_MOVE=./move/move.c
SRC_FT_MALLOC=./ft_malloc/ft_free.c ./ft_malloc/ft_malloc.c

SRC=$(SRC_ERR) $(SRC_EXIT) $(SRC_FILE) $(SRC_SCREEN) $(SRC_UTILS) $(SRC_MAIN) $(SRC_MOVE) $(SRC_FT_MALLOC)
RM = rm -f
OJ = $(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) $(INCLUDE) -c $< -o $@

$(NAME): $(OJ)
	make -C mlx_linux
	$(CC) $(FLAGSEC) $(OJ) $(LINK) -o $(NAME)

all: $(NAME)

sani: $(NAME)
	$(CC) $(OJ) $(SANI) $(LINK) -o $(NAME)

clean:
	$(RM) $(OJ)
	make clean -C mlx_linux

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean sani
