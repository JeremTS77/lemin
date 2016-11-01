/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 22:13:04 by jelefebv          #+#    #+#             */
/*   Updated: 2016/03/20 22:25:09 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strupper(const char *str)
{
	char	*strupper;
	int		i;

	i = 0;
	if (!str || !*str)
		return (NULL);
	if (!(strupper = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	while (str[i])
	{
		strupper[i] = ft_toupper(str[i]);
		++i;
	}
	strupper[i] = '\0';
	return (strupper);
}
