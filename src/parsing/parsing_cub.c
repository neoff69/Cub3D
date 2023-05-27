/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juleslaisne <juleslaisne@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:04:09 by jlaisne           #+#    #+#             */
/*   Updated: 2023/05/27 12:12:02 by juleslaisne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int parsing_cub(char **arg)
{
	t_scub	*data;

	data = malloc(sizeof(t_scub));
	if (!data)
		ft_exit("Error malloc.\n", NULL);
	data->cub = NULL;
	data->map = NULL;
	data->map_fill = NULL;
	data->player = FALSE;
	if (check_arg(arg[1], ".cub") == 1)
	{
		printf("Error, Invalid map format [%s]: *.cub is required.\n", arg[1]);
		return (free(data), 1);
	}
	if (open_arg(data, arg[1], 1) == 1)
	{
		printf("cannot open [%s] map.\n", arg[1]);
		return (close(data->fd), free(data), 1);
	}
	if (get_parameters(data) == 1)
	{
		ft_return("Error, Invalid parameters in *.cub file.", data);
		return (1);
	}
	ft_return(NULL, data);
	return (0);
}

int	open_arg(t_scub *data, char *file, int x)
{
	int fd;

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
		return (0);
	}
}
