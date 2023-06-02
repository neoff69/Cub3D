/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:40:09 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/02 13:38:27 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

typedef struct s_line
{
    float    final_x;
    float    final_y;
    int        step;
    float    xincr;
    float    yincr;
}    t_line;

static void    set_up_variable(t_exec *exec, int next_x, int next_y, t_line *line)
{
    float    dx;
    float    dy;

    dx = next_x - exec->actual_x;
    dy = next_y - exec->actual_y;
    if (fabs(dx) > fabs(dy))
        line->step = fabs(dx);
    else
        line->step = fabs(dy);
    line->xincr = dx / line->step;
    line->yincr = dy / line->step;
}

float    rotate_line_x(t_line *origin, float length, float ang)
{
	int x;

    x = origin->final_x + length * cos(ang);
    return (x);
}

float    rotate_line_y(t_line *origin, float length, float ang)
{
	int y;

    y = origin->final_y + length * sin(ang);
    return (y);
}

void    draw_line(t_exec *exec)
{
    int        i;
    t_line    line;
    float    x;
    float    y;
	float    ang;

	ang = exec->angle - RAD * 45;
	if (ang < 0)
		ang += 2 * PI;
	else if (ang > 2 * PI)
		ang -= 2 * PI;
    i = 0;
	if (ang > PI)
		set_up_variable(exec, exec->actual_x, exec->actual_y - 5, &line);
	else
		set_up_variable(exec, exec->actual_x, exec->actual_y + 5, &line);
	int num = 0;
	while (num < 80)
	{
		line.final_x = (exec->actual_x * SQUARE_SIZE + SQUARE_SIZE / 2);
		line.final_y = (exec->actual_y * SQUARE_SIZE + SQUARE_SIZE / 2);
		i = 0;
		while (i < line.step * SQUARE_SIZE)
		{
			x = rotate_line_x(&line, i, ang);
			y = rotate_line_y(&line, i, ang);
			if (x >= 1920 || x <= 0 || y >= 1080 || y <= 0)
				break ;
			my_mlx_pixel_put(exec, (int)x, (int)y, 0xFF0000);
			line.final_x += line.xincr;
			line.final_y +=  line.yincr;
			i++;
		}
		ang += RAD;
		num++;
	}
}
