/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:29:04 by jdefayes          #+#    #+#             */
/*   Updated: 2023/02/13 17:49:14 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_lst
{
	int			nbr;
	int			idx;
	struct s_lst	*next;
	struct s_lst	*back;
}t_lst;

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
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		display_node(t_lst *lst);
t_lst	*ft_lstnew(t_data *data);
void		insertion(t_lst *list, t_data *data);

t_lst	*ps_lstnew(t_data *data, t_lst *list);
t_lst		*ps_lstlast(t_lst *lst);
void		ps_lstadd_back(t_lst **lst, t_lst *new);
void		ps_lstadd_front(t_lst **lst, t_lst *new);
int			ps_lstsize(t_lst *lst);
void push_front(t_lst ** head, t_data *val);
void push_end(t_lst *head, t_data *val);
void display_lst(t_lst **first_node, char *name);

# endif
