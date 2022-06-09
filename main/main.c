#include "../so_long.h"

void	finalize(t_all *all)
{
	ft_exit(all);
}

static void	_ini_all(t_all *all)
{
	ft_bzero(all, sizeof(t_all));
	all->err = NO_ERR;
}

int main(int argc, char **argv)
{
	t_all all;
	t_display display;
	display.mlx = mlx_init();
	display.mlx_win = mlx_new_window(display.mlx, 1000, 1000, "test");
	display.ground.img = mlx_xpm_file_to_image(display.mlx, PATH_TO_GROUND_IMAGE, &display.ground.resolution.x, &display.ground.resolution.y);
	printf("resolution x: %d, y %d\n", display.ground.resolution.x, display.ground.resolution.y);
	mlx_put_image_to_window(display.mlx, display.mlx_win, display.ground.img, 0, 0);
	mlx_loop(display.mlx);
	return(0);






	_ini_all(&all);
	if (!is_valid_args(argc, argv, &all.err))
		ft_error(&all);
	all.map = make_map(argv[1], &all.err);
	if (all.map.map == NULL)
		ft_error(&all);
	if (!is_valid_map(all.map.map, &all.err))
		ft_error(&all);
	screen_main(all);
}
