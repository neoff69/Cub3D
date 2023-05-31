/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:04:14 by jlaisne           #+#    #+#             */
/*   Updated: 2023/05/31 11:05:24 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int    exec_cub(void)
{
    void    *mlx;
    void    *mlx_win;

    (void)mlx_win;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "A simple window");
    mlx_loop(mlx);
    printf("All Good\n");
    return (0);
}
