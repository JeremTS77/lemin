/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeremy <jeremy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 18:46:58 by jeremy            #+#    #+#             */
/*   Updated: 2016/11/10 12:41:14 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "lemin.h"
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

void	ft_rec_command(t_lem *lem, const char *tab, const char *ptr, char *flag)
{
	char	*tmp;
	char	**str;

	tmp = ft_strtrim(ptr);
	str = ft_strsplit(tmp, ' ');
	ft_strdel(&tmp);
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
	int fd = open("map/map.map", O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		if (flag == -2)
			ft_rec_command(lem, ptr, str, &flag);
		ft_strdel(&ptr);
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
		ft_strdel(&str);
	}
}

void	ft_clear_struct(t_lem *lem)
{
	ft_strdel(&lem->start);
	ft_strdel(&lem->end);
	ft_clear_tube(&lem->tube);
	ft_clear_salle(&lem->map);
	ft_clear_command(&lem->command);
	ft_clear_comment(&lem->comment);
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
	ft_mark_room(lst.end, lst.tube, lst.map, ft_compte_room(lst.map));
	ft_print_lemin(&lst);
	ft_clear_struct(&lst);
	return (0);
}
