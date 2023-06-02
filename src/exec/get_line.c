/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:18:13 by jlaisne           #+#    #+#             */
/*   Updated: 2023/06/02 14:54:40 by jlaisne          ###   ########.fr       */
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
		actualAng = 0;
	dist = dist * cos(actualAng);
	return (dist);
}

float	get_line_height(float dist)
{
	float	lineHeight;

	lineHeight = CUB * 1080 / dist;
	if (lineHeight > 1080)
		lineHeight = 1080;
	return (lineHeight);
}

float	line_offset(float lineHeight)
{
	float	lineOffset;

	lineOffset = HEIGHT / 2 - lineHeight / 2;
	return (lineOffset);
}
