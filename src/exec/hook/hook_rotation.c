/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:23:28 by jlaisne           #+#    #+#             */
/*   Updated: 2023/06/19 14:59:44 by vgonnot          ###   ########.fr       */
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
	if (exec->delta_x > 0.0)
		exec->delta_x += 1;
	else
		exec->delta_x -= 1;
	if (exec->delta_y > 0)
		exec->delta_y += 1;
	else
		exec->delta_y -= 1;
	set_image_win(exec);
}
