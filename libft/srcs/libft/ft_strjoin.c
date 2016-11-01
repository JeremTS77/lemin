/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 10:10:26 by jelefebv          #+#    #+#             */
/*   Updated: 2014/12/29 17:47:51 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	lens2;
	char			*a;
	unsigned int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens2 = ft_strlen(s2);
	a = (char *)malloc(ft_strlen(s1) + lens2 + 1);
	if (a == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		a[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < lens2)
	{
		a[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	a[lens2 + ft_strlen(s1)] = '\0';
	return (a);
}
