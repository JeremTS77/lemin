/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeremy <jeremy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 17:10:34 by jeremy            #+#    #+#             */
/*   Updated: 2016/10/29 18:04:00 by jeremy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "lemin.h"

t_lst	*ft_new(const char *str, const int r)
{
	t_lst	*new;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	new->str = ft_strnew(r);
	new->str = ft_strncpy(new->str, str, r);
	new->next = NULL;
	return (new);
}

void	ft_push_back(t_lst **lst, const char *str, const int r)
{
	t_lst	*tmp;

	tmp = *lst;
	if (!tmp)
		*lst = ft_new(str, r);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_new(str, r);
	}
}

void	ft_print_lst(t_lst *lst)
{
	if (lst)
	{
		while (lst)
		{
			ft_printf("%s\n", lst->str);
			lst = lst->next;
		}
	}
}
