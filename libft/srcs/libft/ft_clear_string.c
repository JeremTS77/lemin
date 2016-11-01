/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 09:16:47 by jelefebv          #+#    #+#             */
/*   Updated: 2015/07/22 09:49:16 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_clear_string(char *tmp)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_strdup(tmp);
	while (str[i] == ' ' || str[i] == '\t')
		++i;
	while (str[i])
	{
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			str[j++] = str[i++];
		while (str[i] == ' ' || str[i] == '\t')
			++i;
		if (str[i])
			str[j++] = ' ';
	}
	str[j] = '\0';
	tmp = ft_strcpy(tmp, str);
	ft_strdel(&str);
}
