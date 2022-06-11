/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:18:36 by marvin            #+#    #+#             */
/*   Updated: 2022/06/11 14:33:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	finalize(t_all *all)
{
	ft_exit(all);
}

static void	_ini_all(t_all *all)
{
	ft_bzero(all, sizeof(t_all));
	all->err = NO_ERR;
}

int	main(int argc, char **argv)
{
	t_all	all;
// mtrace();
	_ini_all(&all);
	if (!is_valid_args(argc, argv, &all.err))
		ft_error(&all);
	all.map = make_map(argv[1], &all.err);
	if (all.map.map == NULL)
		ft_error(&all);
	if (!is_valid_map(all.map.map, &all.err))
		ft_error(&all);
	screen_main(&all);
}
