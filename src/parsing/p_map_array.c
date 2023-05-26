/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juleslaisne <juleslaisne@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:01:44 by juleslaisne       #+#    #+#             */
/*   Updated: 2023/05/26 17:24:03 by juleslaisne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	fill_map_lst(t_scub *data);
void	fill_map_array(t_scub *data);

void	fill_map(t_scub *data)
{
    t_pcub	*ptr;

	ptr = new_map_node(data->first_wall);
	if (!ptr)
		ft_exit("Error malloc.", data);
	lst_cmd_add_back(&data->map_fill, ptr);
	fill_map_lst(data);
	fill_map_array(data);
}

void	fill_map_lst(t_scub *data)
{
    char	*str;
	t_pcub	*ptr;
	
	str = get_next_line(data->fd);
	if (!str)
		ft_exit("Empty map.", data);
	ptr = new_map_node(str);
	if (!ptr)
		ft_exit("Error malloc.", data);
	lst_cmd_add_back(&data->map_fill, ptr);
	while (str)
	{
		free(str);
		str = get_next_line(data->fd);
		if (!str)
			break ;
		ptr = new_map_node(str);
		if (!ptr)
			ft_exit("Error malloc.", data);
		lst_cmd_add_back(&data->map_fill, ptr);
	}
}

void	fill_map_array(t_scub *data)
{
	size_t	size;
	t_pcub	*temp;

	size = map_lst_size(&data->map_fill);
	if (size < 3)
		ft_exit("Map too small", data);
	data->map = malloc(sizeof(char *) * (size + 1));
	if (!data->map)
		ft_exit("Error malloc.", data);
	temp = data->map_fill;
	size = 0;
	while (temp)
	{
		data->map[size] = ft_strdup(temp->key);
		check_par_map(data->map[size], data);
		size++;
		temp = temp->next;
	}
	data->map[size] = NULL;
	free_cub_list(data->map_fill);
	data->map_fill = NULL;
}
