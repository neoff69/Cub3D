/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:16:05 by jlaisne           #+#    #+#             */
/*   Updated: 2023/06/02 15:44:32 by jlaisne          ###   ########.fr       */
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

//EXEC
int		exec_cub(t_exec *exec);

//DISPLAY
void	display_game(t_exec *exec);
void	display_minimap(t_exec *exec);
void	display_minimap_character(t_exec *exec);
void	display_raytracing(t_exec *exec);
void	draw_square(int y, int x, int color, t_exec *exec);

//HOOK
void	hook(t_exec *exec);
void	minimap_deplacement(t_exec *exec, int keycode);
void    minimap_rotation(t_exec *exec, int keycode);

//LINE
float	line_offset(float lineHeight);
float	get_line_height(float dist);
float	adjusted_dist(t_exec *exec, float ray_angle, float dist);

//UTILS
int 	my_mlx_pixel_put(t_exec *exec, int x, int y, int color);
void	set_image_win(t_exec *exec);
void	draw_line(t_exec *exec);

#endif