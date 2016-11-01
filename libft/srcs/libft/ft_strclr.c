/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:22:44 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 15:00:35 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_strclr(char *s)
{
	int		index;

	index = 0;
	if (s != NULL)
	{
		while (s[index] != '\0')
		{
			s[index] = '\0';
			index++;
		}
		s[index] = '\0';
	}
}
