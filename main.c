/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:09:20 by jdefayes          #+#    #+#             */
/*   Updated: 2023/04/03 15:59:34 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_order(int *tab, int size);

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
		check_doublon(tab, size, stack_a);
		check_max_min(tab, size, stack_a);
		bubble_sort(tab, size);
		indexation(&stack_a, tab);
	//	printf("size;%d", size);
		check_order(tab, size);
		free(tab);
	//	printf("split tab;%s\n", res_split[0]);
		free_double_tab(res_split, size, ac);
		push_swap(&stack_a, &stack_b, size);
		//display_lst(&stack_a, "sorted");
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
		free(tab);
	}
	else
	{
		free(tab[0]);
	}
}

void	check_max_min(int *tab, int size, t_lst *stack)
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

int	check_order(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] > tab[i - 1])
			i++;
		if (tab[i] < tab[i - 1])
			return (0);
	}
	exit(2);
}
