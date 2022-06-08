#include "../../so_long.h"

int	re_paste(t_display	display)
{
	mlx_put_image_to_window(display.mlx, display.mlx_win,
		display.front_img.img, 0, 0);
	return (0);
}

void    update_image(t_display *display, t_map map, t_pos previous_pos, t_pos current_pos)
{
    set_block(&display->back_img, display, map.map[previous_pos.y][previous_pos.x], previous_pos);
    set_block(&display->back_img, display, map.map[current_pos.y][current_pos.x], current_pos);
}

int	handle_key(int key, t_all *all)
{
	if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP || key == KEY_DOWN)
		move_main(all, key);
	else if (key == KEY_ESC)
		ft_exit(all);
	return (0);
}

int	ft_exit_hook(int key, t_all *all)
{
	if (key == 1 || 1)
		ft_exit(all);
	return (1);
}

void	screen_main(t_all all)
{
	if (set_display(&all.display, &all.map, &all.err) == FAILED)
		ft_error(&all);
	mlx_clear_window(all.display.mlx, all.display.mlx_win);
	mlx_put_image_to_window(all.display.mlx, all.display.mlx_win, all.display.front_img.img, 0, 0);
	mlx_hook(all.display.mlx_win, KEY_PRESS, MASK_KEY_PRESS, handle_key, &all);
	mlx_hook(all.display.mlx_win, SCREEN_DESTROY, MASK_STRUCTURE_NOTIFY, ft_exit_hook, &all);
	mlx_hook(all.display.mlx_win, FOCUS_IN, MASK_FOCUS_CHANGE, re_paste, &all);
	mlx_loop(all.display.mlx);
}