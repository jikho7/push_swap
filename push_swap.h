/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:29:04 by jdefayes          #+#    #+#             */
/*   Updated: 2023/03/22 18:14:53 by jdefayes         ###   ########.fr       */
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
	int			tab[9];
	struct s_lst	*nx;
	struct s_lst	*back;
}t_lst;

typedef struct s_a
{
	int *check;
	t_lst **stack_a;
	t_lst *tmp_a;
}t_a;

typedef struct s_b
{
	int *check;
	t_lst **stack_b;
	t_lst *tmp_b;
}t_b;

typedef struct s_data
{
	int		i;
	int		j;
	int		k;
	int		size;
	int		*tab;
	char	**av;
}t_data;

t_lst *push_swap(t_lst **stack_a, t_lst **stack_b, int ac);
void halving(t_lst **stack_a, t_lst **stack_b, int ac);
int set_multi(int size);
int *check_order(t_lst **stack, char which_stack, int *check);
int rotate(t_lst **stack_a, t_lst **stack_b, int total_size, int *check_a, int *check_b);
int swap(t_lst **stack_a, t_lst **stack_b, int total_size, int *check_a, int *check_b);
int *create_tab(t_lst **lst, int size);
void indexation(t_lst **lst, int *tab);
void display_node(t_lst *lst);
t_lst	*ft_lstnew(int nbr);
t_lst	*ft_lstnew_b();
void display_lst(t_lst **ptr_to_head, char *name);

t_lst *sa(t_lst **head);
t_lst *sb(t_lst **head);
void ss(t_lst **stack_a, t_lst **stack_b);
void pa(t_lst **stack_a, t_lst **stack_b);
int pb(t_lst **stack_a, t_lst **stack_b);
t_lst *rra(t_lst **head);
t_lst *rrb(t_lst **head);
t_lst *rb(t_lst **head);
void rr(t_lst **stack_a, t_lst **stack_b);
t_lst *ra(t_lst **head);

void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void bubble_sort(int *tab, int size);
int	ft_lstsize(t_lst *lst);
t_lst	*ft_lstlast(t_lst *lst);
void	ft_lstclear(t_lst **lst);
void	ft_lstdelone(t_lst *lst);

void push_front(t_lst ** ptr_to_head, t_data *val);
void add_front2(t_lst **head, t_lst *node_to_add);
void push_end(t_lst *head, t_data *val);
void add_back2(t_lst **head, t_lst *node_to_add);
void add_front(t_lst **ptr_to_head, int x);
void add_back(t_lst **ptr_to_head, int x);
t_lst	*del_first(t_lst **head);

t_lst	*below_5_numbers(t_lst **stack_a, t_lst **stack_b, int ac);
int in_order(t_lst **stack, int size);
int exceptions(t_lst **stack);
int exception_4(t_lst **stack, int in_order);
int exception_5(t_lst **stack, int in_order);
t_lst **two(t_lst **stack);
t_lst *three(t_lst **stack);
t_lst *four(t_lst **stack_a, t_lst **stack_b);
t_lst *sort_five(t_lst **stack_a, t_lst **stack_b);

# endif
