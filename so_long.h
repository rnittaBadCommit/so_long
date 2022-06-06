#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

#include "./ft_malloc/ft_malloc.h"
#include "./gnl/get_next_line.h"

#define MAP_SIZE_MAX 1 << 30
#define BLOCK_SIZE 10
#define DISPLAY_NAME "so_long"

typedef struct s_map
{
	char **map;
	int width;
	int height;
	int num_collect;
} t_map;

typedef struct s_resolution
{
	int y;
	int x;
} t_resolution;

typedef struct s_image
{
	void *img;
	void *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_image;

typedef struct s_display
{
	void *mlx;
	void *mlx_win;
	char *name;
	t_resolution resolution;
	t_image front_img;
	t_image back_img;
} t_display;

typedef struct s_me
{
	int y;
	int x;
} t_me;

typedef enum
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	NO_MOVE,
} e_dir;

typedef enum
{
	BAD_ARG_NUM,
	BAD_FILE_NAME,
	CANNOT_OPEN_FILE,
	TOO_LARGE_MAP,
	NOT_RECTANGLE,
	INVALID_CHAR,
	INVALID_CHAR_NUM,
	NOT_CLOSED_MAP,
	NO_ERR,
} e_err;

typedef struct s_all
{
	t_me me;
	t_map map;
	e_err err;
} t_all;

int		rgb2int(double *rgb);
void zero_reset(void *a, void *b,void *c, void *d);
char **read_file(int fd, e_err *err);
t_map make_map(char *file_name, e_err *err);
void key_handle(int dir, char **map);
int is_valid_args(int argc, char **argv, e_err *err);
int		rgb2int(double *rgb);
void set_display(t_display *display, t_map map);
int ft_strlen(char *s);

#endif
