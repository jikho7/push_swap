/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:29:04 by jdefayes          #+#    #+#             */
/*   Updated: 2023/04/05 18:33:32 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_lst
{
	long			nbr;
	int				idx;
	struct s_lst	*nx;
}t_lst;

t_lst	*push_swap(t_lst **stack_a, t_lst **stack_b, int size);
long	*create_tab(t_lst **lst, int *ptr);
void	indexation(t_lst **lst, long *tab);
void	display_node(t_lst *lst);
t_lst	*ft_lstnew(int nbr);
t_lst	*ft_lstnew_b(void);
void	display_lst(t_lst **ptr_to_head, char *name);
void	radix(t_lst **stack_a, t_lst **stack_b, int size);

t_lst	*sa(t_lst **head);
void	pa(t_lst **stack_a, t_lst **stack_b);
int		pb(t_lst **stack_a, t_lst **stack_b);
t_lst	*rra(t_lst **head);
t_lst	*ra(t_lst **head);

void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	bubble_sort(long *tab, int size);
int		ft_lstsize(t_lst *lst);
t_lst	*ft_lstlast(t_lst *lst);
void	ft_lstclear(t_lst **lst);
void	ft_lstdelone(t_lst *lst);
long	ft_atoi(const char *str, t_lst *stack, char **res_split);
int		exceptions_atoi(const char *str);
void	exceptions_atoi_2(const char *str, long result, t_lst *stack);

void	add_front(t_lst **head, t_lst *node_to_add);
void	add_back(t_lst **head, t_lst *node_to_add);
t_lst	*del_first(t_lst **head);

t_lst	*below_5_numbers(t_lst **stack_a, t_lst **stack_b, int ac);
int		in_order(t_lst **stack, int size);
int		exceptions(t_lst **stack);
int		exception_4(t_lst **stack, int in_order);
int		exception_5(t_lst **stack, int in_order);
t_lst	*rra_twice(t_lst **stack);
t_lst	**sort_two_nb(t_lst **stack);
t_lst	*sort_three_nb(t_lst **stack);
t_lst	*sort_four_nb(t_lst **stack_a, t_lst **stack_b);
t_lst	*sort_five_nb(t_lst **stack_a, t_lst **stack_b);

char	**ft_split(const char *str, char c);
int		verif_split(char **tab);
t_lst	*handle_str(char **str);
void	check_doublon(long *tab, int size, t_lst *stack);
void	check_max_min(long *tab, int size, t_lst *stack);
t_lst	*create_lst(int ac, char **av, char **res_split);
void	error(void);

void	free_double_tab(char **tab, int size, int ac);
int		check_order(t_lst **stack);
t_lst	*generate_lst(t_lst *stack, int size, long *tab, int i);

#endif
