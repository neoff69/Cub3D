/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap_character.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:31:42 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/12 18:28:54 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	display_minimap_character(t_exec *exec)
{
	exec->actual_x = exec->data.pos_x * SQUARE_SIZE + exec->horizontal_movement;
	exec->actual_y = exec->data.pos_y * SQUARE_SIZE + exec->vertical_movement;
	draw_player(exec->actual_x, exec->actual_y, PLAYER_MINIMAP, exec);
}
