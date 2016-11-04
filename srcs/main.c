/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeremy <jeremy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 18:46:58 by jeremy            #+#    #+#             */
/*   Updated: 2016/11/04 18:19:36 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"
#include "ft_printf.h"

void	ft_rec_command(t_lem *lem, const char *tab, const char *ptr)
{
	char	**str;

	str = ft_strsplit(ft_strtrim(ptr), ' ');
	if (ft_strncmp(tab, "##start", ft_strlen("##start")) == 0 && !lem->start &&
			str[0] && str[1] && str[2] && !str[3])
	{
		lem->start = ft_strtrim(str[0]);
		lem->startx = ft_atoi(str[1]);
		lem->starty = ft_atoi(str[2]);
	}
	else if (!ft_strncmp(tab, "##end", ft_strlen("##end")) && !lem->end &&
			str[0] && str[1] && str[2] && !str[3])
	{
		lem->end = ft_strtrim(str[0]);
		lem->endx = ft_atoi(str[1]);
		lem->endy = ft_atoi(str[2]);
	}
	else
		push_back_command(&(lem->command), tab + 2);
	ft_strstrdel(str);
}

void	ft_construct_struct(t_lem *lem, const char *str, char *ptr)
{
	char	flag;
	char	**tab;
	int		i;

	flag = -1;
	tab = ft_strsplit(str, '\n');
	i = 0;
	while (tab[i])
	{
		ptr = ft_strtrim(tab[i]);
		if (flag == -1 && lem->nb_fourmis <= 0 && ft_atoi(ptr) > 0 &&
				(lem->nb_fourmis = ft_atoi(ptr)))
			flag = 0;
		else if (ptr[0] == '#' && ptr[1] == '#')
			ft_rec_command(lem, tab[i], tab[i + 1]);
		else if (ptr[0] == '#' && ptr[1] != '#')
			push_back_comment(&(lem->comment), ptr + 1);
		else if (flag == 0 && ft_push_back_salle(&(lem->map), ptr) != 0)
			flag = 1;
		if (flag == 1)
			ft_push_back_tube(&(lem->tube), lem->map, ptr);
		free(ptr);
		++i;
	}
}

int		main(void)
{
	char	*str;
	char	*ptr;
	int		r;
	t_lem	lst;

	ptr = NULL;
	lst.nb_fourmis = 0;
	lst.map = NULL;
	lst.tube = NULL;
	lst.comment = NULL;
	lst.command = NULL;
	lst.start = NULL;
	lst.end = NULL;
	str = ft_strnew(1024);
	if ((r = read(0, str, 1024)))
		str[r - 1] = '\0';
	ft_construct_struct(&lst, str, ptr);
	ft_print_lemin(&lst);
	ft_strdel(&str);
	return (0);
}
