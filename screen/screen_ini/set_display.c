#include "../../so_long.h"

static void _set_resolution(t_resolution *resolution, t_map *map)
{
	resolution->y = map->height * BLOCK_SIZE;
	resolution->x = map->width * BLOCK_SIZE;
}

static void _set_mlx_mlxwin(t_display *display)
{
	display->mlx = mlx_init();
	display->mlx_win = mlx_new_window(display->mlx, display->resolution.x, display->resolution.y, display->name);
}

int    set_images(t_display *display, t_map *map, e_err *err)
{
    if (load_texture(display, err) == FAILED)
	{
        return (FAILED);
	}
	mlx_put_image_to_window(display->mlx, display->mlx_win, display->wall.img, 0, 0);
	while (1);
	//printf("load_texture done\n");
    if (set_image_buffer(&display->front_img, display, map, err) == FAILED)
		return (FAILED);
	//printf("set_iamge_buffer sone\n");
    if (set_image_buffer(&display->back_img, display, map, err) == FAILED)
		return (FAILED);
    return (SUCCESS);
}

int set_display(t_display *display, t_map *map, e_err *err)
{
	display->name = DISPLAY_NAME;
	_set_resolution(&display->resolution, map);
	_set_mlx_mlxwin(display);
	//printf("err: %d\n", *err);
	return (set_images(display, map, err));
}
