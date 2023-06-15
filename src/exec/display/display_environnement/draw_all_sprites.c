/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:07:37 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/15 14:35:28 by jlaisne          ###   ########.fr       */
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
	(void)exec;

	// printf("line x %f x %f\n", line->final_x, line->x);
	// printf("line x %d line x %d\n",  (int)line->x + 1, (int)line->x);
	// printf("line x %d line x %d\n",  (int)line->x + 1, (int)line->x);

	if (exec->actual_x > line->x && exec->actual_y < line->y)
	{
		if (line->final_x > line->x)
			return (2);
	}
	if (exec->actual_x < line->x)
	{
		if (line->final_x < line->x)
			return (1);
	}
	if (line->final_y > line->y)
		return (3);
	else
		return (4);
	return (0);
}

void	draw_all_sprites( \
	t_exec *exec, float wall_height, t_line *line, t_line *wall_struct)
{
	float	sprite_x;
	float	sprite_y;
	int		texture;

	wall_struct->wall_height = wall_height;
	sprite_x = fmodf(line->x, SQUARE_SIZE) * 8;
	sprite_y = SPRITE_SIZE - fmodf(line->y, SQUARE_SIZE) * 8.5;
	texture = check_texture(line, exec);
	if (texture == 2)
		draw_sprite(exec, &exec->west, wall_struct, sprite_y);
	else if (texture == 3)
		draw_sprite(exec, &exec->north, wall_struct, sprite_x);
	else if (texture == 4)
		draw_sprite(exec, &exec->south, wall_struct, SPRITE_SIZE \
			- fmodf(line->x, SQUARE_SIZE) * 8);
	else
		draw_sprite(exec, &exec->east, wall_struct, \
		(fmodf(line->y, SQUARE_SIZE) * 8.5));
}
