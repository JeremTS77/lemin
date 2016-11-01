/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:24:58 by jelefebv          #+#    #+#             */
/*   Updated: 2015/07/22 19:32:50 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_nbr_tab(char const *s, char c)
{
	int		i;
	int		m;

	i = 0;
	m = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			m++;
			while (s[i] != c && s[i])
				i++;
		}
		if (s[i] == c)
			i++;
	}
	return (m);
}

static char		**ft_creat_tab(char **split, char const *s, char c, int m)
{
	int				i;
	int				j;
	int				k;
	unsigned int	start;

	i = 0;
	j = 0;
	while (s[i] && m > 0)
	{
		k = 0;
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
		{
			i++;
			k++;
		}
		split[j] = ft_strsub(s, start, k);
		j++;
		m--;
	}
	split[j] = 0;
	return (split);
}

char			**ft_strsplit(char const *s, char c)
{
	int		m;
	char	**split;

	if (!s || c == '\0')
		return (NULL);
	else
	{
		m = ft_nbr_tab(s, c);
		split = (char **)malloc((sizeof(char *) * (m + 1)));
		if (split == NULL)
			return (NULL);
		split = ft_creat_tab(split, s, c, m);
		return (split);
	}
}
