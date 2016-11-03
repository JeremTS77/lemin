/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeremy <jeremy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 18:46:58 by jeremy            #+#    #+#             */
/*   Updated: 2016/11/03 07:49:36 by jeremy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"
#include "ft_printf.h"

void	ft_read_fourmis(t_lem *lem)
{
	char	read_str[1024];
	int		r;

	r = 0;
	lem->nb_fourmis = 0;
	while (lem->nb_fourmis <= 0)
	{
		r = read(0, &read_str, 1024);
		read_str[r - 1] = '\0';
		lem->nb_fourmis = ft_atoi(read_str);
	}
}

void	ft_rec_command(t_lem *lem, const char *ptr)
{
	char	read_str[1024];
	char	**str;
	int		r;

	r = 0;
	r = read(0, &read_str, 1024);
	str = ft_strsplit(ft_strtrim(read_str), ' ');
	if (!ft_strncmp(ptr, "##start", ft_strlen("##start")) && !lem->start &&
			str[0] && str[1] && str[2] && !str[3])
	{
		lem->start = ft_strtrim(str[0]);
		lem->startx = ft_atoi(str[1]);
		lem->starty = ft_atoi(str[2]);
	}
	else if (!ft_strncmp(ptr, "##end", ft_strlen("##end")) && !lem->end &&
			str[0] && str[1] && str[2] && !str[3])
	{
		lem->end = ft_strtrim(str[0]);
		lem->endx = ft_atoi(str[1]);
		lem->endy = ft_atoi(str[2]);
	}
	else
		push_back_command(lem->command, ptr + 2);
	ft_strstrdel(str);
}

void	ft_construct_struct(t_lem *lem, const char *str)
{
	char	flag;
	char	**tab;
	char	*ptr;
	int i = 0;

	flag = -1;
	ptr = NULL;
	tab = ft_strsplit(str, '\n');
	while (tab[i])
		ft_printf("%s\n", tab[i++]);
	(void)lem;
//	while (tab[i])
//	{
//		ptr = ft_strtrim(tab[i]);
//		if (flag == -1 && lem->nb_fourmis <= 0 && ft_atoi(ptr) > 0 &&
//				(lem->nb_fourmis = ft_atoi(ptr)))
//			flag = 0;
//		else if (ptr[0] == '#' && ptr[1] == '#')
//			ft_rec_command(lem, ptr);
//		else if (ptr[0] == '#' && ptr[1] != '#')
//			push_back_comment(lem->comment, ptr + 1);
//		else if (flag == 0 && ft_push_back_salle(&(lem->map), ptr) != 0)
//			flag = 1;
//		if (flag == 1 && ft_push_back_tube(&(lem->tube), ptr) != 0)
//			break ;
//		free(ptr);
//		++i;
//	}
}

int		main(void)
{
	char	*str;
	int		r;
	t_lem	lst;

	lst.nb_fourmis = 0;
	lst.map = NULL;
	lst.tube = NULL;
	lst.comment = NULL;
	lst.command = NULL;
	str = ft_strnew(1024);
	if ((r = read(0, str, 1024)))
		str[r - 1] = '\0';
	ft_construct_struct(&lst, str);
//	ft_print_lemin(&lst);
//	ft_print_salle(lst.map);
//	ft_print_tube(lst.tube);
	return (0);
}
