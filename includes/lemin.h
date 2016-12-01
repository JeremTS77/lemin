/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeremy <jeremy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 16:15:20 by jeremy            #+#    #+#             */
/*   Updated: 2016/12/01 23:22:57 by jeremy           ###   ########.fr       */
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
	int					weight;
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
t_salle					*ft_get_salle(t_salle *room, char *name);
t_tube					*ft_new_tube(const char *str, const t_salle *room);
int						ft_push_back_salle(t_salle **salle, const char *str);
int						ft_push_back_tube(t_tube **tube, const t_salle *room,
		const char *str);
int						ft_compte_room(t_salle *room);
void					push_back_comment(t_comment **comment, const char *str);
void					push_back_command(t_command **command, const char *str);
void					ft_print_lemin(t_lem lem);
void					ft_clear_comment(t_comment **lst);
void					ft_clear_command(t_command **lst);
void					ft_clear_salle(t_salle **lst);
void					ft_clear_tube(t_tube **lst);
void					ft_rec(t_lem *lem, char *name, int index);
void					ft_count_room(t_salle *room, int *c);
void					ft_check_error(t_lem *lem, int *c);

#endif
