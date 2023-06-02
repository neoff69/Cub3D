/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:16:25 by jlaisne           #+#    #+#             */
/*   Updated: 2023/06/02 13:13:17 by vgonnot          ###   ########.fr       */
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
	int		size;
	int		pos_x;
	int		pos_y;
	int		fd;
}	t_scub;

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

typedef struct s_exec
{
	t_mlx	mlx;
	t_scub	data;
	float	vertical_movement;
	float	horizontal_movement;
	int		actual_x;
	int		actual_y;
	float	angle;
}	t_exec;

#endif