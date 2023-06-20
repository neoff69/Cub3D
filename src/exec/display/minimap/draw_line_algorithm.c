/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:40:09 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/20 11:23:39 by vgonnot          ###   ########.fr       */
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

static void	get_delta_dist(t_line *line, t_exec *exec, \
		float *delta_dist_x, float *delta_dist_y)
{
		exec->dx = cos(exec->ray_angle);
		exec->dy = sin(exec->ray_angle);
		*delta_dist_x = fabs(1 / exec->dx);
		*delta_dist_y = fabs(1 / exec->dy);
		line->map_x = (int)line->final_x / SQUARE_SIZE;
		line->map_y = (int)line->final_y / SQUARE_SIZE;
}

void	draw(t_exec *exec, t_line *line)
{
	float	delta_dist_x;
	float	delta_dist_y;
	float	distance;

	exec->num = 0;
	while (exec->num <= WIDTH)
	{
		get_delta_dist(line, exec, &delta_dist_x, &delta_dist_y);
		get_step(line, exec, delta_dist_x, delta_dist_y);
		while (1)
			if (incr_until_wall(line, exec, delta_dist_x, delta_dist_y))
				break ;
		distance = get_distance(line, exec, delta_dist_x, delta_dist_y);
		display_environment(exec, exec->ray_angle, distance);
		exec->ray_angle += RAD * (40.0 / WIDTH);
		exec->num++;
	}
}

void	get_angle(t_exec *exec)
{
	exec->ray_angle = exec->angle - (RAD * 20);
	if (exec->ray_angle < 0)
		exec->ray_angle += 2 * PI;
	else if (exec->ray_angle > 2 * PI)
		exec->ray_angle -= 2 * PI;
}

void	display_game(t_exec *exec)
{
	t_line	line;

	get_angle(exec);
	set_up_variable(exec, exec->actual_x, exec->actual_y, &line);
	line.final_x = (exec->actual_x + SQUARE_SIZE / 2);
	line.final_y = (exec->actual_y + SQUARE_SIZE / 2);
	draw(exec, &line);
}
