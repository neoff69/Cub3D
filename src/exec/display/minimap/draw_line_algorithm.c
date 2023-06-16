/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:40:09 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/16 15:04:31 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	set_up_variable(t_exec *exec, int next_x, int next_y, t_line *line)
{
	line->old_x = 0;
	line->old_y = 0;
	line->dx = next_x - exec->actual_x;
	line->dy = next_y - exec->actual_y;
	if (fabs(line->dx) > fabs(line->dy))
		line->step = fabs(line->dx);
	else
		line->step = fabs(line->dy);
	line->xincr = line->dx / (line->step);
	line->yincr = line->dy / (line->step);
}

static void	rotate_line(t_line *line, float length, float dx, float dy)
{
	line->x = line->final_x + (length / CUB) * dx;
	line->y = line->final_y + (length / CUB) * dy;
}

void	draw(t_exec *exec, t_line *line, float ang)
{
	int		pixel;

	exec->num = 0;
	while (exec->num <= WIDTH)
	{
		pixel = 0;
		exec->dx = cos(exec->ray_angle);
		exec->dy = sin(exec->ray_angle);
		while (1)
		{
			
			rotate_line(line, pixel, exec->dx, exec->dy);
			if (my_mlx_pixel_put_rt(exec, \
				(int)line->x, (int)line->y, RAY_MINIMAP))
				break ;
			line->old_x = line->x;
			line->old_y = line->y;
			pixel++;
		}
		display_environment(line, exec, ang);
		exec->ray_angle += RAD * (40.0 / WIDTH);
		exec->num ++;
	}
}

float	get_angle(t_exec *exec)
{
	exec->ray_angle = exec->angle - RAD * 20;
	if (exec->ray_angle < 0)
		exec->ray_angle += 2 * PI;
	else if (exec->ray_angle > 2 * PI)
		exec->ray_angle -= 2 * PI;
	return (exec->ray_angle);
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
