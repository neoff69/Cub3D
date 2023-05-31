/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:39:48 by vgonnot           #+#    #+#             */
/*   Updated: 2023/05/31 18:58:23 by vgonnot          ###   ########.fr       */
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
	else if (keycode == KEY_W || keycode == KEY_S \
			|| keycode == KEY_A || keycode == KEY_D)
		minimap_deplacement(exec, keycode);
	return (0);
}

void	hook(t_exec *exec)
{
	mlx_hook(exec->mlx.mlx_win, 02, 1L << 0, keyhook, exec);
	mlx_hook(exec->mlx.mlx_win, 17, 1L << 0, click_to_quit, exec);
}
