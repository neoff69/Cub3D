/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:01:44 by juleslaisne       #+#    #+#             */
/*   Updated: 2023/06/14 14:50:15 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	fill_map_lst(t_scub *data);
char	**fill_map_array(t_scub *data);
void	check_open_map(t_scub *data);

void	fill_map(t_scub *data)
{
	t_pcub	*ptr;

	data->map_fill = NULL;
	data->player_facing = 0;
	ptr = NULL;
	ptr = new_map_node(data->first_wall);
	free(data->first_wall);
	data->first_wall = NULL;
	if (!ptr)
		ft_exit("Error\nMalloc.", data);
	lst_cmd_add_back(&data->map_fill, ptr);
	fill_map_lst(data);
	data->map = fill_map_array(data);
	if (data->player == FALSE)
		ft_exit("Error\nNo player.", data);
	free_cub_list(data->map_fill);
	data->map_fill = NULL;
	check_open_map(data);
}

void	fill_map_lst(t_scub *data)
{
	char	*str;
	t_pcub	*ptr;

	ptr = NULL;
	str = get_next_line(data->fd, 0);
	if (!str)
		ft_exit("Error\nEmpty map.", data);
	ptr = new_map_node(str);
	if (!ptr)
	{
		free(str);
		str = get_next_line(data->fd, 1);
		ft_exit("Error\nMalloc.", data);
	}
	lst_cmd_add_back(&data->map_fill, ptr);
	fill_map_lst_next(str, data);
}

char	**fill_map_array(t_scub *data)
{
	t_pcub	*temp;
	char	**tab;
	int		i;

	data->size = map_lst_size(&data->map_fill);
	if (data->size < 3)
		ft_exit("Error\nMap too small", data);
	tab = ft_calloc((data->size + 1), sizeof(char *));
	if (!tab)
		ft_exit("Error\nMalloc.", data);
	temp = data->map_fill;
	i = 0;
	while (temp)
	{
		tab[i] = ft_strdup(temp->key);
		if (!tab[i])
		{
			free_2d_array(tab);
			ft_exit("Error\nMalloc.", data);
		}
		check_par_map(tab[i], data, tab);
		i++;
		temp = temp->next;
	}
	return (tab[data->size] = NULL, tab);
}

static void	is_open(t_scub *data, int y, int x)
{
	int	len;

	len = (int)ft_strlen(data->map[y]);
	if (data->map[y][x] != '0')
		return ;
	if (x == 0 || y == 0 || y == data->size - 1 || x == len - 2)
		ft_exit("Error\nMap open.", data);
	if (!data->map[y - 1][x] || !data->map[y + 1][x]
		|| !data->map[y][x - 1] || !data->map[y][x + 1])
		ft_exit("Error\nMap open.", data);
	if ((data->map[y - 1][x] && data->map[y - 1][x] == ' ')
		|| (data->map[y + 1][x] && data->map[y + 1][x] == ' ')
		|| (data->map[y][x - 1] && data->map[y][x - 1] == ' ')
		|| (data->map[y][x + 1] && data->map[y][x + 1] == ' '))
		ft_exit("Error\nMap open.", data);
	if (data->map[y - 1][x] == '\n' || data->map[y + 1][x] == '\n'
		|| data->map[y][x - 1] == '\n'|| data->map[y][x + 1] == '\n')
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
			get_position(data, x, y, data->map[y][x]);
			is_open(data, y, x);
			x++;
		}
		y++;
	}
}
