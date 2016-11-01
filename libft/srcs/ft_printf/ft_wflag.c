/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 15:43:34 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 14:57:30 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wzero(t_flag *flag, int len)
{
	int		yolo;
	char	*whitespace;

	yolo = 0;
	if (!(whitespace = ft_strnew(flag->nbchar + 1)))
		return (0);
	while ((yolo + len) != flag->nbchar)
	{
		whitespace[yolo] = '0';
		yolo++;
	}
	whitespace[yolo] = '\0';
	yolo = ft_putstr_len(whitespace, yolo);
	free(whitespace);
	return (yolo);
}

int		ft_wspace(t_flag *flag, int len)
{
	int		yolo;
	char	*whitespace;

	yolo = 0;
	if (!(whitespace = ft_strnew(flag->nbchar + 1)))
		return (0);
	while ((yolo + len) != flag->nbchar)
	{
		whitespace[yolo] = ' ';
		yolo++;
	}
	whitespace[yolo] = '\0';
	yolo = ft_putstr_len(whitespace, yolo);
	free(whitespace);
	return (yolo);
}

int		ft_wflag_ter(t_flag *flag, wchar_t *str)
{
	int		result;
	int		pointprint;

	result = 0;
	pointprint = 0;
	while (flag->nbpoint + 1 > pointprint)
	{
		if (flag->nbchar >= flag->nbpoint)
		{
			flag->nbchar--;
			if (flag->nbchar >= flag->nbpoint)
				result += ft_putchar(' ');
		}
		else if (flag->nbpoint != 0)
		{
			if (result == 11)
				result += ft_putchar(' ');
			result += ft_putwchar(*str);
			str++;
			pointprint = result + ft_lenwchar(*str);
		}
		else
			break ;
	}
	return (result);
}
