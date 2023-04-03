/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_n_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:06:39 by jdefayes          #+#    #+#             */
/*   Updated: 2023/04/03 20:10:36 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_doublon(long *tab, int size, t_lst *stack_a)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < size)
	{
		i = 1 + j;
		while (i < size)
		{
			if (tab[i] == tab[j])
			{
				free(tab);
				ft_lstclear(&stack_a);
				error();
			}
			i++;
		}
		j++;
	}
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

int	check_order(t_lst **stack)
{
	t_lst	*current;

	current = *stack;
	while (current && current->nx)
	{
		if (current->idx > current->nx->idx)
			current = current->nx;
		if (current->nx && current->idx < current->nx->idx)
			return (1);
	}
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

void	error(void)
{
	write(2, "Error\n", 6);
	exit(2);
}
