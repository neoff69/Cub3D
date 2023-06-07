/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:39:48 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/06 13:13:07 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	click_to_quit(t_exec *exec)
{
	(void)exec;
	exit(0); //LEAKS A GERER
	return (0);
}

int	keyhook(int keycode, t_exec *exec)
{
	if (keycode == KEY_ESCAPE)
		exit(0); //LEAKS A GERER
	if (keycode == KEY_W || keycode == KEY_S \
			|| keycode == KEY_A || keycode == KEY_D)
		minimap_deplacement(exec, keycode);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		minimap_rotation(exec, keycode);
	return (0);
}

void	hook(t_exec *exec)
{
	mlx_hook(exec->mlx.mlx_win, 02, 1L << 0, keyhook, exec);
	mlx_hook(exec->mlx.mlx_win, 17, 1L << 0, click_to_quit, exec);
}
