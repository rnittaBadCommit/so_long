#include "../so_long.h"

int		re_paste_hook(t_display	display)
{
	mlx_put_image_to_window(display.mlx, display.mlx_win,
		display.front_img.img, 0, 0);
	return (0);
}

void	screen_main(t_all all, t_display display)
{
	mlx_clear_window(display.mlx, display.mlx_win);
	make_screen(&all);
	mlx_put_image_to_window(display.mlx, display.mlx_win, display.front_img.img, 0, 0);
	mlx_hook(display.mlx_win, 2, 1L << 0, handle_key, &all);
	mlx_hook(display.mlx_win, 17, 1L << 17, ft_exit, &all);
	mlx_hook(display.mlx_win, 9, 1L << 21, re_paste_hook, &all);
	mlx_loop(display.mlx);
}