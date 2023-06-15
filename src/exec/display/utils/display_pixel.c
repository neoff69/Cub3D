/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:50:31 by jlaisne           #+#    #+#             */
/*   Updated: 2023/06/15 13:59:09 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	my_mlx_pixel_put_rt(t_exec *exec, int x, int y, int color)
{
	char	*dst;
	int		bit;

	bit = exec->mlx.bit / 8;
	dst = exec->mlx.addr + (y * exec->mlx.len + x * (bit));
	if (*(unsigned int *)dst == WALL_MINIMAP)
		return (1);
	if (check_if_corner(exec, bit, x, y))
	{
		*(unsigned int *)dst = color;
		return (1);
	}
	*(unsigned int *)dst = color;
	return (0);
}

int	my_mlx_pixel_put(t_exec *exec, int x, int y, int color)
{
	char	*dst;
	int		bit;

	bit = exec->mlx.bit / 8;
	dst = exec->mlx.addr + (y * exec->mlx.len + x * (bit));
	*(unsigned int *)dst = color;
	return (0);
}

int	pixel_check(t_exec *exec, int x, int y)
{
	char	*dst;
	int		bit;

	bit = exec->mlx.bit / 8;
	dst = exec->mlx.addr + (y * exec->mlx.len + x * (bit));
	if (*(unsigned int *)dst == WALL_MINIMAP)
		return (1);
	return (0);
}

char	*pixel_return(t_img *data, int x, int y)
{
	char	*dst;
	int		bit;

	bit = data->bit / 8;
	dst = data->addr + (y * data->len + x * (bit));
	return (dst);
}

int	my_mlx_put_offset(t_exec *exec, int x, int y, int color)
{
	char	*dst;
	int		bit;

	bit = exec->mlx.bit / 8;
	dst = exec->mlx.addr + (y * exec->mlx.len + x * (bit));
	if (*(unsigned int *)dst == WALL_MINIMAP \
		|| *(unsigned int *)dst == FLOOR_MINIMAP \
		|| *(unsigned int *)dst == PLAYER_MINIMAP \
		|| *(unsigned int *)dst == RAY_MINIMAP)
		return (0);
	else if (*(unsigned int *)dst != 0x000000)
		return (1);
	*(unsigned int *)dst = color;
	return (0);
}
