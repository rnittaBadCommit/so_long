#include "../so_long.h"

static char **_make_map_map(char *file_name, e_err *err)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		*err = CANNOT_OPEN_FILE;
		return (NULL);
	}
	return (read_file(fd, err));
}

static int _map_width(t_map map)
{
	int i;

	i = 0;
	while (map.map[0][i])
		i++;
	return (i);
}

static int _map_height(t_map map)
{
	int i;

	i = 0;
	while (map.map[i])
		i++;
	return (i);
}

t_map make_map(char *file_name, e_err *err)
{
	t_map map;

	map.map = _make_map_map(file_name, err);
	if (map.map == NULL)
		return (map);
	map.width = _map_width(map);
	map.height = _map_height(map);
	return (map);
}

