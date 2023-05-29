/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juleslaisne <juleslaisne@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:09:16 by juleslaisne       #+#    #+#             */
/*   Updated: 2023/05/29 14:48:39 by juleslaisne      ###   ########.fr       */
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

void	get_position(t_scub *data, int x, int y, char c)
{
	int	len;

	if (c != 'N' && c != 'W' && c != 'E' && c != 'S')
		return ;
	data->pos_x = x;
	data->pos_y = y;
	len = (int)ft_strlen(data->map[y]);
	if (x == 0 || y == 0 || y == data->size - 1 || x == len - 2)
		ft_exit("Error\nPlayer is out of bounds.", data);
	if ((data->map[y - 1][x] && data->map[y - 1][x] == ' ')
		|| (data->map[y + 1][x] && data->map[y + 1][x] == ' ')
		|| (data->map[y][x - 1] && data->map[y][x - 1] == ' ')
		||  (data->map[y][x + 1] && data->map[y][x + 1] == ' '))
		ft_exit("Error\nPlayer is out of bounds.", data);
}

static void	check_valid(t_scub *data)
{
	if (data->player_facing >= 7 && data->player_facing <= 10)
		data->player = VALID;
}

static void	check_player(t_scub *data, char c)
{
	if (data->player == VALID 
		&& (c == 'N' || c == 'W' || c == 'E' || c == 'S'))
		ft_exit("Error\nMultiple player POS", data);
	if (c == 'N')	
		data->player_facing = N;
	if (c == 'S')
		data->player_facing = S;
	if (c == 'W')
		data->player_facing = W;
	if (c == 'E')
		data->player_facing = E;
}

void	check_par_map(char *str, t_scub *data)
{
	int	index;

    index = 0;
	data->player = FALSE;
    if (str[index] == '\n')
		ft_exit("Error\nEmpty line in the map.", data);
	index = check_isspace(str);
    if (str[index] == '\n' || str[index] == '\0')
		ft_exit("Error\nEmpty line in the map.", data);
	while (str[index])
	{
		if (check_char(str[index]))
			ft_exit("Error\nInvalid Character", data);
		check_player(data, str[index]);
		check_valid(data);
		index++;
	}	
}
