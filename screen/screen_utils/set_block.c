/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_block.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:19:46 by marvin            #+#    #+#             */
/*   Updated: 2022/06/11 12:19:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	_set_block_process(t_image *img, t_image *texture, t_pos pos)
{
	void			*dest;
	unsigned int	color;
	int				_y;
	int				_x;

	_y = 0;
	while (_y < BLOCK_SIZE)
	{
		_x = 0;
		while (_x < BLOCK_SIZE)
		{
			color = get_color(texture, _y, _x);
			if (color != rgb2int(255, 255, 255))
			{
				dest = get_addr_of_pixel(img, \
					pos.y * BLOCK_SIZE + _y, pos.x * BLOCK_SIZE + _x);
				*(unsigned int *)dest = color;
			}
			_x++;
		}
		_y++;
	}
}

void	set_block(t_image *img, t_display *display, char map_value, t_pos pos)
{
	if (map_value == '0')
		_set_block_process(img, &display->ground, pos);
	else if (map_value == '1')
		_set_block_process(img, &display->wall, pos);
	else
	{
		_set_block_process(img, &display->ground, pos);
		if (map_value == 'C')
			_set_block_process(img, &display->collect, pos);
		else if (map_value == 'E')
			_set_block_process(img, &display->exit, pos);
		else if (map_value == 'P')
			_set_block_process(img, &display->player, pos);
	}
}
