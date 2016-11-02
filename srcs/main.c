/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeremy <jeremy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 18:46:58 by jeremy            #+#    #+#             */
/*   Updated: 2016/11/02 12:35:49 by jelefebv         ###   ########.fr       */
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

void	ft_construct_struct(t_lem *lem)
{
	char	flag;
	char	read_str[1024];
	char	*ptr;
	int		r;

	r = 0;
	flag = 0;
	ptr = NULL;
	while ((r = read(1, &read_str, 1024)))
	{
		read_str[r - 1] = '\0';
		ptr = ft_strtrim(read_str);
		if (!ft_strncmp(ptr, "##start", ft_strlen("##start")) && !lem->start)
			lem->start = ft_strdup(ptr);
		else if (!ft_strncmp(ptr, "##end", ft_strlen("##end")) && !lem->end)
			lem->end = ft_strdup(ptr);
		else if (ptr[0] == '#' && ptr[1] != '#')
			continue ;
		else if (flag == 0 && ft_push_back_salle(&(lem->map), ptr) != 0)
			flag = 1;
		if (flag == 1 && ft_push_back_tube(&(lem->tube), ptr) != 0)
			break ;
		free(ptr);
	}
}

int		main(void)
{
	t_lem	lst;

	ft_read_fourmis(&(lst.nb_fourmis));
	lst.map = NULL;
	lst.tube = NULL;
	ft_construct_struct(&lst);
	ft_print_salle(lst.map);
	ft_print_tube(lst.tube);
	return (0);
}
