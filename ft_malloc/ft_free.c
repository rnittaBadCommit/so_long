/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:23:00 by rnitta            #+#    #+#             */
/*   Updated: 2022/06/10 05:17:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_list	*save_list();

static void	_ft_free_all_process(t_list *list)
{
	printf("%p\n", list->next);
	if (list->next)
	{
		printf("a\n");
		_ft_free_all_process(list->next);
		
		printf("b\n");
		free(list->next);
		
		printf("c\n");
	}
	free(list->p);
	
		printf("d\n");
}

void	ft_free_all(void)
{
	t_list	*list;
printf("\n\nft_free_all\n\n");
	list = save_list();
	if (list->next)
		_ft_free_all_process(list->next);
	free(list->next);
	list->next = NULL;
	list->p = NULL;
}

static int	_ft_free_process(t_list *list, void *p)
{
	if (list->p == p)
	{
		free(p);
		list->p = NULL;
		return (0);
	}
	else if (list->next)
		return (_ft_free_process(list->next, p));
	else
		return (-1);
}

int	ft_free(void *p)
{
	t_list *list;

	list = save_list();
	if (list->next)
		return (_ft_free_process(list->next, p));
	else
		return (-1);
}
