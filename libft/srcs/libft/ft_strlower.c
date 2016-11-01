/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 22:25:40 by jelefebv          #+#    #+#             */
/*   Updated: 2016/03/20 22:26:37 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strlower(const char *str)
{
	char	*strlower;
	int		i;

	i = 0;
	if (!str || !*str)
		return (NULL);
	if (!(strlower = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	while (str[i])
	{
		strlower[i] = ft_tolower(str[i]);
		++i;
	}
	strlower[i] = '\0';
	return (strlower);
}
