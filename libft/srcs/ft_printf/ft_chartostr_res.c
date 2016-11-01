/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostr_res.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 14:55:00 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 14:57:24 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char			*ft_chartostr_res(const char c, int *result, t_flag *list)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (0);
	if (c == 0)
	{
		str[0] = '\0';
		list->cnull = 1;
		if (list->nbchar == 0 && list->nbpoint == 0 && list->point == 1)
			*result = *result;
		else
			*result += 1;
	}
	else
		str[0] = c;
	str[1] = '\0';
	return (str);
}
