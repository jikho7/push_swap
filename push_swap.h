/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:29:04 by jdefayes          #+#    #+#             */
/*   Updated: 2023/02/21 17:46:17 by jdefayes         ###   ########.fr       */
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
void push_front(t_lst ** ptr_to_head, t_data *val);
void push_end(t_lst *head, t_data *val);
void display_lst(t_lst **ptr_to_head, char *name);
void sa(t_lst *a);


t_lst	*ft_lstnew2(int nbr);
void	add_front(t_lst **ptr_to_head, int x);
void	add_back(t_lst **ptr_to_head, int x);
t_lst *del_first(t_lst **head);
void add_front2(t_lst **head, t_lst *node_to_add);
void add_back2(t_lst **head, t_lst *node_to_add);
void rotate(t_lst **head);
void swap2(t_lst **head);

# endif
