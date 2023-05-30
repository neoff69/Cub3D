/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:18:38 by jlaisne           #+#    #+#             */
/*   Updated: 2023/05/30 14:41:59 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char				*res;
	unsigned long int	i;
	size_t				len1;
	size_t				len2;

	if (s1 == NULL)
		return ((char *)s2);
	len1 = ft_strlen(s1);
	len2 = len1 + ft_strlen(s2);
	i = -1;
	res = malloc(sizeof(char) * (len2 + 1));
	if (!res)
		return (free((char *)s1), free((char *)s2), NULL);
	while (++i < len1)
		res[i] = s1[i];
	while (i < len2)
	{
		res[i] = s2[i - len1];
		i++;
	}
	res[i] = '\0';
	return (free((char *)s1), free((char *)s2), res);
}

char	*ft_strchar(const char *s, char b)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *) s;
	while (str[i])
	{
		if (str[i] == b)
			return (&str[i + 1]);
		i++;
	}
	return (NULL);
}

char	*error_check(int fd, char *line, char *temp, int error)
{
	if (read(fd, NULL, 0) == -1)
		return (free(temp), NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || !line || error == 1)
		return (free(temp), NULL);
	return (line);
}
