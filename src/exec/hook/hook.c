/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:39:48 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/06 11:39:47 by jlaisne          ###   ########.fr       */
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
	if (keycode == KEY_W)
		exec->key.key_w = PRE;
	if (keycode == KEY_A)
		exec->key.key_a = PRE;
	if (keycode == KEY_S)
		exec->key.key_s = PRE;
	if (keycode == KEY_D)
		exec->key.key_d = PRE;
	if (keycode == KEY_W || keycode == KEY_S \
			|| keycode == KEY_A || keycode == KEY_D)
		minimap_deplacement(exec, keycode);
	else if (keycode == KEY_Q || keycode == KEY_E)
		minimap_rotation(exec, keycode);
	return (0);
}

int	keyhook_r(int keycode, t_exec *exec)
{
	if (keycode == KEY_W)
		exec->key.key_w = REL;
	if (keycode == KEY_A)
		exec->key.key_a = REL;
	if (keycode == KEY_S)
		exec->key.key_s = REL;
	if (keycode == KEY_D)
		exec->key.key_d = REL;
	if (keycode == KEY_W || keycode == KEY_S \
			|| keycode == KEY_A || keycode == KEY_D)
		minimap_deplacement(exec, keycode);
	return (0);
}

void	hook(t_exec *exec)
{
	mlx_hook(exec->mlx.mlx_win, 02, 1L << 0, keyhook, exec);
	mlx_hook(exec->mlx.mlx_win, 03, 2L << 0, keyhook_r, exec);
	mlx_hook(exec->mlx.mlx_win, 17, 1L << 0, click_to_quit, exec);
}
