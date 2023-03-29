/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:09:20 by jdefayes          #+#    #+#             */
/*   Updated: 2023/03/29 17:05:25 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		*tab;
	int		size;
	char	**res_split;
	t_lst	*stack_a;
	t_lst	*stack_b;

	size = 0;
	if (ac > 1)
	{
		res_split = ft_split(av[1], ' ');
		stack_a = create_lst(ac, av, res_split);
		tab = create_tab(&stack_a, &size);
		bubble_sort(tab, size);
		indexation(&stack_a, tab);
		push_swap(&stack_a, &stack_b, size);
	//	display_lst(&stack_a, "sorted");
		ft_lstclear(&stack_a);
		free(tab);
	}
	else
		return (0);
}
