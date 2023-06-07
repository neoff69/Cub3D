/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_deplacement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:52:57 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/07 13:10:57 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	vertical_movement(t_exec *exec, int keycode, float *x, float *y)
{
	if (keycode == KEY_S)
	{
		*x = ((exec->data.pos_x) * SQUARE_SIZE \
			+ exec->horizontal_movement);
		*y = ((exec->data.pos_y) * SQUARE_SIZE \
			+ exec->vertical_movement);
	}
	else
	{
		*x = (exec->data.pos_x * SQUARE_SIZE \
			+ exec->horizontal_movement);
		*y = (exec->data.pos_y * SQUARE_SIZE \
			+ exec->vertical_movement);
	}
}

void	horizontal_movement(t_exec *exec, int keycode, float *x, float *y)
{
	if (keycode == KEY_D)
	{
		*x = ((exec->data.pos_x) * SQUARE_SIZE \
			+ exec->horizontal_movement);
		*y = ((exec->data.pos_y) * SQUARE_SIZE \
			+ exec->vertical_movement);
	}
	else
	{
		*x = (exec->data.pos_x * SQUARE_SIZE \
			+ exec->horizontal_movement);
		*y = (exec->data.pos_y * SQUARE_SIZE \
			+ exec->vertical_movement);

	}
}

int	draw_player_check(int x, int y, t_exec *exec)
{
	int	i;
	int	j;

	i = 0;
	while (i < SQUARE_SIZE_PLAYER)
	{
		j = 0;
		while (j < SQUARE_SIZE_PLAYER)
		{
			if (pixel_check(exec, x + j, y + i))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// int	check_in_map(float x, float y, t_exec *exec, int keycode)
// {
// 	(void)keycode;
// 	if (draw_player_check((int)x, (int)y, exec))
// 		return (1);
// 	return (0);
// }

int	check_if_wall(t_exec *exec, int keycode)
{
	float	x;
	float	y;

	x = 0;
	y = 0;
	if (keycode == KEY_S || keycode == KEY_W)
		vertical_movement(exec, keycode, &x, &y);
	else
		horizontal_movement(exec, keycode, &x, &y);
	if (draw_player_check((int)x, (int)y, exec))
		return (1);
	return (0);
}

void	minimap_deplacement(t_exec *exec, int keycode)
{	
	float	temp_hor;
	float	temp_ver;

	temp_hor = exec->horizontal_movement;
	temp_ver = exec->vertical_movement;
	if (keycode == KEY_W)
	{
		exec->horizontal_movement += exec->delta_x;
		exec->vertical_movement += exec->delta_y;
	}
	else if (keycode == KEY_S)
	{
		exec->horizontal_movement -= exec->delta_x;
		exec->vertical_movement -= exec->delta_y;
	}
	else if (keycode == KEY_D)
	{
		exec->horizontal_movement += cos(exec->angle + PI / 2);
		exec->vertical_movement += sin(exec->angle + PI / 2);
	}
	else if (keycode == KEY_A)
	{
		exec->horizontal_movement -= cos(exec->angle + PI / 2);
		exec->vertical_movement -= sin(exec->angle + PI / 2);
	}
	if (check_if_wall(exec, keycode))
	{
		exec->horizontal_movement = temp_hor;
		exec->vertical_movement = temp_ver;
	}
	set_image_win(exec);
}
