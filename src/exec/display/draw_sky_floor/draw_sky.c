/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:11:46 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/06 14:38:39 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_sky(t_exec *exec)
{
	t_pcub	*temp;
	char	*sky;

	temp = get_node(exec->data.cub, C);
	sky = temp->content;
}
