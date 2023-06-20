/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:18:13 by jlaisne           #+#    #+#             */
/*   Updated: 2023/06/19 13:36:46 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

float	adjusted_dist(t_exec *exec, float ray_angle, float dist)
{
	float	actual_ang;

	actual_ang = exec->angle - ray_angle;
	if (actual_ang < 0)
		actual_ang += 2 * PI;
	else if (actual_ang > (2 * PI))
		actual_ang -= 2 * PI;
	dist = dist * cos(actual_ang);
	return (dist);
}

float	get_line_height(t_exec *exec, float dist)
{
	float	line_height;

	line_height = HEIGHT / dist;
	if (line_height > HEIGHT)
	{
		exec->act = line_height;
		exec->off = (line_height - HEIGHT) / 2;
		line_height = HEIGHT;
	}
	return (line_height);
}

float	line_offset(float line_height)
{
	float	line_offset;

	line_offset = HEIGHT / 2 - line_height / 2;
	return (line_offset);
}
