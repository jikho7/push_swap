/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:28:59 by jdefayes          #+#    #+#             */
/*   Updated: 2023/04/03 15:24:52 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bit_size(int size);

t_lst	*push_swap(t_lst **stack_a, t_lst **stack_b, int size)
{
	int	ac;

	ac = size + 1;
	if (size < 6)
	{
		below_5_numbers(stack_a, stack_b, ac);
		return (*stack_a);
	}
	else
		radix(stack_a, stack_b, ac);
//	printf("plop\n");
	ft_lstclear(stack_b);
//	printf("end pushswap\n");
	return (*stack_a);
}

void	radix(t_lst **stack_a, t_lst **stack_b, int size)
{
	t_lst	*tmp;
	int		i;
	int		j;

	i = 0;
	tmp = *stack_a;
	while (i < bit_size(size - 1))
	{
		j = 0;
		while (j < size - 1)
		{
			tmp = *stack_a;
			if ((tmp->idx >> i & 1) == 0)
			{
				ra(stack_a);
			}
			else if ((tmp->idx >> i & 1) == 1)
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
//	printf("end radix\n");
}

static int	bit_size(int size)
{
	int	bit_max;

	bit_max = 0;
	while (size >> bit_max)
		bit_max++;
	return (bit_max);
}
