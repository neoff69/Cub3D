/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:40:09 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/13 14:14:21 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	set_up_variable(t_exec *exec, int next_x, int next_y, t_line *line)
{
	line->dx = next_x - exec->actual_x;
	line->dy = next_y - exec->actual_y;
	if (fabs(line->dx) > fabs(line->dy))
		line->step = fabs(line->dx);
	else
		line->step = fabs(line->dy);
	line->xincr = line->dx / (line->step);
	line->yincr = line->dy / (line->step);
}

static float	rotate_line_x(t_line *line, float length, float ang)
{
	float	x;

	x = line->final_x + (length / CUB) * cos(ang);
	return (x);
}

static float	rotate_line_y(t_line *line, float length, float ang)
{
	float	y;

	y = line->final_y + (length / CUB) * sin(ang);
	return (y);
}


void	draw(t_exec *exec, t_line *line, float ang)
{
	int		i;
	int		num;

	num = 0;
	while (num <= WIDTH)
	{
		i = 0;
		while (1)
		{
			line->x = rotate_line_x(line, i, ang);
			line->y = rotate_line_y(line, i, ang);
			if (my_mlx_pixel_put_rt(exec, 
				(int)line->x, (int)line->y, RAY_MINIMAP))
				break ;
			i++;
		}
		display_environment(line, exec, ang, num);
		ang += RAD * (40.0 / WIDTH);
		num ++;
	}
}

float	get_angle(t_exec *exec)
{
	float	ang;

	ang = exec->angle - RAD * 20;
	if (ang < 0)
		ang += 2 * PI;
	else if (ang > 2 * PI)
		ang -= 2 * PI;
	return (ang);
}

void	display_game(t_exec *exec)
{
	t_line	line;
	float	ang;

	ang = get_angle(exec);
	set_up_variable(exec, exec->actual_x, exec->actual_y, &line);
	line.final_x = (exec->actual_x + SQUARE_SIZE / 2);
	line.final_y = (exec->actual_y + SQUARE_SIZE / 2);
	draw(exec, &line, ang);
}
