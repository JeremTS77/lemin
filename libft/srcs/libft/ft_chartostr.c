/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 14:59:44 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 14:59:45 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char			*ft_chartostr(const char c)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (0);
	if (c == 0)
		str[0] = '\0';
	else
		str[0] = c;
	str[1] = '\0';
	return (str);
}
