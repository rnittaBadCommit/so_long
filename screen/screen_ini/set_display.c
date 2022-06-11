/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:19:06 by marvin            #+#    #+#             */
/*   Updated: 2022/06/11 15:20:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	_set_resolution(t_resolution *resolution, t_map *map)
{
	resolution->y = map->height * BLOCK_SIZE;
	resolution->x = map->width * BLOCK_SIZE;
}

static void	_set_mlx_mlxwin(t_display *display)
{
	display->mlx = mlx_init();
	display->mlx_win = mlx_new_window(display->mlx, display->resolution.x, \
		display->resolution.y, display->name);
}

int	set_images(t_display *display, t_err *err)
{
	if (load_texture(display, err) == FAILED)
	{
		return (FAILED);
	}
	return (SUCCESS);
}

int	set_display(t_display *display, t_map *map, t_err *err)
{
	display->name = DISPLAY_NAME;
	_set_resolution(&display->resolution, map);
	_set_mlx_mlxwin(display);
	return (set_images(display, err));
}
