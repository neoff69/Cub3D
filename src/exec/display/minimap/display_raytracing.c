/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_raytracing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:27:15 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/02 10:55:08 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// static void	get_next_wall(t_exec *exec, int *next_x, int *next_y)
// {
// 	while (exec->data.map[*next_y][*next_x] != '1' )
// 	{
// 		*next_y -= 1;
// 	}
// }

void	display_raytracing(t_exec *exec)
{


	exec->actual_x /= SQUARE_SIZE;
	exec->actual_y /= SQUARE_SIZE;
	//get_next_wall(exec, &next_x, &next_y);
	draw_line(exec);
}
