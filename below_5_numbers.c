/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   below_5_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:22:36 by jdefayes          #+#    #+#             */
/*   Updated: 2023/03/01 16:49:05 by jdefayes         ###   ########.fr       */
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
	//if (ac == 5)
	//	four(stack_a, stack_b);
	// if (ac == 6)
	// 	five();
	return(*stack_a);
}

t_lst *three(t_lst **stack)
{
	t_lst *lst;

	lst = *stack;
	printf("three function\n");
	// 132
	if (lst->idx < lst->next->idx && lst->idx > lst->next->next->idx)
	{
		rra(stack);
		// entree -> 132, liste -> 231
		printf("231 exception\n");
	}
	else if (lst->idx > lst->next->idx && lst->idx < lst->next->next->idx)
	{
		sa(stack);
		// entree -> 312, liste 213
		//printf("SA done\n");
		printf("exception\n");
	}
	else
	{
		printf("else\n");
		while ((lst->idx < lst->next->idx && lst->idx < lst->next->next->idx) || (lst->next->idx < lst->next->next->idx))
		{
			if (lst->idx > lst->next->idx)
			{
				ra(stack);
				lst = *stack;
				printf("ra else\n");
			}

			else if (lst->idx < lst->next->idx)
			{
				sa(stack);
				lst = *stack;
				printf("sa else\n");
			}
		//return(*stack);
		}
	}
	return(*stack);
}

t_lst **two(t_lst **stack)
{
	t_lst *lst;
	lst = *stack;
	//printf("two function\n");
	if (lst->idx > lst->next->idx)
	{
		sa(stack);
	}
	return (stack);
}

t_lst *four(t_lst **stack_a, t_lst **stack_b)
{
	t_lst *tmp;
	//t_lst *l_b;
	// 3142
	tmp = *stack_a;
	if (tmp->idx < tmp->next->idx && tmp->idx < tmp->next->next->idx
		&& tmp->idx < tmp->next->next->next->idx)
		{
			// si + petit = head
			pb(stack_a, stack_b);
		//	printf("PB begin done\n");
			//three(stack_a); deja un three en bas de fonction
		//	printf("three begin done\n");
		}
	else if (tmp->next->next->next->idx < tmp->idx && tmp->next->next->next->idx < tmp->next->idx
			&& tmp->next->next->next->idx < tmp->next->next->idx)
		{
			// si + petit dernier
			rra(stack_a);
		//	printf("RRA third done\n");
			pb(stack_a, stack_b);
			//printf("PB third done\n");
		}
	tmp = *stack_a;
	if (tmp->idx > tmp->next->idx)
		{
			printf("LAST IF\n");
			ra(stack_a);
			tmp = *stack_a;
			if (tmp->idx > tmp->next->idx)
			{
				sa(stack_a);
				printf("AFETR SA\n");
			}
			display_lst(stack_a, "STACK A");
			display_lst(stack_b, "STACK B");
			tmp = *stack_a;
			if (tmp->idx < tmp->next->idx && tmp->idx < tmp->next->next->idx && tmp->idx < tmp->next->next->next->idx)
			{
				printf("SA LAST\n");
				sa(stack_a);
			}
		}
		tmp = *stack_a;
		three(stack_a);
	pa(stack_a, stack_b);
	return(*stack_a);
}
// probleme avec 4321, 2143, 2431,
// t_lst *five()
// {

// }
