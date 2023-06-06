/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:23:28 by jlaisne           #+#    #+#             */
/*   Updated: 2023/06/06 13:44:37 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	minimap_rotation(t_exec *exec, int keycode)
{
	if (keycode == KEY_LEFT)
	{
		exec->angle -= 0.1;
		if (exec->angle < 0)
		 	exec->angle += 2 * PI;
	}
	if (keycode == KEY_RIGHT)
	{
		exec->angle += 0.1;
		if (exec->angle > 2 * PI)
		 	exec->angle -= 2 * PI;
	}
	exec->delta_x = cos(exec->angle) * 5;
	exec->delta_y = sin(exec->angle) * 5;
	printf("dx %f  dy %f\n", exec->delta_x, exec->delta_y);
	set_image_win(exec);
}
