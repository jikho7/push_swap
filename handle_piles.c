/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_piles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:11:11 by jdefayes          #+#    #+#             */
/*   Updated: 2023/04/03 21:12:10 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*sa(t_lst **head)
{
	t_lst	*tmp;
	t_lst	*first_node;
	t_lst	*second_node;

	tmp = *head;
	if (tmp->nx != NULL)
	{
		first_node = del_first(head);
		second_node = del_first(head);
		add_front(head, first_node);
		add_front(head, second_node);
	}
	write(1, "sa\n", 3);
	return (*head);
}

int	pb(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*to_move;
	t_lst	*tmp;

	tmp = *stack_a;
	if (tmp != NULL)
	{
		to_move = del_first(stack_a);
		add_front(stack_b, to_move);
	}
	write(1, "pb\n", 3);
	return (0);
}

void	pa(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*to_move;
	t_lst	*tmp;

	tmp = *stack_b;
	if (tmp != NULL)
	{
		to_move = del_first(stack_b);
		add_front(stack_a, to_move);
	}
	write(1, "pa\n", 3);
}

t_lst	*ra(t_lst **head)
{
	t_lst	*to_move;
	t_lst	*tmp;

	tmp = *head;
	if (tmp->nx != NULL)
	{
		to_move = del_first(head);
		add_back(head, to_move);
	}
	write(1, "ra\n", 3);
	return (*head);
}

t_lst	*rra(t_lst **head)
{
	t_lst	*tmp;
	t_lst	*to_add;
	int		size;

	tmp = *head;
	size = ft_lstsize(*head);
	while (tmp->nx)
		tmp = tmp->nx;
	to_add = tmp;
	to_add->nx = *head;
	tmp = to_add;
	add_front(head, to_add);
	while (size > 1)
	{
		tmp = tmp->nx;
		size--;
	}
	tmp->nx = NULL;
	write(1, "rra\n", 4);
	return (*head);
}
