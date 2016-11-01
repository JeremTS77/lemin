/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 14:59:50 by jelefebv          #+#    #+#             */
/*   Updated: 2016/03/22 12:00:38 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_delstr(void)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char))))
		return (NULL);
	tmp[0] = '\0';
	return (tmp);
}
