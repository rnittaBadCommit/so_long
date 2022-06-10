#include "../../so_long.h"

static int _load_image(void *mlx, t_image *img, char *path)
{
	img->image_addr = mlx_xpm_file_to_image(mlx, path, &img->resolution.x, &img->resolution.y);
	if (!img->image_addr)
		return (-1);
	img->data_addr = my_mlx_get_data_addr(img);
	return (0);
}

int load_texture(t_display *display, e_err *err)
{
	if (_load_image(display->mlx, &display->ground, PATH_TO_GROUND_IMAGE) ||
		_load_image(display->mlx, &display->wall, PATH_TO_WALL_IMAGE) ||
		_load_image(display->mlx, &display->collect, PATH_TO_COLLECT_IMAGE) ||
		_load_image(display->mlx, &display->exit, PATH_TO_EXIT_IMAGE) ||
		_load_image(display->mlx, &display->player, PATH_TO_PLAYER_IMAGE) ||
		_load_image(display->mlx, &display->player_on_exit, PATH_TO_PLAYER_ON_EXIT))
	{
		*err = MLX_LIB_ERR;
		return (FAILED);
	}
	return (0);
}
