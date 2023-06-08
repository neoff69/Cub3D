/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:04:14 by jlaisne           #+#    #+#             */
/*   Updated: 2023/06/08 11:31:49 by jlaisne          ###   ########.fr       */
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
}

void	set_up_img(t_exec *exec)
{
	int		img_width;
	int		img_height;
	t_pcub	*temp;

	temp = exec->data.cub;
	exec->north.texture = mlx_xpm_file_to_image(exec->mlx.mlx, temp->content, &img_width, &img_height);
	exec->north.addr = mlx_get_data_addr(exec->north.texture, &exec->north.bit, &exec->north.len, &exec->north.endian);
	// data.img = mlx_xpm_file_to_image(win->mlx, path, &img_width, &img_height);
	// env->data.textures_img = create_textures_img("./textures/east.xpm", &env->windows);
    // env->data.textures_img.addr = mlx_get_data_addr( env->data.textures_img.img, &env->data.textures_img.bits_per_pixel, &env->data.textures_img.line_length, &env->data.textures_img.endian);
	// temp = temp->next;
	// exec->south.texture = mlx_xpm_file_to_image(exec->mlx.mlx, temp->content, &img_width, &img_height);
	// exec->south.addr = mlx_get_data_addr(exec->south.texture, &exec->south.bit, &exec->south.len, &exec->south.endian);
	// temp = temp->next;
	// exec->west.texture = mlx_xpm_file_to_image(exec->mlx.mlx, temp->content, &img_width, &img_height);
	// exec->west.addr = mlx_get_data_addr(exec->west.texture, &exec->west.bit, &exec->west.len, &exec->west.endian);
	// temp = temp->next;
	// exec->east.texture = mlx_xpm_file_to_image(exec->mlx.mlx, temp->content,&img_width, &img_height);
	// exec->east.addr = mlx_get_data_addr(exec->east.texture, &exec->east.bit, &exec->east.len, &exec->east.endian);
}

void	set_up_mlx(t_exec *exec)
{
	exec->mlx.mlx = mlx_init();
	if (exec->mlx.mlx == NULL)
		exit (0); //A GERER
	exec->mlx.mlx_win = mlx_new_window(exec->mlx.mlx, 1920, 1080, "Cub3D");
	exec->mlx.img = mlx_new_image(exec->mlx.mlx, WIDTH, HEIGHT);
	if (exec->mlx.mlx_win == NULL || exec->mlx.img == NULL)
		exit(0); //A GERER
	exec->mlx.addr = mlx_get_data_addr \
			(exec->mlx.img, &exec->mlx.bit, &exec->mlx.len, &exec->mlx.endian);
	set_up_img(exec);
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
