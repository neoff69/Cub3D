/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juleslaisne <juleslaisne@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:23:45 by juleslaisne       #+#    #+#             */
/*   Updated: 2023/05/26 17:03:03 by juleslaisne      ###   ########.fr       */
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
    size_t  size;
    t_pcub  *temp;

    temp = *lst;
    size = 0;
    while (temp)
    {
        temp = temp->next;
        size++;
    }
    return (size);
}