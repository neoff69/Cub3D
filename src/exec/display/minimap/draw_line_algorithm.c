/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:40:09 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/02 12:26:37 by vgonnot          ###   ########.fr       */
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

float	rotate_line_x(t_exec *exec, t_line *origin, float length)
{
	float	x;

	x = origin->final_x + length * cos(exec->angle);
	return (x);
}

float	rotate_line_y(t_exec *exec, t_line *origin, float length)
{
	float	y;

	y = origin->final_y + length * sin(exec->angle);
	return (y);
}

void	draw_line(t_exec *exec)
{
	int		i;
	t_line	line;
	float	x;
	float	y;

	(void)exec;
	i = 0;
	set_up_variable(exec, exec->actual_x, exec->actual_y - 10, &line);
	line.final_x = (exec->actual_x * SQUARE_SIZE + SQUARE_SIZE / 2);
	line.final_y = (exec->actual_y * SQUARE_SIZE + SQUARE_SIZE / 2);
	//printf("x = %f y = %f fnal_x = %f final_y = %f steps = %d xincr = %f yincr =%f\n", x, y, line.final_x, line.final_y, line.step, line.xincr, line.yincr);
	while (i < line.step * SQUARE_SIZE)
	{
		x = rotate_line_x(exec, &line, i);
		y = rotate_line_y(exec, &line, i);
		if (x >= 1920 || x <= 0 || y >= 1080 || y <= 0)
			break ;
		my_mlx_pixel_put(exec, (int)x, (int)y, 0xFF0000);
		//printf("x = %f y= %f i = %d angle = %f\n", x, y, i, sin(exec->angle));
		line.final_x += line.xincr;
		line.final_y +=  line.yincr;
		i++;
	}
}
