/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:40:09 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/19 13:37:20 by jlaisne          ###   ########.fr       */
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

void draw(t_exec *exec, t_line *line)
{
	int pixel;
	float delta_dist_x;
	float delta_dist_y;
	int step_x;
	int step_y;
	int map_x;
	int map_y;

	exec->num = 0;
	while (exec->num <= WIDTH)
	{
		pixel = 0;
		exec->dx = cos(exec->ray_angle);
		exec->dy = sin(exec->ray_angle);
		delta_dist_x = fabs(1 / exec->dx);
		delta_dist_y = fabs(1 / exec->dy);
		map_x = (int)line->final_x / 6.0;
		map_y = (int)line->final_y / 6.0;
		if (exec->dx < 0)
		{
			step_x = -1;
			exec->side_dist_x = ((line->final_x / 6.0) - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			exec->side_dist_x = (map_x + 1.0 - (line->final_x / 6.0)) * delta_dist_x;
		}
		if (exec->dy < 0)
		{
			step_y = -1;
			exec->side_dist_y = ((line->final_y / 6.0) - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			exec->side_dist_y = (map_y + 1.0 - (line->final_y / 6.0)) * delta_dist_y;
		}
		while (1)
		{
			if (exec->side_dist_x < exec->side_dist_y)
			{
				exec->side_dist_x += delta_dist_x;
				map_x += step_x;
				exec->side = 0;
			}
			else
			{
				exec->side_dist_y += delta_dist_y;
				map_y += step_y;
				exec->side = 1;
			}
			if (exec->data.map[map_y][map_x] == '1')
			{
				line->x = map_x;
				line->y = map_y;
				break ;
			}
			my_mlx_pixel_put(exec, map_x * 6, map_y * 6, 0xFF0000);
		}
		float distance;
		if(exec->side == 0) 
			distance = (exec->side_dist_x - delta_dist_x) * 1.02;
      	else          
			distance = (exec->side_dist_y - delta_dist_y) * 1.02;
		display_environment(line, exec, distance);
		exec->ray_angle += RAD * (40.0 / WIDTH);
		exec->num++;
	}
}

float	get_angle(t_exec *exec)
{
	exec->ray_angle = exec->angle - (RAD * 20);
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
	draw(exec, &line);
}
