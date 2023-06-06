/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:27:57 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/06 10:20:08 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_square(int x, int y, int color, t_exec *exec)
{
	int	i;
	int	j;

	i = 0;
	while (i < SQUARE_SIZE)
	{
		j = 0;
		while (j < SQUARE_SIZE)
		{
			my_mlx_pixel_put(exec, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	init_display_minimap(t_exec *exec)
{
	int	y;
	int	x;

	y = 0;
	while (exec->data.map[y])
	{
		x = 0;
		while (exec->data.map[y][x])
		{
			if (exec->data.map[y][x] == '1')
				draw_square(x * SQUARE_SIZE, y * SQUARE_SIZE, 0x808080, exec);
			else if (exec->data.map[y][x] != ' ' && exec->data.map[y][x] != '\n')
				draw_square(x * SQUARE_SIZE, y * SQUARE_SIZE, 0xFFFFFF, exec);
			x++;
		}
		y++;
	}
}

void	display_minimap(t_exec *exec)
{
	init_display_minimap(exec);
	display_minimap_character(exec);
	display_raytracing(exec);
}
