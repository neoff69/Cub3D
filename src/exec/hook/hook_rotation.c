/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:23:28 by jlaisne           #+#    #+#             */
/*   Updated: 2023/06/20 11:49:04 by jlaisne          ###   ########.fr       */
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
	exec->delta_x = cos(exec->angle) * 4;
	exec->delta_y = sin(exec->angle) * 4;
	if (exec->delta_x > 0.0 && exec->delta_x < 1.0)
		exec->delta_x += 1;
	else if (exec->delta_x < 0.0 && exec->delta_x > -1.0)
		exec->delta_x -= 1;
	if (((exec->delta_y >= 3.995 && exec->delta_y <= 4.01) \
	|| (exec->delta_y <= -3.995 && exec->delta_y >= -4.01)))
		exec->delta_x = 0.0;
	if (((exec->delta_x >= 3.995 && exec->delta_x <= 4.01) \
	|| (exec->delta_x <= -3.995 && exec->delta_x >= -4.01)))
		exec->delta_y = 0.0;
	set_image_win(exec);
}
