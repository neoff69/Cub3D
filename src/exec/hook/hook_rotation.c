/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:23:28 by jlaisne           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/14 13:33:07 by jlaisne          ###   ########.fr       */
=======
/*   Updated: 2023/06/20 11:30:52 by vgonnot          ###   ########.fr       */
>>>>>>> 4a7d146ad59786f734da85d7adc2067081380176
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
<<<<<<< HEAD
=======
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
>>>>>>> 4a7d146ad59786f734da85d7adc2067081380176
	set_image_win(exec);
}
