/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:16:05 by jlaisne           #+#    #+#             */
/*   Updated: 2023/06/19 13:36:55 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "typedef.h"
# include "keycode.h"

int		check_arg(char *arg, char *filetype);
int		open_arg(t_scub *data, char *file, int x);
int		parsing_cub(char **arg, t_scub *data);
int		get_parameters(t_scub *data);
void	get_position(t_scub *data, int x, int y, char c);
void	analyse_parameters(t_scub *data);

void	ft_exit(char *info, t_scub *data);
void	ft_exit_mlx(char *info, t_scub *data, t_exec *exec);
void	ft_return(char *info, t_scub *data);
void	*free_2d_array(char **ptr);
void	free_cub_list(t_pcub *lst);

int		check_char(char c);
void	check_par_map(char *str, t_scub *data, char **map);

t_pcub	*new_node_cmd(char	*key, char *content, t_type id, t_valid check);
void	lst_cmd_add_back(t_pcub **lst, t_pcub *new);
t_pcub	*cmd_lst_last(t_pcub **lst);
int		duplicate_key(t_pcub **lst, t_pcub *node);
t_pcub	*get_node(t_pcub *lst, t_type type);
t_pcub	*new_map_node(char *key);
size_t	map_lst_size(t_pcub **lst);
void	fill_map_lst_next(char *str, t_scub *data);

char	**fill_map_array(t_scub *data);
void	fill_map(t_scub *data);

/* TIME */
int		exec_cub(t_exec *exec);
void	set_up_img(t_exec *exec);

/* DISPLAY */
void	display_game(t_exec *exec);
void	display_minimap(t_exec *exec);
void	display_minimap_character(t_exec *exec);
void	display_game(t_exec *exec);
void	draw_square(int y, int x, int color, t_exec *exec);
int		draw_player(int y, int x, int color, t_exec *exec);
void	display_environment(t_line *line, t_exec *exec, float distance);
void	draw_all_sprites( \
	t_exec *exec, float wall_height, t_line *line, t_line *wall_struct);

/* HOOK */
void	hook(t_exec *exec);
void	minimap_deplacement(t_exec *exec, int keycode);
void	minimap_rotation(t_exec *exec, int keycode);
int		draw_player_check(int x, int y, t_exec *exec);
void	check_if_right_wall(t_exec *exec);
void	check_if_left_wall(t_exec *exec);
void	check_if_upper_wall(t_exec *exec);
void	check_if_lower_wall(t_exec *exec);

/* LINE */
float	line_offset(float lineHeight);
float	get_line_height(t_exec *exec, float dist);
float	adjusted_dist(t_exec *exec, float ray_angle, float dist);

/* UTILS */
int		my_mlx_pixel_put(t_exec *exec, int x, int y, int color);
int		my_mlx_pixel_put_wall(t_exec *exec, int x, int y, int color);
int		check_if_corner(t_exec *exec, int bit, int x, int y);
int		my_mlx_pixel_put_rt(t_exec *exec, int x, int y, int color);
int		my_mlx_put_offset(t_exec *exec, int x, int y, int color);
int		pixel_check(t_exec *exec, int x, int y);
void	set_image_win(t_exec *exec);
char	*pixel_return(t_img *data, int x, int y);

#endif