/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeremy <jeremy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 16:15:20 by jeremy            #+#    #+#             */
/*   Updated: 2016/11/02 18:04:09 by jelefebv         ###   ########.fr       */
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

typedef struct			s_salle
{
	char				*name;
	int					x;
	int					y;
	struct s_salle		*next;
}						t_salle;

typedef struct			s_tube
{
	char				*enter;
	char				*exit;
	struct s_tube		*next;
}						t_tube;

typedef struct			s_comment
{
	char				*comment;
	struct s_comment	*next;
}						t_comment;

typedef struct			s_command
{
	char				*command;
	struct s_command	*next;
}						t_command;

typedef struct			s_lem
{
	unsigned int		nb_fourmis;
	char				*start;
	char				*end;
	int					startx;
	int					starty;
	int					endx;
	int					endy;
	t_salle				*map;
	t_tube				*tube;
	t_comment			*comment;
	t_command			*command;
}						t_lem;

t_salle					*ft_new_salle(const char *str);
t_tube					*ft_new_tube(const char *str);
int						ft_push_back_salle(t_salle **salle, const char *str);
int						ft_push_back_tube(t_tube **tube, const char *str);
void					ft_print_salle(t_salle *salle);
void					ft_print_tube(t_tube *tube);
void					push_back_comment(t_comment *comment, const char *str);
void					push_back_command(t_command *command, const char *str);
void					ft_print_lemin(t_lem *lem);

#endif
