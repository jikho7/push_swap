/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   below_5_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:22:36 by jdefayes          #+#    #+#             */
/*   Updated: 2023/03/29 16:53:44 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*below_5_numbers(t_lst **stack_a, t_lst **stack_b, int ac)
{
	(void) **stack_b;
	if (ac == 2)
		return (*stack_a);
	if (ac == 3)
		sort_two_nb(stack_a);
	if (ac == 4)
	{
		sort_three_nb(stack_a);
	}
	if (ac == 5)
	{
		sort_four_nb(stack_a, stack_b);
	}
	if (ac == 6)
	{
		sort_five_nb(stack_a, stack_b);
	}
	ft_lstclear(stack_b);
	return (*stack_a);
}

t_lst	**sort_two_nb(t_lst **stack)
{
	t_lst	*lst;

	lst = *stack;
	if (lst->idx < lst->nx->idx)
	{
		sa(stack);
	}
	return (stack);
}

t_lst	*sort_three_nb(t_lst **stack)
{
	t_lst	*lst;

	lst = *stack;
	if (lst->idx > lst->nx->idx && lst->nx->idx > lst->nx->nx->idx)
		return (*stack);
	if (lst->idx > lst->nx->idx && lst->idx < lst->nx->nx->idx)
		return (rra(stack));
	else if (lst->idx < lst->nx->idx && lst->idx > lst->nx->nx->idx)
		return (sa(stack));
	while (lst->idx < lst->nx->idx || lst->nx->idx < lst->nx->nx->idx)
	{
		if (lst->idx < lst->nx->idx && lst->nx->idx < lst->nx->nx->idx)
		{
			ra(stack);
			lst = *stack;
			sa(stack);
		}
		else if (lst->idx < lst->nx->idx)
			ra(stack);
		else if (lst->idx > lst->nx->idx)
			sa(stack);
		lst = *stack;
	}
	return (*stack);
}

t_lst	*sort_four_nb(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*tmp;
	int		exception;

	tmp = *stack_a;
	exception = exceptions(stack_a);
	if (exception == 1)
	{
		return (*stack_a);
	}
	else if (exception == 2)
	{
		write(1, "", 0);
	}
	else if (exception == 3)
	{
		rra(stack_a);
	}
	else
	{
		exception_4(stack_a, 4);
	}
	pb(stack_a, stack_b);
	sort_three_nb(stack_a);
	pa(stack_a, stack_b);
	return (*stack_a);
}

t_lst	*sort_five_nb(t_lst **stack_a, t_lst **stack_b)
{
	int		exception;
	t_lst	*t;

	exception = exceptions(stack_a);
	t = *stack_a;
	if (exception == 1)
		return (*stack_a);
	if (exception == 2)
		write(1, "", 0);
	else if (exception == 3)
		sa(stack_a);
	else if (exception == 4)
		rra(stack_a);
	else if (exception == 5)
		rra_twice(stack_a);
	else if (exception == 6)
	{
		ra(stack_a);
		sa(stack_a);
	}
	pb(stack_a, stack_b);
	sort_four_nb(stack_a, stack_b);
	pa(stack_a, stack_b);
	return (*stack_a);
}
