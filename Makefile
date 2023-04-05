# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 11:49:08 by jdefayes          #+#    #+#              #
#    Updated: 2023/04/04 18:48:57 by jdefayes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


###################################
##NAME
NAME	= push_swap

###################################
##SOURCES
SRC		=	main.c\
			create_lst.c\
			checks_n_free.c\
			utils.c\
			libft_ft.c\
			push_swap.c\
			handle_lists.c\
			handle_piles.c\
			below_5_numbers.c\
			exceptions_below_5.c\
			lst_infos.c\
			ps_split.c\

OBJ		= ${SRC:.c=.o}
FLAGS	= -Wall -Werror -Wextra -g
CC		= gcc
RM		= rm -f

GUI		= python3 pyviz.py `ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`

###################################
##RULES
all: $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

gui :	all
		@$(GUI)
		@make fclean

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean .c.o

