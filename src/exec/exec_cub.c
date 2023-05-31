/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:04:14 by jlaisne           #+#    #+#             */
/*   Updated: 2023/05/31 18:44:52 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_up_struct(t_exec *exec)
{
	exec->vertical_movement = 0;
	exec->horizontal_movement = 0;
}

void	set_up_mlx(t_exec *exec)
{
	exec->mlx.mlx = mlx_init();
	if (exec->mlx.mlx == NULL)
		exit (0); //A GERER
	exec->mlx.mlx_win = mlx_new_window(exec->mlx.mlx, 1920, 1080, "Cub3D");
	exec->mlx.img = mlx_new_image(exec->mlx.mlx, 1920, 1080);
	if (exec->mlx.mlx_win == NULL || exec->mlx.img == NULL)
		exit(0); //A GERER
	exec->mlx.addr = mlx_get_data_addr \
			(exec->mlx.img, &exec->mlx.bit, &exec->mlx.len, &exec->mlx.endian);
}

int	exec_cub(t_exec *exec)
{
	set_up_mlx(exec);
	set_up_struct(exec);
	hook(exec);
	display_game(exec);
	mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_win, exec->mlx.img, 0, 0);
	mlx_loop(exec->mlx.mlx);
	return (0);
}
