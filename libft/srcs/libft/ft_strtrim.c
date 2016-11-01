/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:46:37 by jelefebv          #+#    #+#             */
/*   Updated: 2015/01/26 23:09:51 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_strlen_trim(char const *s)
{
	int		index;
	int		n;

	index = 0;
	n = 0;
	while ((s[index] != '\0') &&
			((s[index] == ' ') || (s[index] == '\n') || (s[index] == '\t')))
		index++;
	n = ft_strlen((char *)s);
	if ((s[n - 1] == ' ') || (s[n - 1] == '\n') ||
			(s[n - 1] == '\t') || (s[n - 1] == '\n'))
		n--;
	while ((n > 0) && ((s[n] == ' ') || (s[n] == '\n') || (s[n] == '\t')))
		n--;
	if (n > 0)
		return (n - index);
	return (0);
}

char	*ft_strtrim(char const *s)
{
	int		index;

	index = 0;
	if (s != NULL)
	{
		while ((s[index] != '\0') &&
				((s[index] == ' ') || (s[index] == '\n') || (s[index] == '\t')))
			index++;
		return (ft_strsub(s, index, ft_strlen_trim(s) + 1));
	}
	return (NULL);
}
