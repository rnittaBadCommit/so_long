/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:21:02 by marvin            #+#    #+#             */
/*   Updated: 2022/06/12 04:26:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putchar(char c)
{
	if (write(1, &c, 1))
		return ;
}

void	ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr((n / 10));
		ft_putchar((n % 10 + '0'));
	}
	else
		ft_putchar((n + '0'));
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	char		*tmp;
	int			i;

	tmp = dest;
	i = 0;
	while (*src != '\0' && i++ < n)
		*dest++ = *src++;
	*dest = '\0';
	return (tmp);
}

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;
	size_t		i;

	ptr = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			ptr = &s[i];
		i++;
	}
	return ((char *)ptr);
}
