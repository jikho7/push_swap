/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:09:20 by jdefayes          #+#    #+#             */
/*   Updated: 2023/04/03 19:28:18 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	long	*tab;
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
		check_doublon(tab, size, stack_a);
		check_max_min(tab, size, stack_a);
		bubble_sort(tab, size);
		indexation(&stack_a, tab);
		free(tab);
		free_double_tab(res_split, size, ac);
		push_swap(&stack_a, &stack_b, size);
		ft_lstclear(&stack_a);
	}
	else
		return (0);
}

void	free_double_tab(char **tab, int size, int ac)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (i < size)
		{
			free(tab[i]);
			i++;
		}
	}
	else
		free(tab[0]);
	free(tab);
}

void	check_max_min(long *tab, int size, t_lst *stack)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] > 2147483647 || tab[i] < -2147483648)
		{
			free(tab);
			ft_lstclear(&stack);
			error();
		}
		i++;
	}
}
