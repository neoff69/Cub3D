/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:24:40 by gclement          #+#    #+#             */
/*   Updated: 2023/06/14 13:28:19 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include "get_next_line_bonus.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void			ft_bzero(void *pointer, size_t n);
void			*ft_calloc( size_t elCount, size_t elSize);
size_t			ft_strlen(const char *str);
char			*ft_strdup( const char *source );
char			*ft_strchr(const char	*string, int searchCh);
char			*ft_strrchr(const char *string, int searchedCh);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
void			*ft_memchr(const void *memBlock, int srchChar, size_t size);
int				ft_tolower(int ch);
int				ft_toupper(int ch);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
void			*ft_memset(void *pointer, int value, size_t count);
void			*ft_memcpy(void *dest, const void *src, size_t size);
void			*ft_memmove(void *dest, const void *src, size_t size);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_isprint(int ch);
int				ft_isdigit(int ch);
int				ft_isascii(int c);
int				ft_isalpha(int ch);
int				ft_isalnum(int ch);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_atoi(const char *str);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
long long		ft_atoll(const char *str);
int				ft_putnbr_base_and_count(va_list args, int type);
int				ft_printf(const char *format, ...);
int				ft_put_unsigned_int(unsigned int nbr, int fd);
int				ft_putstr_and_count(char *s, int fd);
int				ft_putnbr_and_count(int n, int fd);
int				str_isdigit(char *arg);
int				str_isascii(char *arg);
size_t			check_isspace(const char *str);
void			close_all(void);

#endif