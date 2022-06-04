#include "../so_long.h"

static int _is_rectangle(char **map)
{
	int len;
	int i;

	if (map[0] == NULL)
		return (0);
	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
		if (ft_strlen(map[i]) != len)
			return (0);
	return (1);
}

static int _is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

static int _is_only_valid_char(char **map)
{
	int y;
	int x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!_is_valid_char(map[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int _is_valid_char_num(char **map)
{
	int is_e_exist;
	int is_c_exist;
	int is_p_exist;
	int x;
	int y;

	zero_reset(&is_e_exist, &is_c_exist, &is_p_exist, &y);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				is_e_exist = 1;
			else if (map[y][x] == 'C')
				is_c_exist = 1;
			else if (map[y][x] == 'P')
			{
				if (is_p_exist)
					return (0);
				else
					is_p_exist = 1;
			}
			x++;
		}
		y++;
	}
	return (is_e_exist * is_c_exist * is_p_exist);
}

static int _is_closed(char **map)
{
	int x;
	int y;
	int width;

	x = 0;
	while (map[0][x])
		if (map[0][x] != '1')
			return (0);
	width = x - 1;
	y = 0;
	while (map[y])
	{
		if (map[y][0] != '1' || map[y][width] != '1')
			return (0);
	}
	x = 1;
	y--;
	while (x < width)
		if (map[y][x] != '1')
			return (0);
	return (1);
}

int is_valid_map(char **map, e_err *err)
{
	if (!_is_rectangle(map))
		*err = NOT_RECTANGLE;
	if (!_is_only_valid_char(map))
		*err = INVALID_CHAR;
	if (!_is_valid_char_num(map))
		*err = INVALID_CHAR_NUM;
	if (!_is_closed(map))
		*err = NOT_CLOSED_MAP;
	return (*err != NO_ERR);
}
