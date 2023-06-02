/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:23:28 by jlaisne           #+#    #+#             */
/*   Updated: 2023/06/02 13:47:27 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	minimap_rotation(t_exec *exec, int keycode)
{
	if (keycode == KEY_Q)
	{
		exec->angle -= 0.1;
	}
	if (keycode == KEY_E)
	{
		exec->angle += 0.1;
	}
	set_image_win(exec);
}
