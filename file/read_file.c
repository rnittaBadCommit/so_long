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

char **read_file(int fd, t_all *all)
{
	char **ret;
	char **tmp;
	int len;
	int size;
	int is_eof;

	size = 10;
	len = 0;
	ret = (char **)malloc(size + 1);
	while (get_next_line(fd, ret + len++) > 0)
	{
		if (len == size)
		{
			if (size > MAX_MAP_SIZE)
			{
				all->err = TOO_LARGE_MAP;
				return (NULL);
			}
			size *= 2;
			new = (char **)malloc(size + 1);
			_copy(new, ret, len);
		}
	}
	ret[len] = NULL;
	return (ret);
}
