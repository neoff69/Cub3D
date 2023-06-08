/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:40:09 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/08 13:52:22 by jlaisne          ###   ########.fr       */
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
	line->xincr = dx / line->step;
	line->yincr = dy / line->step;
}

static float	rotate_line_x(t_line *origin, float length, float ang)
{
	float	x;

	x = origin->final_x + (length / 10.0) * cos(ang);
	return (x);
}

static float	rotate_line_y(t_line *origin, float length, float ang)
{
	float	y;

	y = origin->final_y + (length / 10.0) * sin(ang);
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

// static void	single_ray(t_program *prog, t_img *img, int x, double rot)
// {
// 	int			i;
// 	t_side		wall;
// 	int			ln_ht;
// 	t_img		spr;
// 	int			start;

// 	wall = get_wall(prog, rot);
// 	spr = prog->sprites[get_texture(&wall, rot)];
// 	ln_ht = 2 * (img->height / (wall.dist * \
// 		cos((rot - prog->player.rot) / 180 * M_PI)));
// 	start = (img->height - ln_ht) / 2;
// 	i = -1;
// 	while (++i < img->height)
// 	{
// 		if (i < start + ln_ht)
// 			pixel_put(img, x, i, pixel_get(&spr, wich_x(&wall, spr.width), \
// 			trunc((i + 0.5 - start) / ln_ht * spr.height)));
//     }
// }

void	draw_sprite(t_exec *exec, t_line *wall, t_line *line, int x)
{
	char	*dst;
	int		dx;
	int		dy;
	int		i;
	int 	y = 50;

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
		dst = pixel_return(exec, (float)(x % SPRITE_SIZE), y);
		y--;
		if (y < 0)
			y = SPRITE_SIZE;
		my_mlx_pixel_put_wall(exec, wall->final_x, wall->final_y, *(unsigned int*)dst);
		wall->final_x -= wall->xincr;
		wall->final_y -= wall->yincr;
	}
}

void	display_wall(t_line *line, t_exec *exec, float ang, int num)
{
	float	distance;
	float	wall;
	float	not_wall;
	t_line	wall_struct;

	distance = get_distance(line, exec, ang);
	wall = get_line_height(distance);
	not_wall = line_offset(wall);
	wall_struct.x = num * (WIDTH / 1920);
	wall_struct.final_x = wall_struct.x;
	wall_struct.y = not_wall + wall;
	wall_struct.final_y = HEIGHT;
	draw_offset(exec, &wall_struct,  exec->data.f_color, &my_mlx_put_offset);
	wall_struct.y = not_wall;
	wall_struct.final_y = 0.0;
	draw_offset(exec, &wall_struct, exec->data.c_color, &my_mlx_put_offset);
	wall_struct.y = not_wall;
	wall_struct.final_y = wall + not_wall;
	// printf("x = %f y = %f\n", line->x, line->y);
	draw_sprite(exec, &wall_struct, line, num);
}

void	draw(t_exec *exec, t_line *line, float ang)
{
	int		i;
	int		num;

	num = 0;
	while (num <= WIDTH)
	{
		i = 0;
		while (i <= WIDTH)
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
