/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsflag_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 14:56:00 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 14:57:26 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_parsflag_bis(t_flag *flagprintf, const char *s)
{
	flagprintf->nbchar = ft_atoi(s);
	flagprintf->format += ft_nbrlen(flagprintf->nbchar);
	s += ft_nbrlen(flagprintf->nbchar);
	ft_parseflag(flagprintf);
}
