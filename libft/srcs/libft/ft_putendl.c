/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:58:34 by jelefebv          #+#    #+#             */
/*   Updated: 2016/03/22 12:01:23 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putendl(char const *s)
{
	int		result;

	result = 0;
	result += ft_putstr((char *)s);
	result += ft_putchar('\n');
	return (result);
}
