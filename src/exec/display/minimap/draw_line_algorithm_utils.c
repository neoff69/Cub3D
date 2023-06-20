/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_algorithm_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:21:57 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/20 11:31:02 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_step(t_line *line, t_exec *exec, \
		float delta_dist_x, float delta_dist_y)
{
	if (exec->dx < 0)
	{
		line->step_x = -1;
		exec->side_dist_x = ((line->final_x / SQUARE_SIZE) - \
		line->map_x) * delta_dist_x;
	}
	else
	{
		line->step_x = 1;
		exec->side_dist_x = (line->map_x + 1.0 - \
		(line->final_x / SQUARE_SIZE)) * delta_dist_x;
	}
	if (exec->dy < 0)
	{
		line->step_y = -1;
		exec->side_dist_y = ((line->final_y / SQUARE_SIZE) - \
		line->map_y) * delta_dist_y;
	}
	else
	{
		line->step_y = 1;
		exec->side_dist_y = (line->map_y + 1.0 - \
		(line->final_y / SQUARE_SIZE)) * delta_dist_y;
	}
}

int	incr_until_wall(t_line *line, t_exec *exec, \
		float delta_dist_x, float delta_dist_y)
{
	if (exec->side_dist_x < exec->side_dist_y)
	{
		exec->side_dist_x += delta_dist_x;
		line->map_x += line->step_x;
		exec->side = 0;
	}
	else
	{
		exec->side_dist_y += delta_dist_y;
		line->map_y += line->step_y;
		exec->side = 1;
	}
	if (exec->data.map[line->map_y][line->map_x] == '1')
	{
		line->x = line->map_x;
		line->y = line->map_y;
		return (1);
	}
	return (0);
}

float	get_distance(t_line *line, t_exec *exec, \
		float delta_dist_x, float delta_dist_y)
{
	float	distance;

	if (exec->side == 0)
	{
		distance = (exec->side_dist_x - delta_dist_x) * 1;
		exec->coll = (((line->final_y / SQUARE_SIZE) - \
		((int)line->final_y / SQUARE_SIZE)) + distance * exec->dy);
	}
	else
	{
		distance = (exec->side_dist_y - delta_dist_y) * 1;
		exec->coll = (((line->final_x / SQUARE_SIZE) - \
		((int)line->final_x / SQUARE_SIZE)) + distance * exec->dx);
	}
	return (distance);
}
