/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:07:37 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/14 14:16:49 by jlaisne          ###   ########.fr       */
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
				(SPRITE_SIZE * ((exec->act - 10 - exec->off - y) / exec->act)));
		else
			dst = pixel_return(texture, x, \
			(SPRITE_SIZE * (wall->wall_height - y)) / wall->wall_height - 0.5);
		y += 1;
		my_mlx_pixel_put_wall(\
		exec, wall->final_x, wall->final_y, *(unsigned int *)dst);
		wall->final_x -= wall->xincr;
		wall->final_y -= wall->yincr;
	}
}

int	check_texture(t_line *line, t_exec *exec)
{
	if ((int)(line->x + 0.07) / SQUARE_SIZE != (int)line->x / \
			SQUARE_SIZE && exec->data.map[(int)line->y / \
			SQUARE_SIZE][(int)(line->x + 0.07) / SQUARE_SIZE] != '1')
		return (2);
	if ((int)(line->x - 0.07) / SQUARE_SIZE != (int)line->x / \
			SQUARE_SIZE && exec->data.map[(int)line->y / \
			SQUARE_SIZE][(int)(line->x - 0.07) / SQUARE_SIZE] != '1')
		return (1);
	if ((int)(line->y + 0.07) / \
			SQUARE_SIZE != (int)line->y / SQUARE_SIZE)
		return (3);
	if ((int)(line->y - 0.07) / \
			SQUARE_SIZE != (int)line->y / SQUARE_SIZE)
		return (4);
	return (0);
}

void	draw_all_sprites( \
	t_exec *exec, float wall_height, t_line *line, t_line *wall_struct)
{
	float	sprite_x;
	float	sprite_y;

	wall_struct->wall_height = wall_height;
	sprite_x = fmodf(line->x, SQUARE_SIZE) * 8.5;
	sprite_y = SPRITE_SIZE - fmodf(line->y, SQUARE_SIZE) * 8.5;
	if (check_texture(line, exec) == 2)
		draw_sprite(exec, &exec->west, wall_struct, sprite_y);
	else if (check_texture(line, exec) == 3)
		draw_sprite(exec, &exec->north, wall_struct, sprite_x);
	else if (check_texture(line, exec) == 4)
		draw_sprite(exec, &exec->south, wall_struct, SPRITE_SIZE \
			- fmodf(line->x, SQUARE_SIZE) * 8.5);
	else
		draw_sprite(exec, &exec->east, wall_struct, \
		(fmodf(line->y, SQUARE_SIZE) * 8.5));
}
