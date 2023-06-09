/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:56:43 by jlaisne           #+#    #+#             */
/*   Updated: 2023/06/19 14:41:48 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_if_upper_wall(t_exec *exec)
{
	float	x;
	float	y;

	x = (exec->data.pos_x * SQUARE_SIZE \
			+ exec->horizontal_movement);
	y = (exec->data.pos_y * SQUARE_SIZE \
			+ exec->vertical_movement);
	while (draw_player_check((int)x, (int)y, exec))
	{
		exec->horizontal_movement -= ((int)exec->delta_x);
		exec->vertical_movement -= ((int)exec->delta_y);
		x = (exec->data.pos_x * SQUARE_SIZE \
			+ exec->horizontal_movement);
		y = (exec->data.pos_y * SQUARE_SIZE \
			+ exec->vertical_movement);
	}
}

void	check_if_lower_wall(t_exec *exec)
{
	float	x;
	float	y;

	x = (exec->data.pos_x * SQUARE_SIZE \
			+ exec->horizontal_movement);
	y = (exec->data.pos_y * SQUARE_SIZE \
			+ exec->vertical_movement);
	while (draw_player_check((int)x, (int)y, exec))
	{
		exec->horizontal_movement += ((int)exec->delta_x);
		exec->vertical_movement += ((int)exec->delta_y);
		x = (exec->data.pos_x * SQUARE_SIZE \
			+ exec->horizontal_movement);
		y = (exec->data.pos_y * SQUARE_SIZE \
			+ exec->vertical_movement);
	}
}

void	check_if_left_wall(t_exec *exec)
{
	float	x;
	float	y;

	x = (exec->data.pos_x * SQUARE_SIZE \
			+ exec->horizontal_movement);
	y = (exec->data.pos_y * SQUARE_SIZE \
			+ exec->vertical_movement);
	while (draw_player_check((int)x, (int)y, exec))
	{
		exec->horizontal_movement += cos(exec->angle + PI / 2) / 10;
		exec->vertical_movement += sin(exec->angle + PI / 2) / 10;
		x = (exec->data.pos_x * SQUARE_SIZE \
			+ exec->horizontal_movement);
		y = (exec->data.pos_y * SQUARE_SIZE \
			+ exec->vertical_movement);
	}
}

void	check_if_right_wall(t_exec *exec)
{
	float	x;
	float	y;

	x = (exec->data.pos_x * SQUARE_SIZE \
			+ exec->horizontal_movement);
	y = (exec->data.pos_y * SQUARE_SIZE \
			+ exec->vertical_movement);
	while (draw_player_check((int)x, (int)y, exec))
	{
		exec->horizontal_movement -= cos(exec->angle + PI / 2) / 10;
		exec->vertical_movement -= sin(exec->angle + PI / 2) / 10;
		x = (exec->data.pos_x * SQUARE_SIZE \
			+ exec->horizontal_movement);
		y = (exec->data.pos_y * SQUARE_SIZE \
			+ exec->vertical_movement);
	}
}
