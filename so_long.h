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

# include "./ft_malloc/ft_malloc.h"
# include "./gnl/get_next_line.h"

# define MAP_SIZE_MAX 1 << 30
# define BLOCK_SIZE 10
# define DISPLAY_NAME "so_long"

# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_ESC 65307

# define PATH_TO_GROUND_IMAGE "./xpm/ground.xpm"
# define PATH_TO_WALL_IMAGE "./xpm/wall.xpm"
# define PATH_TO_COLLECT_IMAGE "./xpm/collect.xpm"
# define PATH_TO_EXIT_IMAGE "./xpm/exit.xpm"
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

typedef struct s_image
{
	t_resolution resolution;
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
	t_image wall;
	t_image ground;
	t_image collect;
	t_image exit;
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
	t_me me;
	t_map map;
	e_err err;
	t_display display;
} t_all;

unsigned int		rgb2int(int r, int g, int b);
void zero_reset(void *a, void *b,void *c, void *d);
char **read_file(int fd, e_err *err);
t_map make_map(char *file_name, e_err *err);
void key_handle(int dir, char **map);
int is_valid_args(int argc, char **argv, e_err *err);
void set_display(t_display *display, t_map map);
int ft_strlen(char *s);
int ft_strcmp(char *s1, char *s2);
int move(e_dir dir, t_me *me, char **map);
void move_main(t_all *all, int dir);
int is_valid_map(char **map, e_err *err);
void	ft_exit(t_all *all);
void    update_screen(t_display *display);
void	screen_main(t_all all, t_display display);
void	finalize(t_all *all);
void    *get_addr_of_pixel(t_image img, int y, int x);
void    update_image(t_display display, t_map map, t_pos previous_pos, t_pos current_pos);
void    set_block(t_display display, char map_value, t_pos pos);
void    ft_error(t_all all);
unsigned int	get_color(t_image img, int y, int x);
int load_images(t_display *display, e_err *err);
void	set_image(t_display display, t_map map);

#endif
