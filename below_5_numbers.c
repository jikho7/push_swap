/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   below_5_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:22:36 by jdefayes          #+#    #+#             */
/*   Updated: 2023/03/07 19:59:13 by jdefayes         ###   ########.fr       */
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
//	if (ac == 6)
//		five(stack_a, stack_b);
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
	if (lst->idx < lst->next->idx && lst->idx < lst->next->next->idx)
		return (ra(stack));
	else if (lst->idx < lst->next->idx && lst->idx > lst->next->next->idx)
		return (sa(stack));
	while (lst->idx < lst->next->idx || lst->next->idx < lst->next->next->idx)
	{
		if (lst->idx < lst->next->idx && lst->next->idx < lst->next->next->idx)
		{
			rra(stack);
			lst = *stack;
			sa(stack);
		}
		else if (lst->idx < lst->next->idx)
			rra(stack);
		else if (lst->idx > lst->next->idx)
			sa(stack);
		lst = *stack;
	}
	return(*stack);
}

t_lst *four(t_lst **stack_a, t_lst **stack_b)
{
	t_lst *tmp;

	tmp = *stack_a;
	if (tmp->idx < tmp->next->idx && tmp->idx < tmp->next->next->idx
		&& tmp->idx < tmp->next->next->next->idx) // si + petit = head
		{
			pb(stack_a, stack_b);
		}
	else if (tmp->next->next->next->idx < tmp->idx && tmp->next->next->next->idx < tmp->next->idx
			&& tmp->next->next->next->idx < tmp->next->next->idx)	// si + petit dernier
		{
			rra(stack_a);
			pb(stack_a, stack_b);
		}
	else
	{
		while (1)
		{
			tmp = ra(stack_a);
			if (tmp->idx < tmp->next->idx && tmp->idx < tmp->next->next->idx
				&& tmp->idx < tmp->next->next->next->idx)	// si + petit = head
			{
				pb(stack_a, stack_b);
				break;
			}
			tmp = sa(stack_a);
			if (tmp->idx < tmp->next->idx && tmp->idx < tmp->next->next->idx
				&& tmp->idx < tmp->next->next->next->idx)	// si + petit = head
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
t_lst *sort_five(t_lst **stack_a, t_lst **stack_b)
{
	t_lst *t;

	t = *stack_a;
	if (t->idx < t->next->idx && t->idx < t->next->next->idx &&
		t->idx < t->next->next->next->idx && t->idx < t->next->next->next->next->idx) // si + petit = head
		{
			pb(stack_a, stack_b);
		}
	else if (t->next->next->next->next->idx < t->next->idx &&
		t->next->next->next->next->idx < t->next->next->idx &&
		t->next->next->next->next->idx < t->next->next->next->idx)	// si + petit = tail
			{
				rra(stack_a);
				pb(stack_a, stack_b);
			}
	else if ((t->next->next->next->idx < t->idx &&
		t->next->next->next->idx < t->next->idx &&
		t->next->next->next->idx < t->next->next->idx && t->next->next->next->idx < t->next->next->next->next->idx))	// si + petit avant dernier
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if ((t->next->next->idx < t->idx &&
		t->next->next->idx < t->next->idx &&
		t->next->next->idx < t->next->next->next->idx && t->next->next->idx < t->next->next->next->next->idx))
		{
			ra(stack_a);
			ra(stack_a);
		}

	}
}
*/
