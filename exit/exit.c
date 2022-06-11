/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:17:19 by marvin            #+#    #+#             */
/*   Updated: 2022/06/11 15:02:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	_my_mlx_destroy_image(void *mlx, t_image_addr *addr)
{
	if (mlx && addr)
		mlx_destroy_image(mlx, addr);
}

static void	_my_mlx_destroy_window(void *mlx, void *mlx_win)
{
	if (mlx && mlx_win)
		mlx_destroy_window(mlx, mlx_win);
}

static void	_my_mlx_destroy_display(void *mlx)
{
	if (mlx)
		mlx_destroy_display(mlx);
}

void	ft_finish_screen(t_display display)
{
	_my_mlx_destroy_image(display.mlx, display.front_img.image_addr);
	_my_mlx_destroy_image(display.mlx, display.back_img.image_addr);
	_my_mlx_destroy_image(display.mlx, display.wall.image_addr);
	_my_mlx_destroy_image(display.mlx, display.ground.image_addr);
	_my_mlx_destroy_image(display.mlx, display.collect.image_addr);
	_my_mlx_destroy_image(display.mlx, display.exit.image_addr);
	_my_mlx_destroy_image(display.mlx, display.player.image_addr);
	_my_mlx_destroy_image(display.mlx, display.player_on_exit.image_addr);
	_my_mlx_destroy_window(display.mlx, display.mlx_win);
	_my_mlx_destroy_display(display.mlx);
	free(display.mlx);
}

void	ft_exit(t_all *all)
{
	ft_finish_screen(all->display);
	ft_free_all();
	exit(0);
}
