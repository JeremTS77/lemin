/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:58:24 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 15:01:44 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_fd(int n, int fd)
{
	int		result;

	result = 0;
	if (n == -2147483648)
	{
		return (ft_putstr_fd("-2147483648", fd));
	}
	if (n < 0)
	{
		result += ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n < 10)
		result += ft_putchar_fd('0' + n, fd);
	else
	{
		result += ft_putnbr_fd(n / 10, fd);
		result += ft_putchar_fd('0' + n % 10, fd);
	}
	return (result);
}
