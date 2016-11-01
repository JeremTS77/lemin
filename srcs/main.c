/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeremy <jeremy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 18:46:58 by jeremy            #+#    #+#             */
/*   Updated: 2016/11/01 22:48:02 by jeremy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "ft_printf.h"

void	ft_read_fourmis(unsigned int *nb)
{
	char	read_str[1024];
	int		r;

	r = 0;
	ft_printf("Fourmis nb : \n");
	*nb = 0;
	while (*nb <= 0)
	{
		r = read(1, &read_str, 1024);
		read_str[r - 1] = '\0';
		*nb = ft_atoi(read_str);
	}
	ft_printf("Fourmis nb : %d\n", *nb);
}

int		main(void)
{
	char	read_str[1024];
	char	flag;
	int		r;
	t_lem	lst;

	r = 0;
	flag = 0;
	ft_read_fourmis(&(lst.nb_fourmis));
	lst.map = NULL;
	lst.tube = NULL;
	while ((r = read(1, &read_str, 1024)))
	{
		read_str[r - 1] = '\0';
		if (flag == 0 && ft_push_back_salle(&(lst.map), read_str) != 0)
			flag = 1;
		if (flag == 1)
			break ;
	}
	ft_print_salle(lst.map);
	return (0);
}
