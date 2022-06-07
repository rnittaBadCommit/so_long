#include "../so_long.h"

void	ft_finish_screen(t_display display)
{
	mlx_destroy_image(display.mlx, display.front_img.addr);
	mlx_destroy_image(display.mlx, display.back_img.addr);
	mlx_destroy_image(display.mlx, display.wall.addr);
	mlx_destroy_image(display.mlx, display.ground.addr);
	mlx_destroy_image(display.mlx, display.collect.addr);
	mlx_destroy_image(display.mlx, display.exit.addr);
	mlx_destroy_image(display.mlx, display.player.addr);
}

void	ft_exit(t_all *all)
{
	ft_finish_screen(all->display);
	ft_free_all();
}