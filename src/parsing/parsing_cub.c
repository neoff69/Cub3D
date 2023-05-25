/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:04:09 by jlaisne           #+#    #+#             */
/*   Updated: 2023/05/25 15:53:43 by jlaisne          ###   ########.fr       */
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
	if (check_arg(arg[1], ".cub") == 1)
	{
		printf("Invalid map format [%s]: *.cub is required.\n", arg[1]);
		return (1);
	}
	if (open_arg(data, arg[1], 1) == 1)
	{
		printf("cannot open [%s] map.\n", arg[1]);
		return (1);
	}
	if (get_parameters(data) == 1)
	{
		close(data->fd);
		if (data->cub)
			free_cub_list(data->cub);
		free(data);
		printf("Invalid parameters in *.cub file.\n");
		return (1);
	}
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
