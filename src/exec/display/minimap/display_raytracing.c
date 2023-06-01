/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_raytracing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:27:15 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/01 14:06:23 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


static void	get_next_wall(t_exec *exec, int *next_x, int *next_y)
{
	while (exec->data.map[*next_y][*next_x] != '1' )
	{
		*next_y -= 1;
	}
}

static void	set_line(t_exec *exec, int next_x, int next_y)
{
	float	xincr;
	float	yincr;
	float	dx;
	float	dy;
	int		i;
	int		step;

	i = 0;
	dx = next_x - exec->actual_x;
	dy = next_y - exec->actual_y;
	if (fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	xincr = dx / step;
	yincr = dy / step;
	float temp_x = exec->actual_x * SQUARE_SIZE + SQUARE_SIZE / 2;
	float temp_y = exec->actual_y * SQUARE_SIZE + SQUARE_SIZE / 2;
	while (i < step * SQUARE_SIZE - SQUARE_SIZE / 2)
	{
		my_mlx_pixel_put(exec, (int)temp_x, (int)temp_y, 0xFF0000);
		temp_x = temp_x + xincr;
		temp_y = temp_y + yincr;
		i++;
	}
}

void	display_raytracing(t_exec *exec)
{
	int	next_x;
	int	next_y;

	exec->actual_x /= SQUARE_SIZE;
	exec->actual_y /= SQUARE_SIZE;
	next_x = exec->actual_x;
	next_y = exec->actual_y;
	get_next_wall(exec, &next_x, &next_y);
	set_line(exec, next_x, next_y);
}
