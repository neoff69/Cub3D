/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parameters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:51:39 by jlaisne           #+#    #+#             */
/*   Updated: 2023/05/30 14:48:13 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int check_for_parameters(t_pcub *lst);
int	find_map(t_scub *data);
int	fill_line_lst(char *str, char **temp, t_scub *data);

int	get_parameters(t_scub *data)
{
	int	res;

	res = 0;
	data->first_wall = NULL;
	while (res == 0)
		res = find_map(data);
	analyse_parameters(data);
	fill_map(data);
	if (check_for_parameters(data->cub) == 0)
		return (0);
	if (res == 1 && check_for_parameters(data->cub) == 1)
		return (1);
	return (0);
}

int	check_for_parameters(t_pcub *lst)
{
	t_pcub	*temp;

	temp = lst;
	while (temp)
	{
		if (temp->arg != VALID)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	find_map(t_scub *data)
{
	char	*str;
	char	**temp;

	str = get_next_line(data->fd, 0);
	if (!str)
		ft_exit("Error\nNo map.", data);
	data->first_wall = ft_strdup(str);
	if (!data->first_wall)
		return (free(str), 1);
	temp = ft_split(str, ' ');
	if (!temp)
	{
		free(str);
		str = get_next_line(data->fd, 1);
		ft_exit("Error\nmalloc.", data);
	}
	if (str[0] == '\n')
		return (free(data->first_wall), free(str), free_2d_array(temp), 0);
	free(str);
	if (fill_line_lst(str, temp, data) == 1)
		return (1);
	free(data->first_wall);
	return (0);
}

static int	has_walls(char *temp)
{
	size_t	index;

	index = check_isspace(temp);
	if (temp[index] == '1' || temp[index] == '0')
		return(1);
	return (0);
}

int	fill_line_lst(char *str, char **temp, t_scub *data)
{
	char	**cpy;
	t_pcub	*ptr;

	ptr = NULL;
	if (has_walls(temp[0]))
		return (free_2d_array(temp), 1);
	if ((temp[0] && !temp[1]) || temp[2])
	{
		free_2d_array(temp);
		str = get_next_line(data->fd, 1);
		free(str);
		ft_exit("Error\nWrong format.", data);
	}
	cpy = ft_split(temp[1], '\n');
	if (!cpy)
		return (free_2d_array(temp), 1);
	ptr = new_node_cmd(temp[0], cpy[0], FILL, FALSE);
	free_2d_array(cpy);
	free_2d_array(temp);
	if (!ptr)
		ft_exit("Error\nmalloc.", data);
	lst_cmd_add_back(&data->cub, ptr);
	return (0);
}
