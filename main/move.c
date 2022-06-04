#include "../so_long.h"

int move(e_dir dir, t_me *me, char **map)
{
	if (dir == LEFT && map[me->y][me->x - 1] != '1')
	{
		me->x--;
		return (dir);
	}
	else if (dir == RIGHT && map[me->y][me->x + 1] != '1')
	{
		me->x++;
		return (dir);
	}
	else if (dir == UP && map[me->y - 1][me->x] != '1')
	{
		me->y--;
		return (dir);
	}
	else if (dir == DOWN && map[me->y + 1][me->x] != '1')
	{
		me->y++;
		return (dir);
	}
	else
		return (NO_MOVE);
}
