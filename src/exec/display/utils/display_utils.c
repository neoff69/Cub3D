/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:38:13 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/20 11:15:11 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	my_mlx_pixel_put_wall(t_exec *exec, int x, int y, int color)
{
	char	*dst;
	int		bit;

	bit = exec->mlx.bit / 8;
	dst = exec->mlx.addr + (y * exec->mlx.len + x * (bit));
	if (*(unsigned int *)dst != 0x000000)
		return (0);
	*(unsigned int *)dst = color;
	return (0);
}

void	set_image_win(t_exec *exec)
{
	if (exec->mlx.img)
		mlx_destroy_image(exec->mlx.mlx, exec->mlx.img);
	exec->mlx.img = mlx_new_image(exec->mlx.mlx, 1920, 1080);
	if (exec->mlx.img == NULL)
		exit(0);
	exec->mlx.addr = mlx_get_data_addr(\
		exec->mlx.img, &exec->mlx.bit, &exec->mlx.len, &exec->mlx.endian);
	if (exec->mlx.addr == NULL)
		exit(0);
	display_minimap(exec);
	mlx_clear_window(exec->mlx.mlx, exec->mlx.mlx_win);
	mlx_put_image_to_window(\
		exec->mlx.mlx, exec->mlx.mlx_win, exec->mlx.img, 0, 0);
}
