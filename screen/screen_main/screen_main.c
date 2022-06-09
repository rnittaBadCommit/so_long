#include "../../so_long.h"

int	re_paste(t_all *all)
{
	printf("repaste start\n");
	set_screen_from_map(all);
	return (0);
}



void    update_image(t_display *display, t_map map, t_pos previous_pos, t_pos current_pos)
{
    set_block(&display->back_img, display, map.map[previous_pos.y][previous_pos.x], previous_pos);
    set_block(&display->back_img, display, map.map[current_pos.y][current_pos.x], current_pos);
}

int	handle_key(int key, t_all *all)
{
	//printf("handle_key start, key: %d\n", key);
	if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP || key == KEY_DOWN)
	{
		move_main(all, key);
	}
	else if (key == KEY_ESC)
		ft_exit(all);
	//printf("\n");
	return (0);
}

int	ft_exit_hook(int key, t_all *all)
{
	printf("here\n");
	if (key == 1 || all)
		ft_free_all();
	exit(1);
	return (1);
}

void	set_me(t_me *me, t_map map)
{
	int	_y;
	int	_x;

	_y = 0;
	while (_y < map.height)
	{
		_x = 0;
		while (_x < map.width)
		{
			if (map.map[_y][_x] == 'P')
			{
				me->current_pos.y = _y;
				me->current_pos.x = _x;
				map.map[_y][_x] = '0';
			}
			_x++;
		}
		_y++;
	}
}

void	screen_main(t_all all)
{
	//printf("\n==============\n\nscreen_main\n\n\n");
	if (set_display(&all.display, &all.map, &all.err) == FAILED)
		ft_error(&all);
	set_me(&all.me, all.map);
	//printf("set_display done\n");
	mlx_clear_window(all.display.mlx, all.display.mlx_win);
	set_screen_from_map(&all);
	mlx_hook(all.display.mlx_win, KEY_PRESS, MASK_KEY_PRESS, handle_key, &all);
	mlx_hook(all.display.mlx_win, SCREEN_DESTROY, MASK_STRUCTURE_NOTIFY, ft_exit_hook, &all);
	mlx_hook(all.display.mlx_win, FOCUS_IN, MASK_FOCUS_CHANGE, re_paste, &all);
	//printf("mlx_loop start\n");
	mlx_loop(all.display.mlx);
}