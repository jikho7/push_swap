/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:29:04 by jdefayes          #+#    #+#             */
/*   Updated: 2023/02/08 12:25:46 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_element
{
	int			nbr;
	int			idx;
	struct s_element	*next;
	struct s_element	*back;
}t_element;

typedef struct s_list
{
	t_element *first;
}t_list;

typedef struct s_data
{
	int		i;
	int		j;
	int		k;
	int		size;
	int		*tab;
	char	**av;
}t_data;

size_t		ft_strlen(const char *s);
void		bubble_sort(int *tab, int size);
t_element	*ft_lstnew(t_data *data);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
int			ft_lstsize(t_element *lst); // modif type, was t_list *lst
t_list		*initialisation();
# endif
