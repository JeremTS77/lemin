/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeremy <jeremy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 18:46:58 by jeremy            #+#    #+#             */
/*   Updated: 2016/11/07 18:09:15 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"
#include "ft_printf.h"

#include <fcntl.h>
#include "get_next_line.h"

void	ft_rec_command(t_lem *lem, const char *tab, const char *ptr, char *flag)
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
	*flag = 0;
}

void	ft_construct_struct(t_lem *lem)
{
	char	flag;
	char	*str;
	char	*ptr;

	flag = -1;
	str = NULL;
	ptr = NULL;
	while (get_next_line(0, &str) > 0)
	{
		if (flag == -2)
			ft_rec_command(lem, ptr, str, &flag);
		flag = (ft_strncmp(str, "##", ft_strlen("##")) == 0 &&
				(ptr = ft_strdup(str))) ? -2 : flag;
		if (flag == -1 && lem->nb_fourmis <= 0 && ft_atoi(str) > 0 &&
				(lem->nb_fourmis = ft_atoi(str)))
			flag = 0;
		else if (str[0] == '#' && str[1] != '#')
			push_back_comment(&(lem->comment), str + 1);
		else if (flag == 0 && ft_push_back_salle(&(lem->map), str) != 0)
			flag = 1;
		if (flag == 1)
			ft_push_back_tube(&(lem->tube), lem->map, str);
	}
}

int		main(void)
{
	t_lem	lst;

	lst.nb_fourmis = 0;
	lst.map = NULL;
	lst.tube = NULL;
	lst.comment = NULL;
	lst.command = NULL;
	lst.start = NULL;
	lst.end = NULL;
	ft_construct_struct(&lst);
	ft_print_lemin(&lst);
	return (0);
}
