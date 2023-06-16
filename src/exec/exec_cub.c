/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:04:14 by jlaisne           #+#    #+#             */
/*   Updated: 2023/06/16 13:39:53 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_angle(t_exec *exec)
{
	if (exec->data.player_facing == 7)
		exec->angle = 3 * PI / 2;
	else if (exec->data.player_facing == 8)
		exec->angle = 2 * PI;
	else if (exec->data.player_facing == 9)
		exec->angle = PI / 2;
	else if (exec->data.player_facing == 10)
		exec->angle = PI;
}

void	set_up_struct(t_exec *exec)
{
	exec->vertical_movement = 0;
	exec->horizontal_movement = 0;
	set_angle(exec);
	exec->delta_x = cos(exec->angle) * 2;
	exec->delta_y = sin(exec->angle) * 2;
	exec->act = 0;
	exec->off = 0;
	exec->key.key_w = 0;
	exec->key.key_a = 0;
	exec->key.key_s = 0;
	exec->key.key_d = 0;
}

void	set_up_img(t_exec *exec)
{
	t_pcub	*tp;
	int		img_width;
	int		img_height;

	tp = exec->data.cub;
	while (tp)
	{
		if (tp->type == 1)
		{
			exec->north.texture = mlx_xpm_file_to_image(exec->mlx.mlx, tp->content, &img_width, &img_height);
			if (!exec->north.texture)
				ft_exit_mlx("Error\nNull texture.", &exec->data, exec);
			exec->north.addr = mlx_get_data_addr(exec->north.texture, &exec->north.bit, &exec->north.len, &exec->north.endian);
		}
		if (tp->type == 2)
		{
			exec->south.texture = mlx_xpm_file_to_image(exec->mlx.mlx, tp->content, &img_width, &img_height);
			if (!exec->south.texture)
				ft_exit_mlx("Error\nNull texture.", &exec->data, exec);
			exec->south.addr = mlx_get_data_addr(exec->south.texture, &exec->south.bit, &exec->south.len, &exec->south.endian);
		}
		if (tp->type == 3)
		{
			exec->west.texture = mlx_xpm_file_to_image(exec->mlx.mlx, tp->content, &img_width, &img_height);
			if (!exec->west.texture)
				ft_exit_mlx("Error\nNull texture.", &exec->data, exec);
			exec->west.addr = mlx_get_data_addr(exec->west.texture, &exec->west.bit, &exec->west.len, &exec->west.endian);
		}
		if (tp->type == 4)
		{
			exec->east.texture = mlx_xpm_file_to_image(exec->mlx.mlx, tp->content, &img_width, &img_height);
			if (!exec->east.texture)
				ft_exit_mlx("Error\nNull texture.", &exec->data, exec);
			exec->east.addr = mlx_get_data_addr(exec->east.texture, &exec->east.bit, &exec->east.len, &exec->east.endian);
		}
		tp = tp->next;
	}
}

void	set_up_mlx(t_exec *exec)
{
	exec->mlx.mlx = mlx_init();
	if (!exec->mlx.mlx)
		ft_exit_mlx("Error\nNull mlx_init()", &exec->data, exec);
	exec->mlx.mlx_win = mlx_new_window(exec->mlx.mlx, WIDTH, HEIGHT, "Cub3D");
	exec->mlx.img = mlx_new_image(exec->mlx.mlx, WIDTH, HEIGHT);
	if (exec->mlx.mlx_win == NULL || exec->mlx.img == NULL)
		ft_exit_mlx("Error\nNull mlx window/ image init", &exec->data, exec);
	exec->mlx.addr = mlx_get_data_addr \
			(exec->mlx.img, &exec->mlx.bit, &exec->mlx.len, &exec->mlx.endian);
	set_up_img(exec);
}

int	exec_cub(t_exec *exec)
{
	set_up_mlx(exec);
	set_up_struct(exec);
	hook(exec);
	display_minimap(exec);
	mlx_put_image_to_window(exec->mlx.mlx, exec->mlx.mlx_win, \
		exec->mlx.img, 0, 0);
	mlx_loop(exec->mlx.mlx);
	return (0);
}
