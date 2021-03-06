/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:20:11 by marvin            #+#    #+#             */
/*   Updated: 2022/06/11 12:20:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	zero_reset(void *a, void *b, void *c, void *d)
{
	if (a != NULL)
		*(int *)a = 0;
	if (b != NULL)
		*(int *)b = 0;
	if (c != NULL)
		*(int *)c = 0;
	if (d != NULL)
		*(int *)d = 0;
}

int	ft_strlen(char *s)
{
	int	ret;

	ret = 0;
	while (s[ret])
		ret++;
	return (ret);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_bzero(void *p, int n)
{
	char	*s;
	int		i;

	s = (char *)p;
	i = 0;
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
}

void	ft_memcpy(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
}
