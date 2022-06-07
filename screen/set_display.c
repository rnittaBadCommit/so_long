#include "../so_long.h"

static void _set_resolution(t_resolution *resolution, t_map map)
{
	resolution->y = map.height * BLOCK_SIZE;
	resolution->x = map.width * BLOCK_SIZE;
}

static t_image _make_image(void *mlx, t_resolution resolution)
{
	t_image img;

	img.img = mlx_new_window(mlx, resolution.y, resolution.x, DISPLAY_NAME);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	return (img);
}

static void _set_images(t_display *display)
{
	display->front_img = _make_image(display->mlx, display->resolution);
	display->back_img = _make_image(display->mlx, display->resolution);
}

static void _set_mlx_mlxwin(t_display *display)
{
	display->mlx = mlx_init();
	display->mlx_win = mlx_new_window(display->mlx, display->resolution.y, display->resolution.x, display->name);
}

void set_display(t_display *display, t_map map)
{
	display->name = DISPLAY_NAME;
	_set_resolution(&display->resolution, map);
	_set_mlx_mlxwin(display);
	_set_images(display);
}
