#include "../so_long.h"

int move(e_dir dir, t_me *me, char **map)
{
	me->previous_pos = me->current_pos;
	if (dir == LEFT && map[me->current_pos.y][me->current_pos.x - 1] != '1')
	{
		me->current_pos.x--;
		return (dir);
	}
	else if (dir == RIGHT && map[me->current_pos.y][me->current_pos.x + 1] \
		!= '1')
	{
		me->current_pos.x++;
		return (dir);
	}
	else if (dir == UP && map[me->current_pos.y - 1][me->current_pos.x] != '1')
	{
		me->current_pos.y--;
		return (dir);
	}
	else if (dir == DOWN && map[me->current_pos.y + 1][me->current_pos.x] \
		!= '1')
	{
		me->current_pos.y++;
		return (dir);
	}
	else
		return (NO_MOVE);
}

static void _update_map(t_map *map, t_pos pos)
{
	if (map->map[pos.y][pos.x] == 'C')
	{
		map->map[pos.y][pos.x] = '0';
		map->num_collect--;
	}
}

static int	_is_finish(t_map map, t_me me)
{
	if (map.num_collect == 0 && map.map[me.current_pos.y][me.current_pos.x] == 'E')
		return (1);
	else
		return (0);
}

void move_main(t_all *all, int dir)
{
	dir = move(dir, &all->me, all->map.map);
	if (dir != NO_MOVE)
	{
		_update_map(&all->map, all->me.current_pos);
		update_screen(&all->display, &all->map, all->me.previous_pos, all->me.current_pos);
		if (_is_finish(all->map, all->me))
			finalize(all);
	}
}
