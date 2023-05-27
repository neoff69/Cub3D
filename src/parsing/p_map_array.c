/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juleslaisne <juleslaisne@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:01:44 by juleslaisne       #+#    #+#             */
/*   Updated: 2023/05/27 16:37:21 by juleslaisne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdbool.h>

void	fill_map_lst(t_scub *data);
void	fill_map_array(t_scub *data);
void	check_open_map(t_scub *data);

void	fill_map(t_scub *data)
{
    t_pcub	*ptr;

	ptr = new_map_node(data->first_wall);
	if (!ptr)
		ft_exit("Error\nMalloc.", data);
	lst_cmd_add_back(&data->map_fill, ptr);
	fill_map_lst(data);
	fill_map_array(data);
	check_open_map(data);

}

void	fill_map_lst(t_scub *data)
{
    char	*str;
	t_pcub	*ptr;
	
	str = get_next_line(data->fd);
	if (!str)
		ft_exit("Error\nEmpty map.", data);
	ptr = new_map_node(str);
	if (!ptr)
		ft_exit("Error\nMalloc.", data);
	lst_cmd_add_back(&data->map_fill, ptr);
	while (str)
	{
		free(str);
		str = get_next_line(data->fd);
		if (!str)
			break ;
		ptr = new_map_node(str);
		if (!ptr)
			ft_exit("Error\nMalloc.", data);
		lst_cmd_add_back(&data->map_fill, ptr);
	}
}

void	fill_map_array(t_scub *data)
{
	t_pcub	*temp;

	data->size = map_lst_size(&data->map_fill);
	if (data->size < 3)
		ft_exit("Error\nMap too small", data);
	data->map = malloc(sizeof(char *) * (data->size + 1));
	if (!data->map)
		ft_exit("Error\nMalloc.", data);
	temp = data->map_fill;
	data->size = 0;
	while (temp)
	{
		data->map[data->size] = ft_strdup(temp->key);
		check_par_map(data->map[data->size], data, data->size);
		data->size++;
		temp = temp->next;
	}
	data->map[data->size] = NULL;
	free_cub_list(data->map_fill);
	data->map_fill = NULL;
}

static void	is_open(t_scub *data, int y, int x)
{
	int	len;

	len = (int)ft_strlen(data->map[y]);
	if (data->map[y][x] != '0')
		return ;
	if (x == 0 || y == 0 || y == data->size - 1 || x == len - 2)
		ft_exit("Error\nMap open.", data);
	if ((data->map[y - 1][x] && data->map[y - 1][x] == ' ')
		|| (data->map[y + 1][x] && data->map[y + 1][x] == ' ')
		|| (data->map[y][x - 1] && data->map[y][x - 1] == ' ')
		||  (data->map[y][x + 1] && data->map[y][x + 1] == ' '))
		ft_exit("Error\nMap open.", data);
	return ;
}

void	check_open_map(t_scub *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			is_open(data, y, x);
			x++;
		}
		y++;
	}
}