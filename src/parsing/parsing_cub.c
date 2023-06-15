/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:04:09 by jlaisne           #+#    #+#             */
/*   Updated: 2023/06/15 09:54:00 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parsing_cub(char **arg, t_scub *data)
{
	data->cub = NULL;
	data->map = NULL;
	data->map_fill = NULL;
	data->first_wall = NULL;
	if (check_arg(arg[1], ".cub") == 1)
	{
		printf("Error\nInvalid map format [%s]: *.cub is required.\n", arg[1]);
		return (1);
	}
	if (open_arg(data, arg[1], 1) == 1)
	{
		printf("Error\nCannot open [%s] map.\n", arg[1]);
		return (1);
	}
	if (get_parameters(data) == 1)
	{
		ft_return("Error\nInvalid parameters in *.cub file.", data);
		return (1);
	}
	
	return (0);
}

int	open_arg(t_scub *data, char *file, int x)
{
	int	fd;

	if (x == 1)
	{
		data->fd = open(file, O_RDONLY);
		if (data->fd < 0)
			return (1);
		return (0);
	}
	else
	{
		fd = open(file, O_RDONLY);
		if (fd < 0)
			return (1);
		return (close (fd), 0);
	}
}

int	check_arg(char *arg, char *filetype)
{
	unsigned int	i;
	unsigned int	j;
	char			*needle;

	i = 0;
	j = 0;
	needle = ft_strdup(filetype);
	if (arg == NULL)
		return (free(needle), 1);
	while (arg[i])
	{
		if (arg[i] == needle[0] && i >= 1)
		{
			j = 0;
			while (needle[j] && (arg[i + j] == needle[j]))
				j++;
			if (needle[j] == '\0' && arg[i + j] == '\0')
				return (free(needle), 0);
		}
		i++;
	}
	return (free(needle), 1);
}
