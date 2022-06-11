/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:18:31 by marvin            #+#    #+#             */
/*   Updated: 2022/06/11 15:20:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	_is_valid_arg_num(int argc)
{
	return (argc == 2);
}

//".ber" is invalid
static int	_is_valid_file_name(char *file_name)
{
	while (*file_name)
	{
		file_name++;
		if (*file_name == '.')
		{
			if (!ft_strcmp(file_name, ".ber"))
				return (1);
		}
	}
	return (0);
}

int	is_valid_args(int argc, char **argv, t_err *err)
{
	if (!_is_valid_arg_num(argc))
		*err = BAD_ARG_NUM;
	else if (!_is_valid_file_name(argv[1]))
		*err = BAD_FILE_NAME;
	return (*err == NO_ERR);
}
