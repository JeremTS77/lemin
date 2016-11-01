/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 16:14:55 by jelefebv          #+#    #+#             */
/*   Updated: 2016/03/20 22:26:57 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <wchar.h>

char	*ft_delstr(void);
char	*ft_chartostr(const char c);
char	*ft_keepstring(const char c, char *str);
char	*ft_keepstring_inv(const char c, char *str);
char	**ft_strsplit(char const *s, char c);
char	*ft_itoa(long long n);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strnew(size_t size);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strrev(char *str);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s);
char	*ft_strupper(const char *str);
char	*ft_strlower(const char *str);
int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_putaddr(void *str);
char	*ft_straddr(void *str);
int		ft_putaddr_fd(void *str, int fd);
int		ft_putchar(char c);
int		ft_putchar_fd(char c, int fd);
int		ft_putendl(char const *s);
int		ft_putendl_fd(char const *s, int fd);
int		ft_putnbr(int n);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr(char const *str);
int		ft_putstr_fd(char const *str, int fd);
int		ft_putstr_len(const char *str, int len);
int		ft_putwstr(wchar_t *str);
int		ft_putwchar(wint_t x);
size_t	ft_strlcat(char *dest, const char *source, size_t size1);
size_t	ft_strlen(const char *str);
void	*ft_memalloc(size_t size);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *s, int c, size_t n);
void	ft_strstrdel(char **del);
void	ft_bzero(void *s, size_t n);
void	ft_memdel(void **ap);
void	ft_strclr(char *s);
void	ft_strdel(char **as);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_clear_string(char *str);
int		ft_nbrlen(int nb);
int		ft_addrlen(void *str);
int		ft_octallen(unsigned int nb);
int		ft_lenwstr(wchar_t *str);
int		ft_lenwchar(wint_t x);
int		ft_strstrlen(char **str);
int		ft_strcchr(const char *str, const char c);

#endif
