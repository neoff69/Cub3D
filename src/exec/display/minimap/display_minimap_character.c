/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap_character.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:31:42 by vgonnot           #+#    #+#             */
/*   Updated: 2023/05/31 19:33:39 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	display_minimap_character(t_exec *exec)
{
	int	new_x;
	int	new_y;

	new_x = exec->data.pos_x * SQUARE_SIZE + exec->horizontal_movement;
	new_y = exec->data.pos_y * SQUARE_SIZE + exec->vertical_movement;
	draw_square(new_x, new_y, 0x0000FF, exec);
}
