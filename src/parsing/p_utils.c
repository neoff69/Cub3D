/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:09:16 by juleslaisne       #+#    #+#             */
/*   Updated: 2023/05/31 10:14:00 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_char(char c)
{
	if ((c > 9 && c < 13) || c == 'N' || c == 'W' || c == 'E'
		|| c == 'S' || c == '1' || c == '0' || c == ' ')
		return (0);
	return (1);
}

static void	check_valid(t_scub *data)
{
	if (data->player_facing >= 7 && data->player_facing <= 10)
		data->player = VALID;
}

static void	check_player(t_scub *data, char c, char **map)
{
	if (data->player == VALID
		&& (c == 'N' || c == 'W' || c == 'E' || c == 'S'))
	{
		free_2d_array(map);
		ft_exit("Error\nMultiple player POS", data);
	}
	if (c == 'N')
		data->player_facing = N;
	if (c == 'S')
		data->player_facing = S;
	if (c == 'W')
		data->player_facing = W;
	if (c == 'E')
		data->player_facing = E;
}

void	check_str_wall(char *str, int index, char **map, t_scub *data)
{
	while (str[index])
	{
		if (check_char(str[index]))
		{
			free_2d_array(map);
			ft_exit("Error\nInvalid Character", data);
		}
		check_player(data, str[index], map);
		check_valid(data);
		index++;
	}
}

void	check_par_map(char *str, t_scub *data, char **map)
{
	int	index;

	index = 0;
	data->player = FALSE;
	if (str[index] == '\n')
	{
		free_2d_array(map);
		ft_exit("Error\nEmpty line in the map.", data);
	}
	index = check_isspace(str);
	if (str[index] == '\n' || str[index] == '\0')
	{
		free_2d_array(map);
		ft_exit("Error\nEmpty line in the map.", data);
	}
	check_str_wall(str, index, map, data);
}
