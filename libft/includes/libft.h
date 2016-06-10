/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotfas <mcotfas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:43:34 by mcotfas           #+#    #+#             */
/*   Updated: 2016/06/10 10:56:41 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 4096
# define FD_MAX 1000
# define TRUE 1
# define FALSE 0
# define BOOL	int
# define BASE_CAP "0123456789ABCDEF"
# define BASE_MIN "0123456789abcdef"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_mem
{
	char			*buff;
	char			*line;
	int				error;
	int				end;
	int				end_read;
	int				has_line;
}					t_mem;

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr(ssize_t n);
void				ft_putnbr_fd(ssize_t n, int fd);
size_t				ft_strlen(char const *s);
char				*ft_strcpy(char *dst, char const *src);
char				*ft_strncpy(char *dst, char const *src, size_t n);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
int					ft_strcmp(char const *s1, char const *s2);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strstr(char const *s1, char const *s2);
char				*ft_strnstr(char const *s1, char const *s2, size_t n);
char				*ft_strdup(char const *s1);
char				*ft_strchr(char const *s, ssize_t c);
char				*ft_strrchr(char const *s, ssize_t c);
int					ft_isdigit(ssize_t c);
int					ft_isalpha(ssize_t c);
int					ft_isalnum(ssize_t c);
int					ft_isascii(ssize_t c);
int					ft_isprint(ssize_t c);
int					ft_toupper(ssize_t c);
int					ft_tolower(ssize_t c);
int					ft_isnumeric(char *str);
void				*ft_memset(void *b, ssize_t c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, void const *src, size_t n);
void				*ft_memccpy(void *dst, void const *src, ssize_t c,
								size_t n);
void				*ft_memmove(void *dst, void const *src, size_t n);
void				*ft_memchr(void const *s, ssize_t c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
char				*ft_strcat(char *s1, char const *s2);
char				*ft_strncat(char *s1, char const *s2, size_t n);
size_t				ft_strlcat(char *dst, char const *src, size_t size);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(size_t, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char *s1, char *s2);
char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, size_t start, size_t len);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(ssize_t n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(size_t, char));
ssize_t				ft_atoi(char const *str);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_isspace(char c);
size_t				ft_absvalue(ssize_t n);
t_list				*ft_lstaddend(t_list *alst, t_list *new);
t_list				*ft_lstsplit(char const *s, char c);
t_list				*ft_lstback(t_list *alst, t_list *link);
char				*ft_itoa_base(ssize_t n, size_t b, char base[16]);
char				*ft_itoa_base_u(size_t n, size_t b, char base[16]);
size_t				ft_bin_to_dec(char *bin);
char				*ft_charstr(char c);
int					ft_str_is_int(char *str);

int					get_next_line(int const fd, char **line);

#endif
