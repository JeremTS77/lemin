/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:26:40 by jelefebv          #+#    #+#             */
/*   Updated: 2016/11/09 16:46:34 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

void	push_back_comment(t_comment **comment, const char *str)
{
	t_comment	*tmp;

	tmp = *comment;
	if (!tmp)
	{
		if ((*comment = (t_comment *)malloc(sizeof(t_comment))))
		{
			(*comment)->comment = ft_strdup(str);
			(*comment)->next = NULL;
		}
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (str && *str)
		{
			if ((tmp->next = (t_comment *)malloc(sizeof(t_comment))))
			{
				tmp->next->comment = ft_strdup(str);
				tmp->next->next = NULL;
			}
		}
	}
}

void	push_back_command(t_command **command, const char *str)
{
	t_command	*tmp;

	tmp = *command;
	if (!tmp)
	{
		if ((*command = (t_command *)malloc(sizeof(t_command))))
		{
			(*command)->command = ft_strdup(str);
			(*command)->next = NULL;
		}
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (str && *str)
		{
			if ((tmp->next = (t_command *)malloc(sizeof(t_command))))
			{
				tmp->next->command = ft_strdup(str);
				tmp->next->next = NULL;
			}
		}
	}
}
