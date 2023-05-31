/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_deplacement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:52:57 by vgonnot           #+#    #+#             */
/*   Updated: 2023/05/31 20:05:08 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_if_wall(t_exec *exec, int keycode)
{
	int	x;
	int	y;

	(void)keycode;
	x = 0;
	y = 0;
	if (keycode == KEY_S)
	{
		x = ((exec->data.pos_x) * SQUARE_SIZE + exec->horizontal_movement) / (SQUARE_SIZE);
		y = ((1 + exec->data.pos_y) * SQUARE_SIZE + exec->vertical_movement) / (SQUARE_SIZE);
	}
	else if (keycode == KEY_D)
	{
		x = ((1 + exec->data.pos_x) * SQUARE_SIZE + exec->horizontal_movement) / (SQUARE_SIZE);
		y = ((exec->data.pos_y) * SQUARE_SIZE + exec->vertical_movement) / (SQUARE_SIZE);
	}
	else if (keycode == KEY_A)
	{
		x = (exec->data.pos_x * SQUARE_SIZE + exec->horizontal_movement - 1) / (SQUARE_SIZE);
		y = (exec->data.pos_y * SQUARE_SIZE + exec->vertical_movement) / (SQUARE_SIZE);
	}
	else if (keycode == KEY_W)
	{
		x = (exec->data.pos_x * SQUARE_SIZE + exec->horizontal_movement) / (SQUARE_SIZE);
		y = (exec->data.pos_y * SQUARE_SIZE + exec->vertical_movement - 1) / (SQUARE_SIZE);
	}
	//printf("%c %d %d\n", exec->data.map[y][x], y, x);
	if (exec->data.map[y][x] == '1')
		return (1);
	return (0);
}

void	minimap_deplacement(t_exec *exec, int keycode)
{
	if (keycode == KEY_W && check_if_wall(exec, keycode) == 0)
		exec->vertical_movement -= 1;
	else if (keycode == KEY_S && check_if_wall(exec, keycode) == 0)
		exec->vertical_movement += 1;
	else if (keycode == KEY_D && check_if_wall(exec, keycode) == 0)
		exec->horizontal_movement += 1;
	else if (keycode == KEY_A && check_if_wall(exec, keycode) == 0)
		exec->horizontal_movement -= 1;
	set_image_win(exec);
}
