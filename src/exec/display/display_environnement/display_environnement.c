/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_environnement.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:54:04 by vgonnot           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/19 14:52:47 by jlaisne          ###   ########.fr       */
=======
/*   Updated: 2023/06/20 10:02:58 by vgonnot          ###   ########.fr       */
>>>>>>> 4a7d146ad59786f734da85d7adc2067081380176
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
	draw_offset(exec, wall_struct, exec->data.c_color, &my_mlx_put_offset);
	wall_struct->y = not_wall + wall;
	wall_struct->final_y = HEIGHT;
<<<<<<< HEAD
	draw_offset(exec, wall_struct, exec->data.f_color, &my_mlx_put_offset);
=======
	draw_offset(exec, wall_struct, exec->data.f_color);
	wall_struct->y = not_wall;
	wall_struct->final_y = 0.0;
	draw_offset(exec, wall_struct, exec->data.c_color);
>>>>>>> 4a7d146ad59786f734da85d7adc2067081380176
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
