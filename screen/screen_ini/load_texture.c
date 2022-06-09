#include "../../so_long.h"

static int _load_image(void *mlx, t_image *img, char *path)
{
    img->img = mlx_xpm_file_to_image(mlx, path, &img->resolution.x, &img->resolution.y);
    if (!img->img)
        return (-1);
    //printf("ini img->addr: %p\n", img->addr);
    img->addr = my_mlx_get_data_addr(img->img);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    //printf("set img->addr: %p\n", img->addr);
    return (0);
}

int load_texture(t_display *display, e_err *err)
{
    if (_load_image(display->mlx, &display->ground, PATH_TO_GROUND_IMAGE) ||
        _load_image(display->mlx, &display->wall, PATH_TO_WALL_IMAGE) ||
        _load_image(display->mlx, &display->collect, PATH_TO_COLLECT_IMAGE) ||
        _load_image(display->mlx, &display->exit, PATH_TO_EXIT_IMAGE) ||
        _load_image(display->mlx, &display->player, PATH_TO_PLAYER_IMAGE))
    {
        *err = MLX_LIB_ERR;
        return (FAILED);
    }
    return (0);
}
