/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:56:01 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 15:00:15 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (dest == 0)
		return (NULL);
	return (ft_strcpy(dest, str));
}
