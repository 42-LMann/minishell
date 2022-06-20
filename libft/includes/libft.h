/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:55:38 by lmann             #+#    #+#             */
/*   Updated: 2022/04/29 15:35:19 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* -----HEADERS-----*/
/* LIBFT HEADERS */

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

/* PRINTF HEADERS */

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

/* GNL HEADERS */

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

/* -----DEFINES----- */
/* GNL Defines */

# define BUFFER_SIZE 100

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

void	*ft_memset(void *str, int c, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *src, int c, size_t n);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int C);
int		ft_isalnum(int dc);
int		ft_isdigit(int d);
int		ft_isascii(int x);
int		ft_isprint(int pr);
int		ft_toupper(int c);
int		ft_tolower(int c);

//-------Additional Functions--------//

char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *str, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

//--------Printf Functions------------//

typedef struct s_printf
{
	va_list		args;
	int			t_len;
}				t_printf;

int		ft_printf(const char *format, ...);
void	ft_eval_conversion(t_printf *tab, char character);
char	*ft_nbrlen(unsigned long nbr, int *len);
void	ft_hex(t_printf *tab, char character);
void	ft_unint(t_printf *tab, char character);
void	ft_charstr(t_printf *tab, char character);
void	ft_put_unsign_nbr_fd(unsigned int nbr, int fd);
void	ft_nbrcount(t_printf *tab, long n);

//--------GNL Functions----------------//

char	*get_next_line(int fd);
void	ft_free_rest(char *mem, int read_val);
int		ft_get_buffer(int fd, char *buf, int buf_size);

//--------UTIL Functions---------------//

void	ft_free_array(void **array);

#endif
