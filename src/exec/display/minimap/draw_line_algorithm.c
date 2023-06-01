/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:40:09 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/01 14:41:31 by vgonnot          ###   ########.fr       */
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

static void	get_next_wall(t_exec *exec, int *next_x, int *next_y)
{
	while (exec->data.map[*next_y][*next_x] != '1' )
	{
		*next_y -= 1;
	}
}

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

void	draw_line(t_exec *exec, int next_x, int next_y)
{
	int		i;
	t_line	line;

	i = 0;
	set_up_variable(exec, next_x, next_y, &line);
	line.final_x = exec->actual_x * SQUARE_SIZE + SQUARE_SIZE / 2;
	line.final_y = exec->actual_y * SQUARE_SIZE + SQUARE_SIZE / 2;
	while (i < line.step * SQUARE_SIZE - SQUARE_SIZE / 2)
	{
		my_mlx_pixel_put(exec, (int)line.final_x, (int)line.final_y, 0xFF0000);
		line.final_x = line.final_x + line.xincr;
		line.final_y = line.final_y + line.yincr;
		i++;
	}
}