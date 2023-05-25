/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:16:25 by jlaisne           #+#    #+#             */
/*   Updated: 2023/05/25 15:53:52 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef enum s_type
{
	FILL,
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	SPRITE,
	CODE
}	t_type;

typedef enum s_valid
{
	VALID,
	FALSE
}	t_valid;

typedef struct s_pcub
{
	char			*key;
	char			*content;
	t_valid			arg;
	t_type			type;
	struct s_pcub	*next;
}	t_pcub;

typedef struct s_scub
{
	char	**map;
	t_pcub	*cub;
	int		fd;
}	t_scub;

#endif