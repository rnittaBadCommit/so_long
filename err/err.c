#include "../so_long.h"

void	ft_write(int fd, char *s, t_all *all)
{
	if (write(fd, s, ft_strlen(s)) == -1)
		ft_exit(all);
}

void	ft_error(t_all *all)
{
	ft_write(2, "Error\n", all);
	if (all->err == BAD_ARG_NUM)
		ft_write(2, "bad arg num\n", all);
	else if (all->err == BAD_FILE_NAME)
		ft_write(2, "file: bad file name\n", all);
	else if (all->err == CANNOT_OPEN_FILE)
		ft_write(2, "file: cannot open\n", all);
	else if (all->err == TOO_LARGE_MAP)
		ft_write(2, "map: too large\n", all);
	else if (all->err == NOT_RECTANGLE)
		ft_write(2, "map: not rectangle\n", all);
	else if (all->err == INVALID_CHAR)
		ft_write(2, "map: contains invalid char\n", all);
	else if (all->err == INVALID_CHAR_NUM)
		ft_write(2, "map: contains invalid components\n", all);
	else if (all->err == NOT_CLOSED_MAP)
		ft_write(2, "map: not closed\n", all);
	else if (all->err == MLX_LIB_ERR)
		ft_write(2, "mlxibX: cant operate\n", all);
	else if (all->err == NO_ERR)
		ft_write(2, "something wrong\n", all);
	ft_exit(all);
}
