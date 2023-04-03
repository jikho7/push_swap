/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:59:26 by jdefayes          #+#    #+#             */
/*   Updated: 2023/04/03 20:09:12 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*create_lst(int ac, char **av, char **res_split)
{
	int		i;
	int		j;
	t_lst	*tmp;
	t_lst	*stack_a;

	i = 0;
	j = 1;
	stack_a = NULL;
	if (ac == 2)
	{
		stack_a = handle_str(res_split);
	}
	else if (ac > 2)
	{
		stack_a = ft_lstnew(ft_atoi(av[1], stack_a));
		i = 2;
		while (i < ac)
		{
			tmp = ft_lstnew(ft_atoi(av[i], stack_a));
			add_back(&stack_a, tmp);
			i++;
		}
	}
	return (stack_a);
}

t_lst	*handle_str(char **str)
{
	int		i;
	int		size_tab;
	long	*tab;
	t_lst	*stack_a;

	i = 0;
	stack_a = NULL;
	size_tab = verif_split(str);
	tab = malloc(sizeof(long) * size_tab);
	while (i < size_tab)
	{
		tab[i] = ft_atoi(str[i], stack_a);
		i++;
	}
	stack_a = generate_lst(stack_a, size_tab, tab, 1);
	check_max_min(tab, size_tab, stack_a);
	free(tab);
	return (stack_a);
}

t_lst	*generate_lst(t_lst *stack, int size, long *tab, int i)
{
	t_lst	*tmp;

	i = 1;
	stack = ft_lstnew(tab[0]);
	while (i < size)
	{
		tmp = ft_lstnew(tab[i]);
		add_back(&stack, tmp);
		i++;
	}
	return (stack);
}

int	verif_split(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if ((tab[i][j] == '-' && tab[i][j + 1] < '0') || ((tab[i][j] == '-'
				&& tab[i][j + 1] > '9')))
				error();
			if ((tab[i][j] == '+' && tab[i][j + 1] < '0') || ((tab[i][j] == '+'
				&& tab[i][j + 1] > '9')))
				error();
			else if ((tab[i][j] > 47 && tab[i][j] < 58) || tab[i][j] == 32
				|| tab[i][j] == 45 || tab[i][j] == '+')
				write(1, "", 0);
			else
				error();
			j++;
		}
		i++;
	}
	return (i);
}
