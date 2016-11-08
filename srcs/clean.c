/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:57:41 by jelefebv          #+#    #+#             */
/*   Updated: 2016/11/08 18:22:37 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

void	ft_clear_tube(t_tube **lst)
{
	t_tube	*begin;
	t_tube	*next;

	begin = *lst;
	while (begin)
	{
		next = begin->next;
		ft_strdel(&begin->enter);
		ft_strdel(&begin->exit);
		free(begin);
		begin = next;
	}
	*lst = NULL;
}

void	ft_clear_salle(t_salle **lst)
{
	t_salle		*begin;
	t_salle		*next;

	begin = *lst;
	while (begin)
	{
		next = begin->next;
		ft_strdel(&begin->name);
		free(begin);
		begin = next;
	}
	*lst = NULL;
}

void	ft_clear_command(t_command **lst)
{
	t_command	*begin;
	t_command	*next;

	begin = *lst;
	while (begin)
	{
		next = begin->next;
		ft_strdel(&begin->command);
		free(begin);
		begin = next;
	}
	*lst = NULL;
}

void	ft_clear_comment(t_comment **lst)
{
	t_comment	*begin;
	t_comment	*next;

	begin = *lst;
	while (begin)
	{
		next = begin->next;
		ft_strdel(&begin->comment);
		free(begin);
		begin = next;
	}
	*lst = NULL;
}
