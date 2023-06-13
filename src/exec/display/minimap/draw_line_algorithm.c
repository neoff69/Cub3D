/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:40:09 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/13 11:32:33 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	set_up_variable(t_exec *exec, int next_x, int next_y, t_line *line)
{
	float	dx;
	float	dy;

	dx = next_x - exec->actual_x;
	dy = next_y - exec->actual_y;
	if (fabs(dx) > fabs(dy))
		line->step = fabs(dx);
	else
		line->step = fabs(dy);
	line->xincr = dx / (line->step);
	line->yincr = dy / (line->step);
}

static float	rotate_line_x(t_line *origin, float length, float ang)
{
	float	x;

	x = origin->final_x + (length / CUB) * cos(ang);
	return (x);
}

static float	rotate_line_y(t_line *origin, float length, float ang)
{
	float	y;

	y = origin->final_y + (length / CUB) * sin(ang);
	return (y);
}

void	draw_offset(t_exec *exec, t_line *wall, int color, int(*pixel_put)(t_exec *, int, int, int))
{
	int		dx;
	int		dy;
	int		i;

	dx = wall->final_x - wall->x;
	dy = wall->final_y - wall->y;
	i = 0;
	if (abs(dx) > abs(dy))
		wall->step = abs(dx);
	else
		wall->step = abs(dy);
	if (dy == 0)
		return ;
	wall->xincr = dx / wall->step;
	wall->yincr = dy / wall->step;
	while (i <= wall->step)
	{
		i++;
		if (pixel_put(exec, wall->final_x, wall->final_y, color))
			return ;
		wall->final_x -= wall->xincr;
		wall->final_y -= wall->yincr;
	}
}

float	get_angle(t_exec *exec)
{
	float	ang;

	ang = exec->angle - RAD * 20;
	if (ang < 0)
		ang += 2 * PI;
	else if (ang > 2 * PI)
		ang -= 2 * PI;
	return (ang);
}

void	draw_sprite(t_exec *exec, t_img *texture, t_line *wall, int x, float wall_height)
{
	char	*dst;
	int		dx;
	int		dy;
	int		i;
	float 	y = 0;

	dx = wall->final_x - wall->x;
	dy = wall->final_y - wall->y;
	i = 0;
	if (dy == 0)
		return ;
	if (abs(dx) > abs(dy))
		wall->step = abs(dx);
	else
		wall->step = abs(dy);
	wall->xincr = dx / wall->step;
	wall->yincr = dy / wall->step;
	dst = NULL;
	while (i <= wall->step)
	{
		i++;
		if (wall_height == HEIGHT)
			dst = pixel_return(texture, x, (SPRITE_SIZE * ((exec->act - exec->off - 10 - y) / exec->act)));
		else
			dst = pixel_return(texture, x, (SPRITE_SIZE * (wall_height - y)) / wall_height - 0.5);
		y += 1;
		my_mlx_pixel_put_wall(exec, wall->final_x, wall->final_y, *(unsigned int*)dst);
		wall->final_x -= wall->xincr;
		wall->final_y -= wall->yincr;
	}
}

int check_texture(t_line *line, t_exec *exec)
{
	if ((int)(line->x + 0.1) / SQUARE_SIZE != (int)line->x / SQUARE_SIZE && exec->data.map[(int)line->y / SQUARE_SIZE][(int)(line->x + 0.1) / SQUARE_SIZE] != '1')
		return (2);
	if ((int)(line->x - 0.1) / SQUARE_SIZE != (int)line->x / SQUARE_SIZE && exec->data.map[(int)line->y / SQUARE_SIZE][(int)(line->x - 0.1) / SQUARE_SIZE] != '1')
		return (1);
	if ((int)(line->y + 0.1) / SQUARE_SIZE != (int)line->y / SQUARE_SIZE)
		return (3);
	if ((int)(line->y - 0.1) / SQUARE_SIZE != (int)line->y / SQUARE_SIZE)
		return (4);
	return (0);
}

void	display_wall(t_line *line, t_exec *exec, float ang, int num)
{
	float	distance;
	float	wall;
	float	not_wall;
	t_line	wall_struct;
	float	sprite_x;
	float	sprite_y;

	distance = get_distance(line, exec, ang) * 2.0;
	wall = get_line_height(exec, distance);
	not_wall = line_offset(wall);
	wall_struct.x = num;
	wall_struct.final_x = wall_struct.x;
	wall_struct.y = not_wall;
	wall_struct.final_y = wall + not_wall;
	sprite_x = fmodf(line->x, 6.0) * 17.0 / 2;
	sprite_y = SPRITE_SIZE - fmodf(line->y, 6.0) * 17.0 / 2;
	if (check_texture(line, exec) == 2)
		draw_sprite(exec, &exec->west, &wall_struct, sprite_y, wall);
	else if (check_texture(line, exec) == 3)
		draw_sprite(exec, &exec->north, &wall_struct, sprite_x, wall);
	else if (check_texture(line, exec) == 4)
		draw_sprite(exec, &exec->south, &wall_struct, SPRITE_SIZE - fmodf(line->x, 6.0) * 17.0 / 2, wall);
	else
		draw_sprite(exec, &exec->east, &wall_struct, (fmodf(line->y, 6.0) * 17.0 / 2), wall);
	wall_struct.y = not_wall + wall;
	wall_struct.final_y = HEIGHT;
	draw_offset(exec, &wall_struct,  exec->data.f_color, &my_mlx_put_offset);
	wall_struct.y = not_wall;
	wall_struct.final_y = 0.0;
	draw_offset(exec, &wall_struct, exec->data.c_color, &my_mlx_put_offset);
}

void	draw(t_exec *exec, t_line *line, float ang)
{
	int		i;
	int		num;

	num = 0;
	while (num <= WIDTH)
	{
		i = 0;
		while (1)
		{
			line->x = rotate_line_x(line, i, ang);
			line->y = rotate_line_y(line, i, ang);
			if (my_mlx_pixel_put_rt(exec, (int)line->x, (int)line->y, RAY_MINIMAP))
				break ;
			i++;
		}
		display_wall(line, exec, ang, num);
		ang += RAD * (40.0 / WIDTH);
		num ++;
	}
}

void	draw_line(t_exec *exec)
{
	t_line	line;
	float	ang;

	ang = get_angle(exec);
	set_up_variable(exec, exec->actual_x, exec->actual_y, &line);
	line.final_x = (exec->actual_x + SQUARE_SIZE_PLAYER / 2);
	line.final_y = (exec->actual_y + SQUARE_SIZE_PLAYER / 2);
	draw(exec, &line, ang);
}
