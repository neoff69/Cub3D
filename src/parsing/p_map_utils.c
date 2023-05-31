/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:23:45 by juleslaisne       #+#    #+#             */
/*   Updated: 2023/05/31 10:11:42 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_pcub	*new_map_node(char *key)
{
	t_pcub	*new;

	new = malloc(sizeof(t_pcub));
	if (!new)
		return (NULL);
	new->key = ft_strdup(key);
	new->content = NULL;
	if (!new->key)
		return (NULL);
	new->next = NULL;
	return (new);
}

size_t	map_lst_size(t_pcub **lst)
{
	size_t	size;
	t_pcub	*temp;

	temp = *lst;
	size = 0;
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

void	fill_map_lst_next(char *str, t_scub *data)
{
	t_pcub	*ptr;

	ptr = NULL;
	while (str)
	{
		free(str);
		str = get_next_line(data->fd, 0);
		if (!str)
		{
			str = get_next_line(data->fd, 1);
			break ;
		}
		ptr = new_map_node(str);
		if (!ptr)
		{
			free(str);
			str = get_next_line(data->fd, 1);
			ft_exit("Error\nMalloc.", data);
		}
		lst_cmd_add_back(&data->map_fill, ptr);
	}
}

void	get_position(t_scub *data, int x, int y, char c)
{
	int	len;

	if (c != 'N' && c != 'W' && c != 'E' && c != 'S')
		return ;
	data->pos_x = x;
	data->pos_y = y;
	len = (int)ft_strlen(data->map[y]);
	if (x == 0 || y == 0 || y == data->size - 1 || x == len - 2)
		ft_exit("Error\nPlayer is out of bounds.", data);
	if ((data->map[y - 1][x] && data->map[y - 1][x] == ' ')
		|| (data->map[y + 1][x] && data->map[y + 1][x] == ' ')
		|| (data->map[y][x - 1] && data->map[y][x - 1] == ' ')
		|| (data->map[y][x + 1] && data->map[y][x + 1] == ' '))
		ft_exit("Error\nPlayer is out of bounds.", data);
}
