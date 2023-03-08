/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   below_5_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:22:36 by jdefayes          #+#    #+#             */
/*   Updated: 2023/03/08 14:55:13 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

t_lst *below_5_numbers(t_lst **stack_a, t_lst **stack_b, int ac)
{
	(void) **stack_b;
	(void)ac;
	if (ac == 2)
		return (*stack_a);
	if (ac == 3)
		two(stack_a);
	if (ac == 4)
		three(stack_a);
	if (ac == 5)
		four(stack_a, stack_b);
	if (ac == 6)
		sort_five(stack_a, stack_b);
	ft_lstclear(stack_b);
	return (*stack_a);
}

t_lst **two(t_lst **stack)
{
	t_lst	*lst;

	lst = *stack;
	if (lst->idx < lst->nx->idx)
	{
		sa(stack);
	}
	return (stack);
}

t_lst *three(t_lst **stack)
{
	t_lst *lst;

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
	return(*stack);
}


t_lst *four(t_lst **stack_a, t_lst **stack_b)
{
	t_lst *tmp;
	int exception;

	tmp = *stack_a;
	exception = exceptions(stack_a);
	if (exception == 1)
	{
		return (*stack_a);
	}
	else if (exception == 2)	// si + petit = head
	{
		write(1, "", 0);
	}
	else if (exception == 3)	// si + petit dernier
	{
		rra(stack_a);
	}
	else
	{
		exception_4(stack_a, 4);
	}
	pb(stack_a, stack_b);
	three(stack_a);
	pa(stack_a, stack_b);
	return(*stack_a);
}


int in_order(t_lst **stack, int size)
{
	t_lst *tmp;

	tmp = *stack;
	if (size == 4)
	{
		if (tmp->idx > tmp->nx->idx && tmp->nx->idx > tmp->nx->nx->idx
			&& tmp->nx->nx->idx > tmp->nx->nx->nx->idx)
			return (1);
	}
	if (size == 5)
	{
		if (tmp->idx > tmp->nx->idx && tmp->nx->idx > tmp->nx->nx->idx
			&& tmp->nx->nx->idx > tmp->nx->nx->nx->idx
			&& tmp->nx->nx->nx->idx > tmp->nx->nx->nx->nx->idx)
			return (1);
	}
	return (0);
}


t_lst *sort_five(t_lst **stack_a, t_lst **stack_b)
{
	int exception;
	t_lst *t;

	exception = exceptions(stack_a);
	t = *stack_a;
	if (exception == 1)
		return (*stack_a);
	if (exception == 2) // si + petit = head
	{
		printf("");
	}
	else if (exception == 3)	// si + petit 2eme
	{
		sa(stack_a);
	}
	else if (exception == 4)	// si + petit = tail
	{
		rra(stack_a);
	}
	else if (exception == 5)	// si + petit avant dernier
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (exception == 6)	// si + petit 3eme
	{
		ra(stack_a);
		sa(stack_a);
	}
	pb(stack_a, stack_b);
	four(stack_a, stack_b);
	pa(stack_a, stack_b);
	return (*stack_a);
}


int exceptions(t_lst **stack)
{
	int size;
	int check;
	int result;

	result = 0;
	size = ft_lstsize(*stack);
	check = in_order(stack, size);
	if (size == 4)
	{
		result = exception_4(stack, check);
	}
	if (size == 5)
	{
		result = exception_5(stack, check);
	}
	return (result);
}

int exception_5(t_lst **stack, int in_order)
{
	t_lst *t;

	t = *stack;
	if (in_order == 1)
		return (1);
	if (t->idx > t->nx->idx && t->idx > t->nx->nx->nx->nx->idx
		&& t->idx > t->nx->nx->nx->idx && t->idx > t->nx->nx->idx)
		return (2); // si + petit = head
	else if (t->nx->idx > t->idx && t->nx->idx > t->nx->nx->nx->nx->idx
		&& t->nx->idx > t->nx->nx->nx->idx && t->nx->idx > t->nx->nx->idx)
		return (3);// si + petit 2eme
	else if (t->nx->nx->nx->nx->idx > t->nx->idx
		&& t->nx->nx->nx->nx->idx > t->nx->nx->idx
		&& t->nx->nx->nx->nx->idx > t->nx->nx->nx->idx)
		return (4);// si + petit = tail
	else if (t->nx->nx->nx->idx > t->idx && t->nx->nx->nx->idx > t->nx->idx
		&& t->nx->nx->nx->idx > t->nx->nx->idx
		&& t->nx->nx->nx->idx > t->nx->nx->nx->nx->idx)
		return (5);// si + petit avant dernier
	else if (t->nx->nx->idx > t->idx && t->nx->nx->idx > t->nx->idx
		&& t->nx->nx->idx > t->nx->nx->nx->idx
		&& t->nx->nx->idx > t->nx->nx->nx->nx->idx)
		return (6);// si + petit 3eme
	return (0);
}

int exception_4(t_lst **stack, int in_order)
{
	t_lst *t;

	t = *stack;
	if (in_order == 1)
		return (1);
	else if (t->idx > t->nx->idx && t->idx > t->nx->nx->idx
			&& t->idx > t->nx->nx->nx->idx) // si + petit = head
		return (2);
	else if (t->nx->nx->nx->idx > t->nx->nx->idx && t->nx->nx->nx->idx > t->nx->idx
			&&t->nx->nx->nx->idx > t->idx)	// si + petit dernier
		return (3);
	else if (in_order == 4)
		while (1)
		{
			t = ra(stack);
			if (t->idx > t->nx->idx && t->idx > t->nx->nx->idx
				&& t->idx > t->nx->nx->nx->idx)	// si + petit = head
				break;
			t = sa(stack);
			if (t->idx > t->nx->idx && t->idx > t->nx->nx->idx
				&& t->idx > t->nx->nx->nx->idx)	// si + petit = head
				break;
		}
	return (0);
}


