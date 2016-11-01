/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:44:48 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 15:01:08 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

int		ft_putwstr(wchar_t *str)
{
	int		result;

	result = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
		result += ft_putwchar(*str++);
	return (result);
}
