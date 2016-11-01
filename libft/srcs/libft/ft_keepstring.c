/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keepstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 15:02:55 by jelefebv          #+#    #+#             */
/*   Updated: 2016/03/22 20:00:32 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_keepstring(const char c, char *str)
{
	char	*tmp;

	tmp = ft_chartostr(c);
	str = ft_strjoin(str, tmp);
	ft_strdel(&tmp);
	return (str);
}
