/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:09:20 by jdefayes          #+#    #+#             */
/*   Updated: 2023/03/20 20:17:07 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int main (int ac, char **av)
{
	int *tab;
	int i;
	t_lst *tmp;
	t_lst *stack_a;
	t_lst *stack_b;
	if (ac > 1)
	{
		stack_a = ft_lstnew(atoi(av[1]));
		i = 2;
		while (i < ac)
		{
			tmp = ft_lstnew(atoi(av[i]));
			add_back2(&stack_a, tmp);
			i++;
		}
		tab = create_tab(&stack_a, ac);
		bubble_sort(tab, ac - 1);
		indexation(&stack_a, tab);
		//display_lst(&stack_a, "STACK A");
		//rra(&stack_a);
		//printf("After SA");
		//display_lst(&stack_a, "STACK A");
		//display_lst(&stack_b, "STACK B");
		push_swap(&stack_a, &stack_b, ac);

		//display_lst(&stack_a, "STACK A");
		//display_lst(&stack_b, "STACK B");
	}
	else
		return (0);
}
