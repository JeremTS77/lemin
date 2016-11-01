/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 15:07:01 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/27 16:14:20 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libft.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <wchar.h>

typedef struct	s_flag
{
	int			hash;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			point;
	int			index;
	int			l;
	int			h;
	int			j;
	int			z;
	int			tmp;
	int			nbchar;
	int			nbpoint;
	int			cnull;
	int			null;
	char		c;
	char		*string;
	const char	*format;
}				t_flag;

char			*ft_chartostr_res(const char c, int *result, t_flag *list);
char			*ft_check_x(va_list *ap, t_flag *flag);
char			*ft_check_x_bis(va_list *ap, t_flag *flag);
char			*ft_check_x_quater(va_list *ap, t_flag *flag);
char			*ft_check_x_ter(va_list *ap, t_flag *flag);
char			*ft_checkarg(va_list *ap, t_flag *flag);
char			*ft_checkarg_bis(va_list *ap, t_flag *flag);
char			*ft_checkarg_quater(va_list *ap, t_flag *flag);
char			*ft_checkarg_ter(va_list *ap, t_flag *flag);
char			*ft_itoa_ull(unsigned long long n);
int				ft_parsing(t_flag *list);
char			*ft_parsmoins(int *ptr, char *str);
char			*ft_printf_o(unsigned int nb);
char			*ft_printf_o_maj(long unsigned int nb);
char			*ft_printf_s(char *str, t_flag *yolo);
char			*ft_puthhnbr(signed char n);
char			*ft_puthho(unsigned char nb);
char			*ft_puthhx(unsigned char nb);
char			*ft_puthhx_maj(unsigned char nb);
char			*ft_puthhx_maj(unsigned char nb);
char			*ft_puthnbr(short n);
char			*ft_putho(unsigned short nb);
char			*ft_puthx(unsigned short nb);
char			*ft_puthx_maj(unsigned short nb);
char			*ft_puthx_maj(unsigned short nb);
char			*ft_putjd(intmax_t n);
char			*ft_putjo(uintmax_t nb);
char			*ft_putju(uintmax_t n);
char			*ft_putjx(uintmax_t nb);
char			*ft_putjx_maj(uintmax_t nb);
char			*ft_putjx_maj(uintmax_t nb);
char			*ft_putllnbr(long long n);
char			*ft_putllo(unsigned long long nb);
char			*ft_putllx(unsigned long long nb);
char			*ft_putllx_maj(unsigned long long nb);
char			*ft_putllx_maj(unsigned long long nb);
char			*ft_putlnbr(long n);
char			*ft_putlo(unsigned long nb);
char			*ft_putlx(unsigned long nb);
char			*ft_putlx_maj(unsigned long nb);
char			*ft_putlx_maj(unsigned long nb);
char			*ft_putu(unsigned int n);
char			*ft_putuhhnbr(unsigned char n);
char			*ft_putuhnbr(unsigned short n);
char			*ft_putullnbr(unsigned long long n);
char			*ft_putulnbr(unsigned long n);
char			*ft_putuz(size_t n);
char			*ft_putx(unsigned int nb);
char			*ft_putx_maj(unsigned int nb);
char			*ft_putzx(size_t nb);
char			*ft_putzx_maj(size_t nb);
char			*ft_straddr(void *str);
int				ft_glhf(t_flag *list, int nb);
int				ft_glhfmin(t_flag *list, int nb);
int				ft_opt_all(int nbr, int isneg, t_flag *list, char c);
void			ft_opt_all_bis(int *nbr, int isneg, t_flag *list, char c);
int				ft_opt_hash(t_flag *list, char c);
int				ft_opt_minus(t_flag *list, int nb);
int				ft_opt_plus(int isneg, t_flag *list);
int				ft_opt_point_nbr(int nb, t_flag *list, int isneg);
int				ft_opt_point_adr(int nb, t_flag *list);
int				ft_opt_point_null(t_flag *list, char c);
int				ft_opt_point_null_bis(t_flag *list, char c, int i);
int				ft_opt_space(int isneg, t_flag *list);
int				ft_opt_zero(t_flag *list, int nb, int isneg, char c);
int				ft_printf(const char *format, ...);
int				ft_printf_n(int *nb, int result);
int				ft_trimprintf(t_flag *flag, va_list *ap);
int				us_printf(const char *format, int result, va_list *ap);
t_flag			*ft_put_in_string(t_flag *list, va_list *ap);
void			ft_init_flag(t_flag *list, const char *format);
void			ft_parse_point(t_flag *flagprintf, const char *str);
void			ft_parseflag(t_flag *flagprintf);
char			*ft_checkz(va_list *ap, t_flag *flag);
char			*ft_checkj(va_list *ap, t_flag *flag);
char			*ft_putzo(size_t nb);
char			*ft_putznbr(ssize_t n);
int				ft_check_null(char c, va_list ap);
int				ft_wspace(t_flag *flag, int len);
int				ft_wflag(t_flag *flag, wchar_t *str);
int				ft_wzero(t_flag *flag, int len);
int				ft_wflag_bis(t_flag *flag, wchar_t *str);
int				ft_s_opt(t_flag *flag, va_list *ap);
void			ft_parsflag_bis(t_flag *flagprintf, const char *s);
int				ft_wflag_ter(t_flag *flag, wchar_t *str);

#endif
