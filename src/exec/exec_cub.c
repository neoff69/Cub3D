/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:04:14 by jlaisne           #+#    #+#             */
/*   Updated: 2023/06/07 14:25:59 by jlaisne          ###   ########.fr       */
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
	int	img_width;
	int	img_height;
	t_pcub	*temp;

	temp = exec->data.cub;
	exec->mlx.north_img = mlx_xpm_file_to_image(exec->mlx.mlx, temp->content, &img_width, &img_height);
	temp = temp->next;
	exec->mlx.east_img = mlx_xpm_file_to_image(exec->mlx.mlx, temp->content, &img_width, &img_height);
	temp = temp->next;
	exec->mlx.south_img = mlx_xpm_file_to_image(exec->mlx.mlx, temp->content,&img_width, &img_height);
	temp = temp->next;
	exec->mlx.west_img = mlx_xpm_file_to_image(exec->mlx.mlx, temp->content, &img_width, &img_height);
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
