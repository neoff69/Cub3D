/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:40:09 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/06 15:15:05 by jlaisne          ###   ########.fr       */
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
	float	x;
	float	y;
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

static float	rotate_line_x(t_line *origin, float length, float ang)
{
	int	x;

	x = origin->final_x + length * cos(ang);
	return (x);
}

static float	rotate_line_y(t_line *origin, float length, float ang)
{
	int	y;

	y = origin->final_y + length * sin(ang);
	return (y);
}

void	draw_wall(t_exec *exec, t_line *wall, int color)
{
	int	dx;
	int	dy;
	int	i;

	dx = wall->final_x - wall->x;
	dy = wall->final_y - wall->y;
	i = 0;
	if (abs(dx) > abs(dy))
		wall->step = abs(dx);
	else
		wall->step = abs(dy);
	wall->xincr = dx / wall->step;
	wall->yincr = dy / wall->step;
	while (i < wall->step)
	{
		i++;
		if (my_mlx_pixel_put_wall(exec, wall->final_x, wall->final_y, color))
			return ;
		wall->final_x -= wall->xincr;
		wall->final_y -= wall->yincr;
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

float	get_distance(t_line *line, t_exec *exec, float ang)
{
	float	distance;

	distance = ((line->final_x - line->x) * (line->final_x - line->x)) \
			+ ((line->final_y - line->y) * (line->final_y - line->y));
	distance = sqrt(distance);
	distance = adjusted_dist(exec, ang, distance);
	return (distance);
}

void	display_wall(t_line *line, t_exec *exec, float ang, int num)
{
	float	distance;
	float	wall;
	float	not_wall;
	t_line	wall_struct;

	distance = get_distance(line, exec, ang);
	wall = get_line_height(distance);
	not_wall = line_offset(wall);
	wall_struct.x = num * (WIDTH / 1920);
	wall_struct.final_x = wall_struct.x;
	wall_struct.y = not_wall;
	wall_struct.final_y = wall + not_wall;
	draw_wall(exec, &wall_struct, 0x00FFFF);
}

void	draw(t_exec *exec, t_line *line, float ang)
{
	int		i;
	int		num;

	num = 0;
	while (num < WIDTH)
	{
		i = 0;
		while (i < WIDTH)
		{
			line->x = rotate_line_x(line, i, ang);
			line->y = rotate_line_y(line, i, ang);
			if (line->x >= 1920 || line->x <= 0 \
				|| line->y >= 1080 || line->y <= 0)
				break ;
			if (my_mlx_pixel_put_rt(exec, (int)line->x, (int)line->y, 0xFF0000))
				break ;
			i++;
		}
		display_wall(line, exec, ang, num);
		ang += RAD * (40.0 / WIDTH);
		num++;
	}
}

void	draw_line(t_exec *exec)
{
	t_line	line;
	float	ang;

	ang = get_angle(exec);
	set_up_variable(exec, exec->actual_x, exec->actual_y, &line);
	line.final_x = (exec->actual_x + SQUARE_SIZE / 2);
	line.final_y = (exec->actual_y + SQUARE_SIZE / 2);
	draw(exec, &line, ang);
}
