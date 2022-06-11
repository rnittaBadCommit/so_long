/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:18:31 by marvin            #+#    #+#             */
/*   Updated: 2022/06/12 04:35:25 by marvin           ###   ########.fr       */
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
	char	*dot_addr;

	dot_addr = ft_strrchr(file_name, '.');
	if (dot_addr && dot_addr != file_name)
		if (!ft_strcmp(dot_addr, ".ber"))
			return (1);
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
