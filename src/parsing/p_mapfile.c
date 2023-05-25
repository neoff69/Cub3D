/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_mapfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:50:54 by jlaisne           #+#    #+#             */
/*   Updated: 2023/05/25 15:22:23 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
