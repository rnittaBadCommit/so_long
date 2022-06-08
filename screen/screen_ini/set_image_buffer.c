#include "../../so_long.h"

void	_set_image_image_buffer(t_image *img, t_display *display, t_map *map)
{
	t_pos pos;

	pos.y = 0;
	while (pos.y < map->height)
	{
		pos.x = 0;
		while (pos.x < map->width)
		{
			set_block(img, display, map->map[pos.y][pos.x], pos);
			pos.x++;
		}
		pos.y++;
	}
}

static t_image _make_image_buffer(void *mlx, t_resolution resolution)
{
	t_image img;

	img.img = mlx_new_image(mlx, resolution.y, resolution.x);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	return (img);
}

void set_image_buffer(t_image *img, t_display *display, t_map *map)
{
	*img = _make_image_buffer(display->mlx, display->resolution);
    _set_image_image_buffer(img, display, map);
}
