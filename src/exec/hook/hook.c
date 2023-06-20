/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:39:48 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/19 17:34:07 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	click_to_quit(t_exec *exec)
{
	ft_exit_mlx(NULL, &exec->data, exec);
	return (0);
}

void	reset_hook(int keycode, t_exec *exec)
{
	if (keycode == KEY_W)
		exec->key.key_w = 1;
	if (keycode == KEY_A)
		exec->key.key_a = 1;
	if (keycode == KEY_S)
		exec->key.key_s = 1;
	if (keycode == KEY_D)
		exec->key.key_d = 1;
	if (keycode == KEY_LEFT)
		exec->key.key_l = 1;
	if (keycode == KEY_RIGHT)
		exec->key.key_r = 1;
}

int	keyhook(int keycode, t_exec *exec)
{
	if (keycode == KEY_ESCAPE)
		ft_exit_mlx(NULL, &exec->data, exec);
	reset_hook(keycode, exec);
	if ((keycode == KEY_W && exec->key.key_w == 1) \
		|| (keycode == KEY_S && exec->key.key_s == 1) \
		|| (keycode == KEY_A && exec->key.key_a == 1) \
		|| (keycode == KEY_D && exec->key.key_d == 1))
		minimap_deplacement(exec, keycode);
	if ((keycode == KEY_LEFT && exec->key.key_l == 1) \
		|| (keycode == KEY_RIGHT && exec->key.key_r == 1))
		minimap_rotation(exec, keycode);
	return (0);
}

int	keyhook_rel(int keycode, t_exec *exec)
{
	if (keycode == KEY_W)
		exec->key.key_w = 0;
	if (keycode == KEY_A)
		exec->key.key_a = 0;
	if (keycode == KEY_S)
		exec->key.key_s = 0;
	if (keycode == KEY_D)
		exec->key.key_d = 0;
	if (keycode == KEY_LEFT)
		exec->key.key_l = 0;
	if (keycode == KEY_RIGHT)
		exec->key.key_r = 0;
	return (0);
}

void	hook(t_exec *exec)
{
	mlx_hook(exec->mlx.mlx_win, 2, 1L << 0, keyhook, exec);
	mlx_hook(exec->mlx.mlx_win, 3, 1L << 1, keyhook_rel, exec);
	mlx_hook(exec->mlx.mlx_win, 17, 1L << 0, click_to_quit, exec);
}
