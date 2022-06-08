#include "../so_long.h"

static void	_my_mlx_destroy_image(void *mlx, void *addr)
{
	if (mlx && addr)
		mlx_destroy_image(mlx, addr);
}

static void	_my_mlx_destroy_window(void *mlx, void *mlx_win)
{
	if (mlx && mlx_win)
		mlx_destroy_window(mlx, mlx_win);
}


void	ft_finish_screen(t_display display)
{
	_my_mlx_destroy_image(display.mlx, display.front_img.addr);
	_my_mlx_destroy_image(display.mlx, display.back_img.addr);
	_my_mlx_destroy_image(display.mlx, display.wall.addr);
	_my_mlx_destroy_image(display.mlx, display.ground.addr);
	_my_mlx_destroy_image(display.mlx, display.collect.addr);
	_my_mlx_destroy_image(display.mlx, display.exit.addr);
	_my_mlx_destroy_image(display.mlx, display.player.addr);
	_my_mlx_destroy_window(display.mlx, display.mlx_win);
}

void	ft_exit(t_all *all)
{
	ft_finish_screen(all->display);
	ft_free_all();
	exit(0);
}