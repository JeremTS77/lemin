/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keepstring_inv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:52:34 by jelefebv          #+#    #+#             */
/*   Updated: 2016/03/22 12:04:18 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_keepstring_inv(const char c, char *str)
{
	str = ft_strjoin(ft_chartostr(c), str);
	return (str);
}
