/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:40:09 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/02 09:46:17 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

typedef struct s_line
{
	float	final_x;
	float	final_y;
	int		step;
	float	xincr;
	float	yincr;
}	t_line;

static void	set_up_variable(t_exec *exec, int next_x, int next_y, t_line *line)
{
	float	dx;
	float	dy;

	dx = next_x - exec->actual_x;
	dy = next_y - exec->actual_y;
	if (fabs(dx) > fabs(dy))
		line->step = fabs(dx);
	else
		line->step = fabs(dy);
	line->xincr = dx / line->step;
	line->yincr = dy / line->step;
}

float rotate_line_x(t_exec *exec, t_line origin, float length) 
{
	float	x;

	x = origin.final_x + length * cos(exec->angle);
	return x;
}

float rotate_line_y(t_exec *exec, t_line origin, float length)
{
	float	y;

	y = origin.final_y + length * sin(exec->angle);
	return y;
}

void	draw_line(t_exec *exec, int next_x, int next_y)
{
	int		i;
	t_line	line;
	float		x;
	float		y;

	i = 0;
	set_up_variable(exec, next_x, next_y, &line);
	line.final_x = (exec->actual_x * SQUARE_SIZE + SQUARE_SIZE / 2);
	line.final_y = (exec->actual_y * SQUARE_SIZE + SQUARE_SIZE / 2);
	x = rotate_line_x(exec, line, 30);
	y = rotate_line_y(exec, line, 30);
	set_up_variable(exec, x, y, &line);
	printf("%f\n", exec->angle);
	while (i < line.step * SQUARE_SIZE - SQUARE_SIZE / 2)
	{
		my_mlx_pixel_put(exec, (int)x, (int)y, 0xFF0000);
		line.final_x = x - line.xincr;
		line.final_y = y - line.yincr;
		i++;
	}
}
