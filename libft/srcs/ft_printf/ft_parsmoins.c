/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsmoins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 11:58:39 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 14:58:08 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <string.h>

char	*ft_parsmoins(int *ptr, char *str)
{
	char	*tmp;

	if (str[0] == '-')
	{
		*ptr = 1;
		if (!(tmp = malloc(sizeof(char) * ft_strlen(str))))
			return (NULL);
		str++;
		tmp = ft_strcpy(tmp, str);
		return (tmp);
	}
	else
	{
		*ptr = 0;
		return (str);
	}
}
