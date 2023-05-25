/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:31:21 by jlaisne           #+#    #+#             */
/*   Updated: 2023/05/25 14:38:05 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_cub_list(t_pcub *lst)
{
	t_pcub	*temp;

	while (lst)
	{
		temp = lst->next;
		if (lst->content)
			free(lst->content);
		if (lst->key)
			free(lst->key);
		free(lst);
		lst = temp;
	}
	free(lst);
}

void	ft_exit(char *info, t_scub *data)
{
	if (data->cub)
		free_cub_list(data->cub);
	printf("%s\n", info);
	close(data->fd);
	free(data);
	exit (1);
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
