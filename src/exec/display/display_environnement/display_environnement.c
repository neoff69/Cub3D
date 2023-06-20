/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_environnement.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:54:04 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/20 11:39:17 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_offset(t_exec *exec, t_line *wall, int color)
{
	int		dx;
	int		dy;
	int		i;

	dx = wall->final_x - wall->x;
	dy = wall->final_y - wall->y;
	i = 0;
	if (dy == 0)
		return ;
	wall->step = dy;
	wall->xincr = dx / wall->step;
	wall->yincr = dy / wall->step;
	while (i <= wall->step)
	{
		i++;
		if (my_mlx_put_offset(exec, wall->final_x, wall->final_y, color))
			return ;
		wall->final_x -= wall->xincr;
		wall->final_y -= wall->yincr;
	}
}

void	draw_floor_and_sky( \
	t_exec *exec, float wall, float not_wall, t_line *wall_struct)
{
	wall_struct->x = exec->num;
	wall_struct->final_x = wall_struct->x;
	wall_struct->y = 0.0;
	wall_struct->final_y = not_wall;
	draw_offset(exec, wall_struct, exec->data.c_color);
	wall_struct->y = not_wall + wall;
	wall_struct->final_y = HEIGHT;
	draw_offset(exec, wall_struct, exec->data.f_color);
	wall_struct->y = not_wall;
	wall_struct->final_y = 0.0;
	draw_offset(exec, wall_struct, exec->data.c_color);
}

void	display_environment(t_exec *exec, float ang, float distance)
{
	float	wall;
	float	not_wall;
	t_line	wall_struct;

	distance = adjusted_dist(exec, ang, distance);
	wall = get_line_height(exec, distance);
	not_wall = line_offset(wall);
	wall_struct.x = exec->num;
	wall_struct.final_x = wall_struct.x;
	draw_floor_and_sky(exec, wall, not_wall, &wall_struct);
	wall_struct.y = not_wall;
	wall_struct.final_y = wall + not_wall;
	draw_all_sprites(exec, wall, &wall_struct);
}
