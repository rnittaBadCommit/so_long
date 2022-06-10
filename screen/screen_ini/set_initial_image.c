#include "../so_long.h"

image_addr	*_correspond_image_addr(t_display *display, \
	t_map *map, t_pos pos, t_pos player_pos)
{
	if (map->map[pos.y][pos.x] == 'E' && \
		(pos.y != player_pos.y || pos.x != player_pos.x))
		return (display->exit.image_addr);
	else if (map->map[pos.y][pos.x] == 'E' && \
		(pos.y == player_pos.y && pos.x == player_pos.x))
		return (display->player_on_exit.image_addr);
	else if (map->map[pos.y][pos.x] == 'P' || \
		(pos.y == player_pos.y && pos.x == player_pos.x))
		return (display->player.image_addr);
	else if (map->map[pos.y][pos.x] == '0')
		return (display->ground.image_addr);
	else if (map->map[pos.y][pos.x] == '1')
		return (display->wall.image_addr);
	else if (map->map[pos.y][pos.x] == 'C')
		return (display->collect.image_addr);
	else
		return (NULL);
}

void	set_screen_from_map(t_all *all)
{
	t_pos		pos;
	image_addr	*image_addr;

	pos.y = 0;
	while (pos.y < all->map.height)
	{
		pos.x = 0;
		while (pos.x < all->map.width)
		{
			image_addr = _correspond_image_addr(&all->display, \
				&all->map, pos, all->me.current_pos);
			mlx_put_image_to_window(all->display.mlx, all->display.mlx_win, \
				image_addr, pos.x * BLOCK_SIZE, pos.y * BLOCK_SIZE);
			pos.x++;
		}
		pos.y++;
	}
}

void	update_screen(t_display *display, t_map *map, \
	t_pos previous_pos, t_pos current_pos)
{
	image_addr *image_addr;

	image_addr = _correspond_image_addr(display, map, \
		previous_pos, current_pos);
	mlx_put_image_to_window(display->mlx, display->mlx_win, \
		image_addr, previous_pos.x * BLOCK_SIZE, previous_pos.y * BLOCK_SIZE);
	if (map->map[current_pos.y][current_pos.x] == 'E')
		image_addr = display->player_on_exit.image_addr;
	else
		image_addr = display->player.image_addr;
	mlx_put_image_to_window(display->mlx, display->mlx_win, image_addr, \
		current_pos.x * BLOCK_SIZE, current_pos.y * BLOCK_SIZE);
}
