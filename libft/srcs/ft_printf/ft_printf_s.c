/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:40:59 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 14:57:55 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_s(char *str, t_flag *yolo)
{
	int	len;

	len = ft_strlen(str);
	if (!str)
		str = ft_strdup("(null)");
	if (yolo->nbpoint)
		return (ft_strsub(str, 0, (yolo->nbpoint > len) ? len : yolo->nbpoint));
	return (str);
}
