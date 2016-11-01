/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 14:45:52 by jelefebv          #+#    #+#             */
/*   Updated: 2016/03/22 12:04:01 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "libft.h"

int		ft_lenwstr(wchar_t *str)
{
	int		result;

	result = 0;
	while (*str)
		result += ft_lenwchar(*str++);
	return (result);
}
