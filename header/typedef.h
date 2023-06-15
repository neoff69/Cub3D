/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:16:25 by jlaisne           #+#    #+#             */
/*   Updated: 2023/06/15 10:41:05 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef enum s_type
{
	FILL,
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	N,
	E,
	S,
	W,
	SPRITE,
	CODE
}	t_type;

typedef enum s_valid
{
	VALID,
	FALSE
}	t_valid;

typedef enum s_pressed
{
	PRE,
	REL
}	t_pressed;

typedef struct s_pcub
{
	char			*key;
	char			*content;
	t_valid			arg;
	t_type			type;
	struct s_pcub	*next;
}	t_pcub;

typedef struct s_scub
{
	char	**map;
	t_pcub	*map_fill;
	t_pcub	*cub;
	char	*first_wall;
	t_type	player_facing;
	t_valid	player;
	int		c_tab[3];
	int		f_tab[3];
	int		c_color;
	int		f_color;
	int		size;
	int		pos_x;
	int		pos_y;
	int		fd;
}	t_scub;

typedef struct s_line
{
	float	final_x;
	float	final_y;
	int		step;
	float	xincr;
	float	yincr;
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	wall_height;
}	t_line;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bit;
	int		len;
	int		endian;
}	t_mlx;

typedef struct s_key
{
	t_pressed key_w;
	t_pressed key_a;
	t_pressed key_s;
	t_pressed key_d;
	t_pressed key_r;
	t_pressed key_l;
}	t_key;

typedef struct s_img
{
	void	*texture;
	char	*addr;
	int		bit;
	int		len;
	int		endian;
}	t_img;


typedef struct s_exec
{
	t_mlx	mlx;
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
	t_scub	data;
	t_key	key;
	float	vertical_movement;
	float	horizontal_movement;
	int		actual_x;
	int		actual_y;
	int		num;
	float	angle;
	float	act;
	float	off;
	float	delta_x;
	float	delta_y;
}	t_exec;

#endif