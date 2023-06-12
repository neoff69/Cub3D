/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:18:13 by jlaisne           #+#    #+#             */
/*   Updated: 2023/06/12 09:46:09 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

float	adjusted_dist(t_exec *exec, float ray_angle, float dist)
{
	float	actualAng;

	actualAng = exec->angle - ray_angle;
	if (actualAng < 0)
		actualAng += 2 * PI;
	else if (actualAng > (2 * PI))
		actualAng -= 2 * PI;
	dist = dist * cos(actualAng);
	return (dist);
}

float	get_line_height(t_exec *exec, float dist)
{
	float	lineHeight;

	lineHeight = CUB * 1080 / dist;
	if (lineHeight > 1080)
	{
		exec->act = lineHeight;
		exec->off = (lineHeight - 1080) / 2;
		lineHeight = 1080;
	}
	return (lineHeight);
}

float	line_offset(float lineHeight)
{
	float	lineOffset;

	lineOffset = HEIGHT / 2 - lineHeight / 2;
	return (lineOffset);
}

float	get_distance(t_line *line, t_exec *exec, float ang)
{
	float	distance;

	distance = ((line->final_x - line->x) * (line->final_x - line->x)) \
			+ ((line->final_y - line->y) * (line->final_y - line->y));
	distance = sqrt(distance);
	distance = adjusted_dist(exec, ang, distance);
	return (distance);
}
