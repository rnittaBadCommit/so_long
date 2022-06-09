#include "../so_long.h"

static void	_my_mlx_destroy_image(void *mlx, image_addr *addr)
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
	_my_mlx_destroy_image(display.mlx, display.front_img.image_addr);
	_my_mlx_destroy_image(display.mlx, display.back_img.image_addr);
	_my_mlx_destroy_image(display.mlx, display.wall.image_addr);
	_my_mlx_destroy_image(display.mlx, display.ground.image_addr);
	_my_mlx_destroy_image(display.mlx, display.collect.image_addr);
	_my_mlx_destroy_image(display.mlx, display.exit.image_addr);
	_my_mlx_destroy_image(display.mlx, display.player.image_addr);
	_my_mlx_destroy_window(display.mlx, display.mlx_win);
}

void	ft_exit(t_all *all)
{
	ft_finish_screen(all->display);
	printf("\n\nft_free_all start\n");
	ft_free_all();
	exit(0);
}