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


