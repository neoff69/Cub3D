/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_list_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:41:22 by jlaisne           #+#    #+#             */
/*   Updated: 2023/06/20 10:46:09 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	lst_cmd_add_back(t_pcub **lst, t_pcub *new)
{
	t_pcub	*head;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	head = cmd_lst_last(lst);
	head->next = new;
}

t_pcub	*cmd_lst_last(t_pcub **lst)
{
	t_pcub	*tmp;

	if (!*lst)
		return (NULL);
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_pcub	*new_node_cmd(char *key, char *content, t_type id, t_valid check)
{
	t_pcub	*new;

	new = malloc(sizeof(t_pcub));
	if (!new)
	{
		content = get_next_line(0, 1);
		return (NULL);
	}
	new->key = ft_strdup(key);
	new->content = ft_strdup(content);
	if (!new->content || !new->key)
		return (NULL);
	new->type = id;
	new->arg = check;
	new->next = NULL;
	return (new);
}

int	duplicate_key(t_pcub **lst, t_pcub *node)
{
	t_pcub	*temp;

	temp = *lst;
	while (temp)
	{
		if (temp == node && temp->next)
			temp = temp->next;
		else if (temp == node && !temp->next)
			break ;
		if (temp->type == node->type)
			return (1);
		temp = temp->next;
	}
	node->arg = VALID;
	return (0);
}

t_pcub	*get_node(t_pcub *lst, t_type type)
{
	if (!lst)
		return (NULL);
	while (lst && lst->type != type)
		lst = lst->next;
	if (lst && lst->type == type)
		return (lst);
	else
		return (NULL);
}
