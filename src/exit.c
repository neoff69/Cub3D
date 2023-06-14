/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:31:21 by jlaisne           #+#    #+#             */
/*   Updated: 2023/06/14 11:00:28 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_cub_list(t_pcub *lst)
{
	t_pcub	*temp;

	while (lst)
	{
		temp = lst->next;
		if (lst->key)
			free(lst->key);
		if (lst->content)
			free(lst->content);
		free(lst);
		lst = temp;
	}
	free(lst);
}

void	ft_exit(char *info, t_scub *data)
{
	if (info)
		printf("%s\n", info);
	if (data)
	{
		if (data->first_wall)
			free(data->first_wall);
		if (data->cub)
			free_cub_list(data->cub);
		if (data->map_fill)
			free_cub_list(data->map_fill);
		if (data->map)
			free_2d_array(data->map);
		if (data->fd != -1)
			close(data->fd);
	}
	exit (1);
}

void	ft_return(char *info, t_scub *data)
{
	if (data->first_wall)
		free(data->first_wall);
	if (data->cub)
		free_cub_list(data->cub);
	if (data->map_fill)
		free_cub_list(data->map_fill);
	if (data->map)
		free_2d_array(data->map);
	if (info)
		printf("%s\n", info);
	if (data->fd != -1)
		close(data->fd);
}

void	*free_2d_array(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}
