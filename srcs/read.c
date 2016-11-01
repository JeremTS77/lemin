/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeremy <jeremy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 18:46:58 by jeremy            #+#    #+#             */
/*   Updated: 2016/10/29 22:11:23 by jeremy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	char		read_str[1024];
	int			r;
	t_salle		*lst;

	r = 0;
	lst = NULL;
	while ((r = read(1, &read_str, 1024)))
	{
		read_str[r - 1] = '\0';
		if (ft_push_back_salle(&lst, read_str) != 0)
			break ;
	}
	ft_print_salle(lst);
	return (0);
}
