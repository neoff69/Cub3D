/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:51:32 by jlaisne           #+#    #+#             */
/*   Updated: 2023/06/16 13:54:44 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_textures_n_s(t_pcub *tp, t_exec *exec)
{
	int	img_width;
	int	img_height;

	if (tp->type == 1)
	{
		exec->north.texture = mlx_xpm_file_to_image(exec->mlx.mlx, tp->content, \
			&img_width, &img_height);
		if (!exec->north.texture)
			ft_exit_mlx("Error\nNull texture.", &exec->data, exec);
		exec->north.addr = mlx_get_data_addr(exec->north.texture, \
		&exec->north.bit, &exec->north.len, &exec->north.endian);
	}
	if (tp->type == 2)
	{
		exec->south.texture = mlx_xpm_file_to_image(exec->mlx.mlx, tp->content, \
			&img_width, &img_height);
		if (!exec->south.texture)
			ft_exit_mlx("Error\nNull texture.", &exec->data, exec);
		exec->south.addr = mlx_get_data_addr(exec->south.texture, \
			&exec->south.bit, &exec->south.len, &exec->south.endian);
	}
}

void	init_textures_w_e(t_pcub *tp, t_exec *exec)
{
	int	img_width;
	int	img_height;

	if (tp->type == 3)
	{
		exec->west.texture = mlx_xpm_file_to_image(exec->mlx.mlx, tp->content, \
			&img_width, &img_height);
		if (!exec->west.texture)
			ft_exit_mlx("Error\nNull texture.", &exec->data, exec);
		exec->west.addr = mlx_get_data_addr(exec->west.texture, \
			&exec->west.bit, &exec->west.len, &exec->west.endian);
	}
	if (tp->type == 4)
	{
		exec->east.texture = mlx_xpm_file_to_image(exec->mlx.mlx, tp->content, \
			&img_width, &img_height);
		if (!exec->east.texture)
			ft_exit_mlx("Error\nNull texture.", &exec->data, exec);
		exec->east.addr = mlx_get_data_addr(exec->east.texture, \
			&exec->east.bit, &exec->east.len, &exec->east.endian);
	}
}

void	set_up_img(t_exec *exec)
{
	t_pcub	*tp;

	tp = exec->data.cub;
	while (tp)
	{
		if (tp->type >= 1 && tp->type <= 2)
			init_textures_n_s(tp, exec);
		if (tp->type >= 3 && tp->type <= 4)
			init_textures_w_e(tp, exec);
		tp = tp->next;
	}
}
