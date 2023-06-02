/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_deplacement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:52:57 by vgonnot           #+#    #+#             */
/*   Updated: 2023/06/02 15:23:58 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	vertical_movement(t_exec *exec, int keycode, float *x, float *y)
{
	if (keycode == KEY_S)
	{
		*x = ((exec->data.pos_x) * SQUARE_SIZE \
			+ exec->horizontal_movement) / (SQUARE_SIZE);
		*y = ((1 + exec->data.pos_y) * SQUARE_SIZE \
			+ exec->vertical_movement) / (SQUARE_SIZE);
	}
	else
	{
		*x = (exec->data.pos_x * SQUARE_SIZE \
			+ exec->horizontal_movement) / (SQUARE_SIZE);
		*y = (exec->data.pos_y * SQUARE_SIZE \
			+ exec->vertical_movement - 1) / (SQUARE_SIZE);
	}
}

void	horizontal_movement(t_exec *exec, int keycode, float *x, float *y)
{
	if (keycode == KEY_D)
	{
		*x = ((1 + exec->data.pos_x) * SQUARE_SIZE \
			+ exec->horizontal_movement) / (SQUARE_SIZE);
		*y = ((exec->data.pos_y) * SQUARE_SIZE \
			+ exec->vertical_movement) / (SQUARE_SIZE);

		// exec->angle -= 0.1;
		// if (exec->angle < 0)
		// 	exec->angle = 2 * PI;
	}
	else
	{
		*x = (exec->data.pos_x * SQUARE_SIZE \
			+ exec->horizontal_movement - 1) / (SQUARE_SIZE);
		*y = (exec->data.pos_y * SQUARE_SIZE \
			+ exec->vertical_movement) / (SQUARE_SIZE);

		// exec->angle += 0.1;
		// if (exec->angle > 2 * PI)
		// 	exec->angle = 0;
	}
}

int    check_in_map(float x, float y, t_exec *exec, int keycode)
{
    if (exec->data.map[(int)y][(int)x] == '1')
        return (1);
    if (keycode == KEY_A && y != (int)y)
    {
        if (exec->data.map[(int)y + 1][(int)x] == '1')
            return (1);
    }
    else if (keycode == KEY_D && y != (int) y)
    {
        if (exec->data.map[(int)y + 1][(int)x] == '1')
            return (1);
    }
    else if (keycode == KEY_W && x != (int) x)
    {
        if (exec->data.map[(int)y][(int)x + 1] == '1')
            return (1);
    }
    else if (keycode == KEY_S && x != (int) x)
    {
        if (exec->data.map[(int)y][(int)x + 1] == '1')
            return (1);
    }
    return (0);
}

int    check_if_wall(t_exec *exec, int keycode)
{
    float    x;
    float    y;

    x = 0;
    y = 0;
    if (keycode == KEY_S || keycode == KEY_W)
        vertical_movement(exec, keycode, &x, &y);
    else
        horizontal_movement(exec, keycode, &x, &y);
    if (check_in_map(x, y, exec, keycode))
        return (1);
    return (0);
}

void    minimap_deplacement(t_exec *exec, int keycode)
{
    if (keycode == KEY_W && check_if_wall(exec, keycode) == 0)
        exec->vertical_movement -= 10;
    else if (keycode == KEY_S && check_if_wall(exec, keycode) == 0)
        exec->vertical_movement += 10;
    else if (keycode == KEY_D && check_if_wall(exec, keycode) == 0)
        exec->horizontal_movement += 10;
    else if (keycode == KEY_A && check_if_wall(exec, keycode) == 0)
        exec->horizontal_movement -= 10;
    set_image_win(exec);
}
