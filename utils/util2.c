/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:22:39 by marvin            #+#    #+#             */
/*   Updated: 2022/06/11 14:50:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i] && i < n)
		i++;
	new = (char *)ft_malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	return (ft_strncpy(new, (char *)str, i));
}

char	*ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

static int	count(char *s, char c)
{
	int		i;

	i = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			i++;
		s++;
	}
	return (i);
}

void	_set_strs(char *s, char **ss)
{
	char	*next;
	int		i;

	i = 0;
	while (*s)
	{
		next = ft_strchr(s, '\n');
		if (next)
		{
			ss[i++] = ft_strndup(s, next - s);
			s += next - s + 1;
			while (*s == '\n')
				s++;
		}
		else
		{
			ss[i++] = ft_strndup(s, ft_strlen(s));
			break ;
		}
	}
	ss[i] = NULL;
}

char	**ft_split(char *s, char c)
{
	char	**ss;

	while (*s == '\n')
		s++;
	ss = (char **)ft_malloc(sizeof(char *) * (count(s, c) + 1));
	if (!ss)
		return (NULL);
	_set_strs(s, ss);
	return (ss);
}
