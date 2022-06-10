#include "../../so_long.h"

static void	_destroy_all_images(t_display display)
{
	mlx_destroy_image(display.mlx, display.front_img.image_addr);
	mlx_destroy_image(display.mlx, display.back_img.image_addr);
}

void	finish_screen(t_display display)
{
	_destroy_all_images(display);
	mlx_destroy_window(display.mlx, display.mlx_win);
}