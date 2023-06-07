/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_analyse_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:15:21 by jlaisne           #+#    #+#             */
/*   Updated: 2023/06/07 12:44:22 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	key_compare(t_pcub *lst, t_scub *data);
int		open_content_sprites(t_scub *data);
int		check_colors(t_scub *data);

void	analyse_parameters(t_scub *data)
{
	t_pcub	*temp;
	int		keys;
	char	*str;
	
	keys = 0;
	temp = data->cub;
	while (temp)
	{
		key_compare(temp, data);
		if (duplicate_key(&data->cub, temp) == 1)
		{
			str = get_next_line(-1, 1);
			ft_exit("Error\nDuplicate textures.", data);
		}
		temp = temp->next;
		keys++;
	}
	if (keys != 6 || open_content_sprites(data) == 1 || check_colors(data) == 1)
	{
		str = get_next_line(-1, 1);
		free(str);
		ft_exit("Error\nInvalid arguments.", data);
	}
	return ;
}

void	key_compare(t_pcub *lst, t_scub *data)
{
	char	*str;

	if (ft_strncmp(lst->key, "NO", ft_strlen(lst->key) + 1) == 0)
		lst->type = NO;
	else if (ft_strncmp(lst->key, "SO", ft_strlen(lst->key) + 1) == 0)
		lst->type = SO;
	else if (ft_strncmp(lst->key, "WE", ft_strlen(lst->key) + 1) == 0)
		lst->type = WE;
	else if (ft_strncmp(lst->key, "EA", ft_strlen(lst->key) + 1) == 0)
		lst->type = EA;
	else if (ft_strncmp(lst->key, "C", ft_strlen(lst->key) + 1) == 0)
		lst->type = C;
	else if (ft_strncmp(lst->key, "F", ft_strlen(lst->key) + 1) == 0)
		lst->type = F;
	else
	{
		str = get_next_line(-1, 1);
		free(str);
		ft_exit("Error\nInvalid key identifier.", data);
	}
}

int	open_content_sprites(t_scub *data)
{
	t_pcub	*temp;

	temp = data->cub;
	while (temp)
	{
		if (temp->type < 5)
		{
			if (check_arg(temp->content, ".xpm") == 1)
				return (1);
			if (open_arg(data, temp->content, 0) == 1)
				return (1);
		}
		temp = temp->next;
	}
	return (0);
}

int	split_and_check(t_scub *data, char *content, int index)
{
	int		i;
	char	**colors;

	i = 0;
	colors = ft_split(content, ',');
	if (!colors)
		return (printf("Error\nmalloc\n"), 1);
	if (colors[3])
		return (printf("Error\nInvalid RGB format\n"), free_2d_array(colors), 1);
	while (i < 3)
	{
		if (ft_atoll(colors[i]) < 0 || ft_atoll(colors[i]) > 255)
			return (free_2d_array(colors), 1);
		if (index == 0)
			data->f_tab[i] = ft_atoll(colors[i]);
		if (index == 1)
			data->c_tab[i] = ft_atoll(colors[i]);
		i++;
	}
	if (index == 0)
		data->f_color = (data->f_tab[0] << 16) + (data->f_tab[1] << 8) + data->f_tab[2];
	if (index == 1)
		data->c_color = (data->c_tab[0] << 16) + (data->c_tab[1] << 8) + data->c_tab[2];
	free_2d_array(colors);
	return (0);
}

int	check_colors(t_scub *data)
{
	t_pcub	*floor;
	t_pcub	*ceilling;

	floor = get_node(data->cub, F);
	ceilling = get_node(data->cub, C);
	if (split_and_check(data, floor->content, 0) == 1)
		return (1);
	if (split_and_check(data, ceilling->content, 1) == 1)
		return (1);
	return (0);
}
