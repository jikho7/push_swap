/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   below_5_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:22:36 by jdefayes          #+#    #+#             */
/*   Updated: 2023/03/08 11:37:06 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

t_lst *below_5_numbers(t_lst **stack_a, t_lst **stack_b, int ac)
{
	(void) **stack_b;
	(void)ac;
	if(ac == 2)
		return(*stack_a);
	if(ac == 3)
	 	two(stack_a);
	if (ac == 4)
		three(stack_a);
	if (ac == 5)
		four(stack_a, stack_b);
	if (ac == 6)
		sort_five(stack_a, stack_b);
	ft_lstclear(stack_b);
	return(*stack_a);
}

t_lst **two(t_lst **stack)
{
	t_lst *lst;
	lst = *stack;
	if (lst->idx < lst->next->idx)
	{
		sa(stack);
	}
	return (stack);
}

t_lst *three(t_lst **stack)
{
	t_lst *lst;

	lst = *stack;
	if (lst->idx > lst->next->idx && lst->next->idx > lst->next->next->idx)
		return (*stack);
	if (lst->idx > lst->next->idx && lst->idx < lst->next->next->idx)
		return (rra(stack));
	else if (lst->idx < lst->next->idx && lst->idx > lst->next->next->idx)
		return (sa(stack));
	while (lst->idx < lst->next->idx || lst->next->idx < lst->next->next->idx)
	{
		if (lst->idx < lst->next->idx && lst->next->idx < lst->next->next->idx)
		{
			ra(stack);
			lst = *stack;
			sa(stack);
		}
		else if (lst->idx < lst->next->idx)
			ra(stack);
		else if (lst->idx > lst->next->idx)
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
		return (*stack_a);
	if (exception == 2) // si + petit = head
		{
			pb(stack_a, stack_b);
		}
	else if (exception == 3)	// si + petit dernier
		{
			rra(stack_a);
			pb(stack_a, stack_b);
		}
	else
	{
		while (1)
		{
			tmp = ra(stack_a);
			if (tmp->idx > tmp->next->idx && tmp->idx > tmp->next->next->idx
				&& tmp->idx > tmp->next->next->next->idx)	// si + petit = head
			{
				pb(stack_a, stack_b);
				break;
			}
			tmp = sa(stack_a);
			if (tmp->idx > tmp->next->idx && tmp->idx > tmp->next->next->idx
				&& tmp->idx > tmp->next->next->next->idx)	// si + petit = head
			{
				pb(stack_a, stack_b);
				break;
			}
		}
	}
	three(stack_a);
	pa(stack_a, stack_b);
return(*stack_a);
}

/*
t_lst *four(t_lst **stack_a, t_lst **stack_b)
{
	t_lst *tmp;
	int check;

	tmp = *stack_a;
	check = in_order(stack_a);
	if (check == 1)
		return (*stack_a);
	if (tmp->idx > tmp->next->idx && tmp->idx > tmp->next->next->idx
		&& tmp->idx > tmp->next->next->next->idx) // si + petit = head
		{
			pb(stack_a, stack_b);
		}
	else if (tmp->next->next->next->idx > tmp->next->next->idx && tmp->next->next->next->idx > tmp->next->idx
			&&tmp->next->next->next->idx > tmp->idx)	// si + petit dernier
		{
			rra(stack_a);
			pb(stack_a, stack_b);
		}
	else
	{
		while (1)
		{
			tmp = ra(stack_a);
			if (tmp->idx > tmp->next->idx && tmp->idx > tmp->next->next->idx
				&& tmp->idx > tmp->next->next->next->idx)	// si + petit = head
			{
				pb(stack_a, stack_b);
				break;
			}
			tmp = sa(stack_a);
			if (tmp->idx > tmp->next->idx && tmp->idx > tmp->next->next->idx
				&& tmp->idx > tmp->next->next->next->idx)	// si + petit = head
			{
				pb(stack_a, stack_b);
				break;
			}
		}
	}
	three(stack_a);
	pa(stack_a, stack_b);
return(*stack_a);
}
*/

int in_order(t_lst **stack)
{
	t_lst *tmp;

	tmp = *stack;
	if (tmp->idx > tmp->next->idx && tmp->next->idx > tmp->next->next->idx
		&& tmp->next->next->idx > tmp->next->next->next->idx)
		return (1);
	return (0);
}

t_lst *sort_five(t_lst **stack_a, t_lst **stack_b)
{
	t_lst *t;

	t = *stack_a;
	if (t->idx > t->next->idx && t->idx > t->next->next->idx &&
		t->idx > t->next->next->next->idx && t->idx > t->next->next->next->next->idx) // si + petit = head
		{
			printf("");
		}
	else if (t->next->idx > t->idx && t->next->idx > t->next->next->idx &&
		t->next->idx > t->next->next->next->idx && t->next->idx > t->next->next->next->next->idx)	// si + petit 2eme
		{
			sa(stack_a);
		}
	else if (t->next->next->next->next->idx > t->next->idx &&
		t->next->next->next->next->idx > t->next->next->idx &&
		t->next->next->next->next->idx > t->next->next->next->idx)	// si + petit = tail
			{
				rra(stack_a);
			}
	else if ((t->next->next->next->idx > t->idx &&
		t->next->next->next->idx > t->next->idx &&
		t->next->next->next->idx > t->next->next->idx && t->next->next->next->idx > t->next->next->next->next->idx))	// si + petit avant dernier
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if ((t->next->next->idx > t->idx &&
		t->next->next->idx > t->next->idx &&
		t->next->next->idx > t->next->next->next->idx && t->next->next->idx > t->next->next->next->next->idx))	// si + petit 3eme
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
	t_lst *t;

	size = ft_lstsize(*stack);
	check = in_order(stack);
	t = *stack;
	if (size == 4)
	{
		if (check == 1)
			return (1);
		if (t->idx > t->next->idx && t->idx > t->next->next->idx
			&& t->idx > t->next->next->next->idx) // si + petit = head
				return (2);
		if (t->next->next->next->idx > t->next->next->idx && t->next->next->next->idx > t->next->idx
				&&t->next->next->next->idx > t->idx)	// si + petit dernier
				return (3);
	}
	if (size == 5)
	{
		if (check == 1)
			return (1);
		if (t->idx > t->next->idx && t->idx > t->next->next->idx &&
		t->idx > t->next->next->next->idx && t->idx > t->next->next->next->next->idx) // si + petit = head
		{
			return (2);
		}

	}

	return (0);
}
