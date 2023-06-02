/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_raytracing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:27:15 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/02 14:35:54 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	display_raytracing(t_exec *exec)
{
	exec->actual_x /= SQUARE_SIZE;
	exec->actual_y /= SQUARE_SIZE;
	draw_line(exec);
}
