/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   below_5_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:22:36 by jdefayes          #+#    #+#             */
/*   Updated: 2023/03/07 17:06:17 by jdefayes         ###   ########.fr       */
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
	// if (ac == 6)
	// 	five();
	ft_lstclear(stack_b);
	return(*stack_a);
}

t_lst *three(t_lst **stack)
{
	t_lst *lst;

	lst = *stack;
	if (lst->idx < lst->next->idx && lst->idx > lst->next->next->idx)
	{
		rra(stack);
		lst = *stack;
	}
	else if (lst->idx > lst->next->idx && lst->idx < lst->next->next->idx)
	{
		sa(stack);
		lst = *stack;
	}
	while (lst->idx > lst->next->idx || lst->next->idx > lst->next->next->idx)
	{
		if (lst->idx > lst->next->idx && lst->next->idx > lst->next->next->idx)
		{
			ra(stack);
			lst = *stack;
			sa(stack);
		}
		else if (lst->idx > lst->next->idx)
			ra(stack);
		else if (lst->idx < lst->next->idx)
			sa(stack);
		lst = *stack;
	}
	//lst = *stack;
	return(*stack);
}

t_lst **two(t_lst **stack)
{
	t_lst *lst;
	lst = *stack;
	if (lst->idx > lst->next->idx)
	{
		sa(stack);
	}
	return (stack);
}

t_lst *four(t_lst **stack_a, t_lst **stack_b)
{
	t_lst *tmp;
	t_lst *l_b;

	tmp = *stack_a;
	l_b = *stack_b;
	if (tmp->idx < tmp->next->idx && tmp->idx < tmp->next->next->idx
		&& tmp->idx < tmp->next->next->next->idx)
		{
			// si + petit = head
			pb(stack_a, stack_b);
		//	tmp = *stack_a;
		//	l_b = *stack_b;
		}
	else if (tmp->next->next->next->idx < tmp->idx && tmp->next->next->next->idx < tmp->next->idx
			&& tmp->next->next->next->idx < tmp->next->next->idx)
		{
			// si + petit dernier
			rra(stack_a);
			tmp = *stack_a;
			pb(stack_a, stack_b);
		//	tmp = *stack_a;
		//	l_b = *stack_b;
		}
	else
	{
		while (1)
		{

			ra(stack_a);
			tmp = *stack_a;

			if (tmp->idx < tmp->next->idx && tmp->idx < tmp->next->next->idx
				&& tmp->idx < tmp->next->next->next->idx)
			{
				// si + petit = head
				pb(stack_a, stack_b);
			//	tmp = *stack_a;
			//	l_b = *stack_b;
				break;
			}
			sa(stack_a);
			tmp = *stack_a;

			if (tmp->idx < tmp->next->idx && tmp->idx < tmp->next->next->idx
				&& tmp->idx < tmp->next->next->next->idx)
			{
				// si + petit = head
				pb(stack_a, stack_b);
				//l_b = *stack_b;
				//tmp = *stack_a;
				break;
			}
		}
	}
	tmp = *stack_a;
	l_b = *stack_b;
	three(stack_a);
	pa(stack_a, stack_b);
return(*stack_a);
}

// pronleme avec entree 2143, nb 3412
/*
	else if (tmp->idx > tmp->next->idx)
		{
		//	printf("LAST IF\n");
			ra(stack_a);
			tmp = *stack_a;
			if (tmp->idx > tmp->next->idx)
			{
				sa(stack_a);
		//		printf("AFETR SA\n");
			}
		//	display_lst(stack_a, "STACK A");
		//	display_lst(stack_b, "STACK B");
			tmp = *stack_a;
			if (tmp->idx < tmp->next->idx && tmp->idx < tmp->next->next->idx && tmp->idx < tmp->next->next->next->idx)
			{
			//	printf("SA LAST\n");
				sa(stack_a);
			}
		}


		tmp = *stack_a;
		three(stack_a);
	pa(stack_a, stack_b);
	return(*stack_a);
}
*/

// probleme avec 4321, 2143, 2431,
// t_lst *five()
// {

// }
