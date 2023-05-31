/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:16:46 by jlaisne           #+#    #+#             */
/*   Updated: 2023/05/31 12:55:19 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parsing(int argc, char **argv, t_scub *data)
{
	if (argc != 2)
	{
		printf("Please provide one (1) *.cub map.\n");
		return (1);
	}
	if (parsing_cub(argv, data) == 1)
		return (1);
	return (0);
}

int	exec(t_scub *data)
{
	t_exec	exec;

	exec.data = *data;
	exec_cub(&exec);
	return (0);
}

int	main(int argc, char **argv)
{
	t_scub	data;

	if (parsing(argc, argv, &data))
		return (1);
	if (exec(&data))
		return (1);
	return (0);
}
