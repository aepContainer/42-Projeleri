/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:08:21 by apalaz            #+#    #+#             */
/*   Updated: 2023/12/15 16:08:36 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "stdlib.h"
# include "stdarg.h"
# include "unistd.h"

typedef unsigned long	t_ul;
typedef unsigned char	t_uc;
typedef unsigned int	t_ui;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

char	*get_next_line_b(int fd);
char	*get_next_line(int fd);
char	*get_line_wout(char *lwol);
char	*get_line_wol(int fd, char *lwol);
char	*get_buff(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	ctrl_nl(char *str);
t_ui	ft_strlen_gnl(char *str);

int		ft_printf(const char *str, ...);
void	ft_print_perc(va_list arg_list, char perc, int *printed);
void	ft_putchar_arg(char c, int *printed);
void	ft_putnum_addr(t_ul ul, int *printed);
void	ft_putnum_hex_arg(t_ui i, char perc, int *printed);
void	ft_putnum_hex_ul_arg(t_ul ul, int *printed);
void	ft_putnum_sdec_arg(int i, int *printed);
void	ft_putnum_udec_arg(t_ui ui, int *printed);
void	ft_putstr_arg(char *str, int *printed);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s2, char c);
char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(t_ui, char));
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, t_ui start, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(t_ui, char *));
int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif