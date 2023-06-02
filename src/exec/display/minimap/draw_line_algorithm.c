/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:40:09 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/02 17:09:00 by jlaisne          ###   ########.fr       */
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

void set_pixel_color(t_exec *exec, int x, int y, int color)
{
    char *pixel = exec->mlx.addr + (y * exec->mlx.len + x * (exec->mlx.bit / 8));
    *(unsigned int*)pixel = color;
}

void draw_wall(t_exec *data, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (x0 != x1 || y0 != y1)
    {
        set_pixel_color(data, x0, y0, color);
        int err2 = err * 2;
        if (err2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (err2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

float	get_angle(t_exec *exec)
{
	float	ang;

	ang = exec->angle - RAD * 40;
	ang = exec->angle - RAD * 45;
	if (ang < 0)
		ang += 2 * PI;
	else if (ang > 2 * PI)
		ang -= 2 * PI;
	return (ang);
}

void	draw(t_exec *exec, t_line *line, float ang)
{
	int		i;
	int		num;
	float	x;
	float	y;
	float distance;
	float wall;
	float not_wall;

	num = 0;
	while (num < 80)
	{
		i = 0;
		while (i < WIDTH)
		{
			x = rotate_line_x(line, i, ang);
			y = rotate_line_y(line, i, ang);
			if (x >= 1920 || x <= 0 || y >= 1080 || y <= 0)
				break ;
			if (my_mlx_pixel_put(exec, (int)x, (int)y, 0xFF0000))
				break ;
			i++;
		}
		distance = ((line->final_x - x) * (line->final_x - x)) + ((line->final_y - y) * (line->final_y - y));
		distance = sqrt(distance);
		distance = adjusted_dist(exec, ang, distance);
		wall = get_line_height(distance);
		not_wall = line_offset(wall);
		// draw_wall(exec, num * 24, wall - not_wall , num * 24, wall + not_wall, 0xFFFF);
		draw_wall(exec, num * 24, not_wall, num * 24, wall + not_wall, 0xFFFFFF);
		ang += RAD;
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
