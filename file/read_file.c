#include "../so_long.h"

static void _copy(char **dest, char **src, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
}

char **read_file(int fd, e_err *err)
{
	char **ret;
	char **tmp;
	int len;
	int size;

	size = 100;
	len = 0;
	ret = (char **)ft_malloc(size + 1);
	while (get_next_line(fd, ret + len) > 0)
	{
		len++;
		if (len + 1 == size)
		{
			if (size > MAP_SIZE_MAX)
			{
				*err = TOO_LARGE_MAP;
				return (NULL);
			}
			size *= 2;
			tmp = (char **)ft_malloc(size + 1);
			_copy(tmp, ret, len);
			ret = tmp;
		}
	}
	ret[len] = NULL;
	return (ret);
}

