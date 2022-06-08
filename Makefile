CC = gcc
FLAG = -Wall -Wextra -Werror
INCLUDE = -I/usr/include -Imlx_linux -O3 
LINK = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
SANI = -g -fsanitize=address
FLAGSEC = -L./lib/ -lmlx_Linux -Wall -lXext -lX11 -lm
NAME = miniRT
SRC_ERR=./err/err.c
SRC_EXIT=./exit/exit.c
SRC_FILE=./file/check_file.c ./file/read_file.c
SRC_SCREEN=./screen/finish_screen.c ./screen/get_address.c ./screen/load_image.c ./screen/screen_main.c ./screen/set_display.c ./screen/update_image.c ./screen/update_screen.c 
SRC_UTILS=./utils/image_utils.c ./utils/util1.c
SRC_MAIN=./main/check_args.c ./main/main.c ./main/make_map.c
SRC_MOVE=./move/move.c
SRC_GNL=./gnl/get_next_line.c ./gnl/get_next_line_utils.c
SRC_FT_MALLOC=./ft_malloc/ft_free.c ./ft_malloc/ft_malloc.c
SRC=$(SRC_ERR) $(SRC_EXIT) $(SRC_FILE) $(SRC_SCREEN) $(SRC_UTILS) $(SRC_MAIN) $(SRC_MOVE) $(SRC_GNL) $(SRC_FT_MALLOC) 
RM = rm -f
OJ = $(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) $(INCLUDE) -c $< -o $@

$(NAME): $(OJ)
	$(CC) $(FLAGSEC) $(OJ) $(LINK) -o $(NAME)

all: $(NAME)

sani: $(NAME)
	$(CC) $(OJ) $(SANI) $(LINK) -o $(NAME)

clean:
	$(RM) $(OJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean sani
