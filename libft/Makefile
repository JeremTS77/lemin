# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/15 16:40:45 by jelefebv          #+#    #+#              #
#    Updated: 2016/03/20 10:34:30 by jelefebv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

NAMEBASE		=   $(shell basename $(NAME) .a)

LENGTHNAME		=	`printf "%s" $(NAMEBASE) | wc -c`

MAX_COLS		=	$$(echo "$$(tput cols)-24-$(LENGTHNAME)"|bc)

CC				=	gcc

FLAGS			=	-Wall -Wextra -Werror -ggdb

SRCDIR			=	srcs/

SRCLIBDIR		=	libft/

SRCGETFDIR		=	get_next_line/

SRCPRINTFDIR	=	ft_printf/

OBJDIR			=	objs/

INCDIR			=	includes/


SRCLIB			=	\
					ft_addrlen.c\
					ft_atoi.c\
					ft_bzero.c\
					ft_chartostr.c\
					ft_clear_string.c\
					ft_delstr.c\
					ft_isalnum.c\
					ft_isalpha.c\
					ft_isascii.c\
					ft_isdigit.c\
					ft_isprint.c\
					ft_itoa.c\
					ft_keepstring.c\
					ft_keepstring_inv.c\
					ft_lenwchar.c\
					ft_lenwstr.c\
					ft_memalloc.c\
					ft_memccpy.c\
					ft_memchr.c\
					ft_memcmp.c\
					ft_memcpy.c\
					ft_memdel.c\
					ft_memmove.c\
					ft_memset.c\
					ft_nbrlen.c\
					ft_putaddr.c\
					ft_putaddr_fd.c\
					ft_putchar.c\
					ft_putchar_fd.c\
					ft_putendl.c\
					ft_putendl_fd.c\
					ft_putnbr.c\
					ft_putnbr_fd.c\
					ft_putstr.c\
					ft_putstr_fd.c\
					ft_putstr_len.c\
					ft_putwchar.c\
					ft_putwstr.c\
					ft_straddr.c\
					ft_strcat.c\
					ft_strcchr.c\
					ft_strchr.c\
					ft_strclr.c\
					ft_strcmp.c\
					ft_strcpy.c\
					ft_strdel.c\
					ft_strdup.c\
					ft_strequ.c\
					ft_striter.c\
					ft_striteri.c\
					ft_strjoin.c\
					ft_strlcat.c\
					ft_strlen.c\
					ft_strlower.c\
					ft_strmap.c\
					ft_strmapi.c\
					ft_strncat.c\
					ft_strncmp.c\
					ft_strncpy.c\
					ft_strnequ.c\
					ft_strnew.c\
					ft_strnstr.c\
					ft_strrchr.c\
					ft_strrev.c\
					ft_strsplit.c\
					ft_strstr.c\
					ft_strstrdel.c\
					ft_strstrlen.c\
					ft_strsub.c\
					ft_strtrim.c\
					ft_strupper.c\
					ft_tolower.c\
					ft_toupper.c

SRCGET			=	\
					get_next_line.c

SRCPRINTF		=	\
					ft_chartostr_res.c\
					ft_check.c\
					ft_check_null.c\
					ft_check_x.c\
					ft_checkj.c\
					ft_checkz.c\
					ft_octalen.c\
					ft_opt_all.c\
					ft_parsflag_bis.c\
					ft_parsing.c\
					ft_parsing_bis.c\
					ft_parsing_ter.c\
					ft_parsmoins.c\
					ft_printf.c\
					ft_printf_n.c\
					ft_printf_o.c\
					ft_printf_s.c\
					ft_putdmodif.c\
					ft_putnormal.c\
					ft_putomodif.c\
					ft_putumodif.c\
					ft_putxmodif.c\
					ft_putxmodif_maj.c\
					ft_putzmodif.c\
					ft_s_opt.c\
					ft_triprintf.c\
					ft_wflag.c

INCBASE			=	\
				ft_printf.h													\
				get_next_line.h												\
				libft.h

SRCS_L			=	$(addprefix $(SRCLIBDIR), $(SRCLIB))

SRCS_PRINTF		=	$(addprefix $(SRCPRINTFDIR), $(SRCPRINTF))

SRCS_GETN		=	$(addprefix $(SRCGETFDIR), $(SRCGET))

SRCG			=	$(SRCS_L) $(SRCS_PRINTF) $(SRCS_GETN)

INCS			=	$(addprefix $(INCDIR), $(INCBASE))

OBJS			=	$(addprefix $(OBJDIR), $(SRCG:.c=.o))

.SILENT:

all:		$(NAME)

$(NAME):	$(OBJDIR) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	echo "\r\033[38;5;25m📘  MAKE   $(NAMEBASE)\033[0m\033[K"

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(dir $(OBJS))

$(OBJDIR)%.o : $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@ -I $(INCDIR)
	printf "\r\033[38;5;11m⌛  MAKE   %s plz wait ...%*s\033[0m\033[K"		\
		$(NAMEBASE) $(MAX_COLS) "($@)"

clean:
	printf "\r\033[38;5;11m⌛  CLEAN  $(NAMEBASE) plz wait ...\033[0m\033[K"
	if [[ `rm -R $(OBJDIR) &> /dev/null 2>&1; echo $$?` == "0" ]]; then		\
		echo -en "\r\033[38;5;124m📕  CLEAN  $(NAMEBASE)\033[0m\033[K";		\
		else																	\
		printf "\r";														\
		fi

fclean:		clean
	printf "\r\033[38;5;11m⌛  FCLEAN $(NAMEBASE) plz wait ...\033[0m\033[K"
	if [[ `rm $(NAME) &> /dev/null 2>&1; echo $$?` == "0" ]]; then			\
		echo -en "\r\033[38;5;124m📕  FCLEAN $(NAMEBASE)\033[0m\033[K";		\
		else																	\
		printf "\r";														\
		fi

re:			fclean all

.PHONY:		fclean clean re
