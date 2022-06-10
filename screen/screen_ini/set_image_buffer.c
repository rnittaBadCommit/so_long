#include "../../so_long.h"

void	_set_image_image_buffer(t_image *img, t_display *display, t_map *map)
{
	t_pos	pos;

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

static t_image	_make_image_buffer(void *mlx, \
	t_resolution resolution, e_err *err)
{
	t_image	img;

	img.image_addr = mlx_new_image(mlx, resolution.y, resolution.x);
	img.data_addr = my_mlx_get_data_addr(&img);
	if (img.data_addr == NULL)
		*err = MLX_LIB_ERR;
	return (img);
}

int	set_image_buffer(t_image *img, t_display *display, t_map *map, e_err *err)
{
	*img = _make_image_buffer(display->mlx, display->resolution, err);
	if (*err != NO_ERR)
		return (FAILED);
	_set_image_image_buffer(img, display, map);
	return (SUCCESS);
}
