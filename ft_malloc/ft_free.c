/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:23:00 by rnitta            #+#    #+#             */
/*   Updated: 2022/04/21 15:24:28 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_list	*save_list();

static void	_ft_free_process(t_list *list)
{
	if (list->next)
	{
		_ft_free_process(list->next);
		free(list->next);
	}
	free(list->p);
}

void	ft_free_all(void)
{
	t_list	*list;

	list = save_list();
	if (list->next)
		_ft_free_process(list->next);
	free(list->next);
	list->next = NULL;
	list->p = NULL;
}
