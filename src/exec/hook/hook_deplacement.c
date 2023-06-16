/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_deplacement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:52:57 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/16 13:55:23 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	draw_player_check(int x, int y, t_exec *exec)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 5)
	{
		j = 0;
		while (j <= 5)
		{
			if (pixel_check(exec, x + j, y + i))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	minimap_deplacement(t_exec *exec, int keycode)
{	
	if (keycode == KEY_W)
	{
		exec->horizontal_movement += exec->delta_x;
		exec->vertical_movement += exec->delta_y;
		check_if_upper_wall(exec);
	}
	else if (keycode == KEY_S)
	{
		exec->horizontal_movement -= exec->delta_x;
		exec->vertical_movement -= exec->delta_y;
		check_if_lower_wall(exec);
	}
	else if (keycode == KEY_D)
	{
		exec->horizontal_movement += cos(exec->angle + PI / 2);
		exec->vertical_movement += sin(exec->angle + PI / 2);
		check_if_right_wall(exec);
	}
	else if (keycode == KEY_A)
	{
		exec->horizontal_movement -= cos(exec->angle + PI / 2);
		exec->vertical_movement -= sin(exec->angle + PI / 2);
		check_if_left_wall(exec);
	}
	set_image_win(exec);
}
