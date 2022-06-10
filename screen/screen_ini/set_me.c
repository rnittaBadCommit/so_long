#include "../so_long.h"

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
