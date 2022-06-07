#include "../so_long.h"

int     ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

void    ft_write(int fd, char *s, t_all all)
{
    if (write(fd, s, ft_strlen(s)) == -1)
        ft_exit(&all);
}

void    ft_error(t_all all)
{
    ft_write(2, "Error\n", all);
    if (all.err == BAD_ARG_NUM)
        ft_write(2, "bad arg num\n", all);
}