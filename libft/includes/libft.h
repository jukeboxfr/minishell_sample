/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:16:51 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/10 18:57:03 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

char			*ft_strndup(const char *s, int size);
int				ft_str_r_alpha_cmp(char *s1, char *s2);
int				ft_str_alpha_cmp(char *s1, char *s2);
int				ft_strindex(char *str, char c);
void			ft_putnstr(char const *s, int length);
char			*ft_strreplace(char *str, const char c, const char new_c);
char			*ft_itoa(int n);
void			ft_strdel(char **as);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strtrim(char const *s);
void			ft_putchar(char c);
void			ft_putstr(char const *str);
void			ft_bzero(void *s, size_t n);
int				ft_atoi(const char *nptr);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_memdel(void **ap);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putstr_fd(char const *s, int fd);
char			*ft_strncat(char *dest, const char *src, size_t n);
void			ft_strclr(char *s);
char			*ft_strrchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strequ(char const *s1, char const *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strchr(const char *s, int c);
char			**ft_strsplit(char const *s, char c);
char			**ft_sstrsplit(char const *s, char *search);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strrchr(const char *s, int c);
char			*ft_strccpy(char *dest, const char *str, const char delimiter);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstpop(t_list *lst);
int				ft_lstsome(t_list *lst, int (*f)(t_list	*elem));
t_list			*ft_lstfind(t_list *lst, int (*f)(t_list *elem));
int				ft_lstevery(t_list *lst, int (*f)(t_list	*elem));
int				ft_lstcount(t_list *lst);
int				ft_strcasecmp(char *s1, char *s2);

#endif
