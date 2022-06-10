#include "../so_long.h"

static char	**_make_map_map(char *file_name, e_err *err)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		*err = CANNOT_OPEN_FILE;
		return (NULL);
	}
	return (read_file(fd));
}

static int	_map_width(t_map map)
{
	int	i;

	i = 0;
	if (map.map[0])
		while (map.map[0][i])
			i++;
	return (i);
}

static int	_map_height(t_map map)
{
	int	i;

	i = 0;
	while (map.map[i])
		i++;
	return (i);
}

int	_count_num_collect(t_map map)
{
	int	_y;
	int	_x;
	int	ret;

	_y = 0;
	ret = 0;
	while (_y < map.height)
	{
		_x = 0;
		while (_x < map.width)
		{
			if (map.map[_y][_x] == 'C')
				ret++;
			_x++;
		}
		_y++;
	}
	return (ret);
}

t_map	make_map(char *file_name, e_err *err)
{
	t_map	map;

	map.map = _make_map_map(file_name, err);
	if (map.map == NULL)
		return (map);
	map.width = _map_width(map);
	map.height = _map_height(map);
	map.num_collect = _count_num_collect(map);
	return (map);
}
