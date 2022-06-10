#include "../so_long.h"

static	char	*ft_strncpy(char *dest, char *src, int n)
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

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i] && i < n)
		i++;
	new = (char *)malloc(sizeof(char) * (i + 1));
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

char	**ft_split(char *s, char c)
{
	char	*next;
	char	**ss;
	int		i;

	while (*s == '\n')
		s++;
	i = 0;
	ss = (char **)ft_malloc(sizeof(char *) * count(s, c) + 1);
	if (!ss)
		return (NULL);
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
			break;
		}
	}
	ss[i] = NULL;
	return (ss);
}
