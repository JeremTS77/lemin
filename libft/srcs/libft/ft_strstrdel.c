/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 09:19:48 by jelefebv          #+#    #+#             */
/*   Updated: 2015/07/22 09:53:47 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

void	ft_strstrdel(char **del)
{
	int		i;

	i = 0;
	while (del[i])
	{
		ft_strdel(&del[i]);
		++i;
	}
	free(*del);
	free(del);
	del = NULL;
}
