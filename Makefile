# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 11:49:08 by jdefayes          #+#    #+#              #
#    Updated: 2023/02/13 19:54:18 by jdefayes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


###################################
##NAME
NAME	= push_swap

###################################
##SOURCES
SRC		=	push_swap.c\
			utils.c\
			handle_lists.c\
			handle_piles.c\

OBJ		= ${SRC:.c=.o}
FLAGS	= -Wall -Werror -Wextra -g
CC		= gcc
RM		= rm -f

###################################
##RULES
all: $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean .c.o

