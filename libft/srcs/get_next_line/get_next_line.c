/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:23:42 by jelefebv          #+#    #+#             */
/*   Updated: 2016/03/22 12:06:40 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"

int		get_next_line(int const fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE];
	static char		*tmp;
	static char		*str;

	if (fd == -1)
		return (-1);
	str = (!str) ? ft_strnew(1) : str;
	if ((ret = read(fd, buf, BUFF_SIZE)) == -1 || ret == 0)
		return (ret == 0 ? 0 : -1);
	*line = (ret == 0 && !ft_strchr(str, '\n')) ? ft_strcpy(*line, str) : str;
	if (ret == 0 && (*line != str) && str != tmp + 1)
		return (0);
	buf[ret] = '\0';
	str = ft_strjoin(str, buf);
	if (!ft_strchr(str, '\n'))
		get_next_line(fd, line);
	else
	{
		tmp = ft_strchr(str, '\n');
		*tmp = '\0';
		*line = ft_strcpy(*line, str);
		str = tmp + 1;
	}
	return (1);
}
