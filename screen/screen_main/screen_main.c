/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:19:34 by marvin            #+#    #+#             */
/*   Updated: 2022/06/11 15:03:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	re_paste(t_all *all)
{
	set_screen_from_map(all);
	return (0);
}

void	update_image(t_display *display, t_map map, \
	t_pos previous_pos, t_pos current_pos)
{
	set_block(&display->back_img, display, \
		map.map[previous_pos.y][previous_pos.x], previous_pos);
	set_block(&display->back_img, display, \
		map.map[current_pos.y][current_pos.x], current_pos);
}

int	handle_key(int key, t_all *all)
{
	if (key == KEY_LEFT || key == KEY_RIGHT || \
		key == KEY_UP || key == KEY_DOWN)
	{
		move_main(all, key);
	}
	else if (key == KEY_ESC)
		ft_exit(all);
	return (0);
}

int	ft_exit_hook(t_all *all)
{
	ft_exit(all);
	return (1);
}

void	screen_main(t_all *all)
{
	if (set_display(&all->display, &all->map, &all->err) == FAILED)
		ft_error(all);
	set_me(&all->me, all->map);
	mlx_clear_window(all->display.mlx, all->display.mlx_win);
	set_screen_from_map(all);
	mlx_hook(all->display.mlx_win, KEY_PRESS, MASK_KEY_PRESS, handle_key, all);
	mlx_hook(all->display.mlx_win, SCREEN_DESTROY, \
		MASK_STRUCTURE_NOTIFY, ft_exit_hook, all);
	mlx_hook(all->display.mlx_win, FOCUS_IN, MASK_FOCUS_CHANGE, re_paste, all);
	mlx_loop(all->display.mlx);
}
