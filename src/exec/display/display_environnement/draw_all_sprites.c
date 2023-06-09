/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:14:08 by jlaisne           #+#    #+#             */
/*   Updated: 2023/06/20 11:49:59 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	get_incrementation_and_step(t_line *wall)
{
	int	dx;
	int	dy;

	dx = wall->final_x - wall->x;
	dy = wall->final_y - wall->y;
	if (dy == 0)
		return ;
	wall->step = dy;
	wall->xincr = dx / wall->step;
	wall->yincr = dy / wall->step;
}

static void	draw_sprite(\
	t_exec *exec, t_img *texture, t_line *wall, int x)
{
	char	*dst;
	int		i;
	float	y;

	y = 0;
	i = 0;
	get_incrementation_and_step(wall);
	dst = NULL;
	while (i <= wall->step)
	{
		i++;
		if (wall->wall_height == HEIGHT)
			dst = pixel_return(texture, x, \
				(SPRITE_SIZE * ((exec->act - 5 - exec->off - y) / exec->act)));
		else
			dst = pixel_return(texture, x, (SPRITE_SIZE * \
				(wall->wall_height - y)) / wall->wall_height - 0.5);
		y++;
		my_mlx_pixel_put_wall(\
		exec, wall->final_x, wall->final_y, *(unsigned int *)dst);
		wall->final_x -= wall->xincr;
		wall->final_y -= wall->yincr;
	}
}

int	check_texture(t_exec *exec)
{
	if (exec->side == 0)
	{
		if (exec->dx < 0)
			return (1);
		else
			return (2);
	}
	else
	{
		if (exec->dy < 0)
			return (4);
		else
			return (3);
	}
	return (0);
}

void	draw_all_sprites(t_exec *exec, \
		float wall_height, t_line *wall_struct)
{
	int		texture;
	float	x;

	wall_struct->wall_height = wall_height;
	x = (exec->coll - (int)exec->coll) * SPRITE_SIZE;
	if (x < 0)
		x = SPRITE_SIZE - fabs(x);
	texture = check_texture(exec);
	if (texture == 2)
		draw_sprite(exec, &exec->west, wall_struct, x);
	else if (texture == 3)
		draw_sprite(exec, &exec->north, wall_struct, x);
	else if (texture == 4)
		draw_sprite(exec, &exec->south, wall_struct, x);
	else
		draw_sprite(exec, &exec->east, wall_struct, x);
}
