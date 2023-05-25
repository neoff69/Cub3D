/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:16:05 by jlaisne           #+#    #+#             */
/*   Updated: 2023/05/25 16:02:35 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "typedef.h"

int		check_arg(char *arg, char *filetype);
int		open_arg(t_scub *data, char *file, int x);
int		parsing_cub(char **arg);
int		get_parameters(t_scub *data);
void	analyse_parameters(t_scub *data);

void	ft_exit(char *info, t_scub *data);
void	*free_2d_array(char **ptr);
void	free_cub_list(t_pcub *lst);

t_pcub	*new_node_cmd(char	*key, char *content, t_type id, t_valid check);
void	lst_cmd_add_back(t_pcub **lst, t_pcub *new);
t_pcub	*cmd_lst_last(t_pcub **lst);
int		duplicate_key(t_pcub **lst, t_pcub *node);
t_pcub	*get_node(t_pcub *lst, t_type type);
void	display_lst(t_pcub *lst);

#endif