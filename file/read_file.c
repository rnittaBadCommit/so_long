/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:18:04 by marvin            #+#    #+#             */
/*   Updated: 2022/06/11 12:18:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// static void _copy(char **dest, char **src, int len)
// {
// 	int i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// }

// char **read_file(int fd, e_err *err)
// {
// 	char **ret;
// 	// char **tmp;
// 	int len;
// 	int size;

// 	size = 1;
// 	len = 0;
// 	ret = (char **)ft_malloc(size + 1);
// 	while (get_next_line(fd, ret + len) > 0)
// 	{
// 		len++;
// 		printf("len: %d, size: %d\n", len, size);
// 		if (len + 2 >= size)
// 		{
// 			if (size > MAP_SIZE_MAX)
// 			{
// 				*err = TOO_LARGE_MAP;
// 				return (NULL);
// 			}
// 			size *= 2;
// 			// tmp = (char **)ft_malloc(size + 1);
// 			// _copy(tmp, ret, len);
// 			// ret = tmp;
// 			ret = (char **)ft_malloc(size + 1);
// 			printf("%p\n", ret);
// 			ret[len] = (char *)ft_malloc(10);
// 		}
// 		printf("end\n");
// 	}
// 	printf("done\n");
// 	ret[len] = NULL;
// 	return (ret);
// }
#include <string.h>

char	**read_file(int fd)
{
	char	*one_line;
	char	*tmp_one_line;
	int		len;
	int		size;
	int		read_ret;

	len = 0;
	size = 10;
	one_line = (char *)malloc(size + 1);
	while (1)
	{
		read_ret = read(fd, one_line + len, 10);
		len += read_ret;
		if (read_ret != 10)
			break ;
		if (len > size - 15)
		{
			size *= 2;
			tmp_one_line = (char *)ft_malloc(size + 1);
			ft_memcpy(tmp_one_line, one_line, len);
			one_line = tmp_one_line;
		}
	}
	one_line[len] = '\0';
	return (ft_split(one_line, '\n'));
}
