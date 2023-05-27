/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juleslaisne <juleslaisne@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:09:16 by juleslaisne       #+#    #+#             */
/*   Updated: 2023/05/27 10:54:19 by juleslaisne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int check_char(char c)
{
    if ((c > 9 && c < 13) || c == 'N' || c == 'W' || c == 'E'
        || c == 'S' || c == '1' || c == '0' || c == ' ')
        return (0);
    return (1);
}

void	check_player(t_scub *data, char c, int y, int x)
{
	if (data->player == VALID 
		&& (c == 'N' || c == 'W' || c == 'E' || c == 'S'))
		ft_exit("Multiple player POS", data);
	data->pos_x = y;
	data->pos_y = x;
	if (c == 'N')
	{	
		data->player_facing = N;
		data->player = VALID;
	}
	if (c == 'S')
	{
		data->player_facing = S;
		data->player = VALID;
		
	}
	if (c == 'W')
	{
		data->player_facing = W;
		data->player = VALID;	
	}
	if (c == 'E')
	{
		data->player_facing = E;
		data->player = VALID;
	}
}

void	check_par_map(char *str, t_scub *data, int row)
{
	int	index;

    index = 0;
    if (str[index] == '\n')
		ft_exit("Empty line in the map.", data);
	index = check_isspace(str);
    if (str[index] == '\n' || str[index] == '\0')
		ft_exit("Empty line in the map.", data);
	while (str[index])
	{
		if (check_char(str[index]))
			ft_exit("Invalid Character", data);
		check_player(data, str[index], index, row);
		index++;
	}
}