#include "../so_long.h"

int	re_paste(t_display	display)
{
	mlx_put_image_to_window(display.mlx, display.mlx_win,
		display.front_img.img, 0, 0);
	return (0);
}

int	handle_key(int key, t_all *all)
{
	if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP || key == KEY_DOWN)
		move_main(all, key);
	else if (key == KEY_ESC)
		ft_exit(all);
	return (0);
}

void	screen_main(t_all all, t_display display)
{
	all.display.mlx = mlx_init();
	all.display.mlx_win = mlx_new_window(all.display.mlx, all.display.resolution.x, all.display.resolution.y, all.display.name);
	mlx_clear_window(display.mlx, display.mlx_win);
	set_image(all.map, all.display);
	mlx_put_image_to_window(display.mlx, display.mlx_win, display.front_img.img, 0, 0);
	mlx_hook(display.mlx_win, KEY_PRESS, MASK_KEY_PRESS, handle_key, &all);
	mlx_hook(display.mlx_win, SCREEN_DESTROY, MASK_STRUCTURE_NOTIFY, ft_exit, &all);
	mlx_hook(display.mlx_win, FOCUS_IN, MASK_FOCUS_CHANGE, re_paste, &all);
	mlx_loop(display.mlx);
}