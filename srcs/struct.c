/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:26:40 by jelefebv          #+#    #+#             */
/*   Updated: 2016/11/02 17:47:40 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

void	push_back_comment(t_comment *comment, const char *str)
{
	t_comment	*tmp;

	tmp = comment;
	while (tmp->next)
		tmp = tmp->next;
	if (str)
	{
		tmp->next->comment = ft_strdup(str);
		tmp->next->next = NULL;
	}
}

void	push_back_command(t_command *command, const char *str)
{
	t_command	*tmp;

	tmp = command;
	while (tmp->next)
		tmp = tmp->next;
	if (str)
	{
		tmp->next->command = ft_strdup(str);
		tmp->next->next = NULL;
	}
}
