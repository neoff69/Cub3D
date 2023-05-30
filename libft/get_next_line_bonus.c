/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:17:53 by jlaisne           #+#    #+#             */
/*   Updated: 2023/05/30 14:43:40 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*copy_buffer(char *oldtemp, char *newtemp)
{
	int	i;

	i = 0;
	while (newtemp && newtemp[i])
	{
		oldtemp[i] = newtemp[i];
		i++;
	}
	oldtemp[i] = '\0';
	return (oldtemp);
}

static int	check_newline(char	*temp)
{
	int	i;

	i = 0;
	if (temp == NULL)
		return (1);
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		return (1);
	return (0);
}

static char	*extract_buffer(char **temp, char *buffer)
{
	char	*str;
	char	*hold;

	str = ft_strdup(buffer);
	hold = *temp;
	*temp = ft_strjoin(hold, str);
	if (!*temp)
		return (NULL);
	return (*temp);
}

char	*extract_line(char **line, char **temp)
{
	int		i;
	int		j;
	int		newl;
	char	*holder;
	char	*str;

	i = 0;
	newl = 0;
	while ((*temp)[i] && (*temp)[i] != '\n')
		i++;
	if ((*temp)[i] == '\n')
		newl = 1;
	holder = (char *)malloc(sizeof(char) * (i + newl + 1));
	if (!holder)
		return (NULL);
	j = -1;
	while (++j < i + newl)
		holder[j] = (*temp)[j];
	holder[j] = '\0';
	*line = ft_strjoin(*line, holder);
	str = *temp;
	*temp = ft_strdup(copy_buffer(str, ft_strchar(*temp, '\n')));
	if ((*line) == NULL || *temp == NULL)
		return (free(str), NULL);
	return (free(str), (*line));
}

char	*get_next_line(int fd, int error)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*temp;
	char		*line;
	int			treated;

	line = ft_strdup("");
	if (error_check(fd, line, temp, error) == NULL)
		return (temp = NULL, buffer[0] = '\0', free(line), NULL);
	treated = 0;
	if (temp)
		treated = check_newline(temp);
	while (treated == 0)
	{
		treated = read(fd, buffer, BUFFER_SIZE);
		if (treated == 0 || treated < 0)
			break ;
		buffer[treated] = '\0';
		temp = extract_buffer(&temp, buffer);
		treated = check_newline(temp);
	}
	if (line && temp && treated >= 0)
		line = extract_line(&line, &temp);
	if (!temp || !line || line[0] == '\0' || treated < 0)
		return (free(temp), buffer[0] = '\0', temp = NULL, free(line), NULL);
	return (line);
}
