/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeremy <jeremy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 16:15:20 by jeremy            #+#    #+#             */
/*   Updated: 2016/10/29 19:25:56 by jeremy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <strings.h>
# include "libft.h"

typedef struct		s_salle
{
	char			*name;
	int				x;
	int				y;
	struct s_salle	*next;
}					t_salle;

typedef struct		s_tube
{
	char			*enter;
	char			*exit;
	struct s_tube	*next;
}					t_tube;

typedef struct		s_lem
{
	unsigned int	nb_fourmis;
	char			*start;
	char			*end;
	t_salle			*map;
	t_tube			*tube;
}					t_lem;

t_salle		*ft_new_salle(const char *str);
int			ft_push_back_salle(t_salle **salle, const char *str);
void		ft_print_salle(t_salle *salle);

#endif
