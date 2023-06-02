/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:23:28 by jlaisne           #+#    #+#             */
/*   Updated: 2023/06/02 13:39:45 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	minimap_rotation(t_exec *exec, int keycode)
{
	if (keycode == KEY_Q)
	{
		exec->angle -= 0.1;
		if (exec->angle < 0)
			exec->angle += 2 * PI;
	}
	if (keycode == KEY_E)
	{
		exec->angle += 0.1;
		if (exec->angle > 2 * PI)
			exec->angle -= 2 * PI;
	}
	set_image_win(exec);
}
