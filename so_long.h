#ifndef SO_LONG_H
#define SO_LONG_H

# include <X11/Xlib.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <X11/extensions/XShm.h>
# include "./mlx_linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>

# include "./ft_malloc/ft_malloc.h"
# include "./gnl/get_next_line.h"

# define MAP_SIZE_MAX 1 << 30
# define BLOCK_SIZE 40
# define DISPLAY_NAME "so_long"

# define FAILED -1
# define SUCCESS 0

# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_ESC 65307

# define PATH_TO_GROUND_IMAGE "./xpm/ground.xpm"
# define PATH_TO_WALL_IMAGE "./xpm/wall.xpm"
# define PATH_TO_COLLECT_IMAGE "./xpm/collect.xpm"
# define PATH_TO_EXIT_IMAGE "./xpm/exit.xpm"
# define PATH_TO_PLAYER_ON_EXIT "./xpm/wall.xpm"//./xpm/player_on_exit.xpm"
# define PATH_TO_PLAYER_IMAGE "./xpm/player.xpm"

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

typedef void image_addr;
typedef void image_data;

typedef struct s_image
{
	t_resolution resolution;
	// void *image_addr;
	image_addr *image_addr;
	image_data *data_addr;
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
	t_image wall;
	t_image ground;
	t_image collect;
	t_image exit;
	t_image player_on_exit;
	t_image player;
} t_display;

typedef struct s_pos
{
	int y;
	int x;
} t_pos;

typedef struct s_me
{
	t_pos current_pos;
	t_pos previous_pos;
}	t_me;

enum {
	KEY_PRESS = 2,
	KEY_RELEASE = 3,
	FOCUS_IN = 9,
	SCREEN_DESTROY = 17
};

enum {
	MASK_KEY_PRESS = (1L<<0),
	MASK_KEY_RELEASE = (1L<<1),
	MASK_FOCUS_CHANGE = (1L<<21),
	MASK_STRUCTURE_NOTIFY = (1L<<17),
};

typedef enum
{
	LEFT = KEY_LEFT,
	RIGHT = KEY_RIGHT,
	UP = KEY_UP,
	DOWN = KEY_DOWN,
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
	MLX_LIB_ERR,
	NO_ERR,
} e_err;

typedef struct s_all
{
	int step_count;
	t_me me;
	t_map map;
	e_err err;
	t_display display;
} t_all;

//file
char **read_file(int fd);
int is_valid_map(char **map, e_err *err);

//main
int is_valid_args(int argc, char **argv, e_err *err);
t_map make_map(char *file_name, e_err *err);
void	finalize(t_all *all);

//screen_ini
int set_display(t_display *display, t_map *map, e_err *err);
int load_texture(t_display *display, e_err *err);
int set_image_buffer(t_image *img, t_display *display, t_map *map, e_err *err);

//screen_main
void	screen_main(t_all *all);
void	set_screen_from_map(t_all *all);
void	update_image(t_display *display, t_map map, t_pos previous_pos, t_pos current_pos);
void	update_screen(t_display *display, t_map *map, t_pos previous_pos, t_pos current_pos);
void	finish_screen(t_display display);

//screen_utils
void	set_block(t_image *img, t_display *display, char map_value, t_pos pos);
void	*my_mlx_get_data_addr(t_image *img);
void	*get_addr_of_pixel(t_image *img, int y, int x);
unsigned int		rgb2int(int r, int g, int b);
unsigned int	get_color(t_image *img, int y, int x);

//others
void move_main(t_all *all, int dir);
void	ft_error(t_all *all);
void	ft_exit(t_all *all);

//general_utils
void ft_putchar(char c);
void	ft_putnbr(int n);
void zero_reset(void *a, void *b,void *c, void *d);
int ft_strlen(char *s);
int ft_strcmp(char *s1, char *s2);
void	ft_bzero(void *p, int n);
void	ft_memcpy(char *dest, char *src, int len);
char	**ft_split(char *s, char c);







#endif
