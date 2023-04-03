/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions_below_5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:59:33 by jdefayes          #+#    #+#             */
/*   Updated: 2023/04/03 21:11:45 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	except_4_order_4(t_lst **stack);

int	exceptions(t_lst **stack)
{
	int	size;
	int	check;
	int	result;

	result = 0;
	size = ft_lstsize(*stack);
	check = in_order(stack, size);
	if (size == 4)
	{
		result = exception_4(stack, check);
	}
	if (size == 5)
	{
		result = exception_5(stack, check);
	}
	return (result);
}

int	exception_5(t_lst **stack, int in_order)
{
	t_lst	*t;

	t = *stack;
	if (in_order == 1)
		return (1);
	if (t->idx > t->nx->idx && t->idx > t->nx->nx->nx->nx->idx
		&& t->idx > t->nx->nx->nx->idx && t->idx > t->nx->nx->idx)
		return (2);
	else if (t->nx->idx > t->idx && t->nx->idx > t->nx->nx->nx->nx->idx
		&& t->nx->idx > t->nx->nx->nx->idx && t->nx->idx > t->nx->nx->idx)
		return (3);
	else if (t->nx->nx->nx->nx->idx > t->nx->idx
		&& t->nx->nx->nx->nx->idx > t->nx->nx->idx
		&& t->nx->nx->nx->nx->idx > t->nx->nx->nx->idx)
		return (4);
	else if (t->nx->nx->nx->idx > t->idx && t->nx->nx->nx->idx > t->nx->idx
		&& t->nx->nx->nx->idx > t->nx->nx->idx
		&& t->nx->nx->nx->idx > t->nx->nx->nx->nx->idx)
		return (5);
	else if (t->nx->nx->idx > t->idx && t->nx->nx->idx > t->nx->idx
		&& t->nx->nx->idx > t->nx->nx->nx->idx
		&& t->nx->nx->idx > t->nx->nx->nx->nx->idx)
		return (6);
	return (0);
}

int	exception_4(t_lst **stack, int in_order)
{
	t_lst	*t;

	t = *stack;
	if (in_order == 1)
		return (1);
	else if (t->idx > t->nx->idx && t->idx > t->nx->nx->idx
		&& t->idx > t->nx->nx->nx->idx)
		return (2);
	else if (t->nx->nx->nx->idx > t->nx->nx->idx && t->nx->nx->nx->idx > t->idx
		&& t->nx->nx->nx->idx > t->nx->idx)
		return (3);
	else if (in_order == 4)
		except_4_order_4(stack);
	return (0);
}

void	except_4_order_4(t_lst **stack)
{
	t_lst	*t;

	t = *stack;
	while (1)
	{
		t = ra(stack);
		if (t->idx > t->nx->idx && t->idx > t->nx->nx->idx
			&& t->idx > t->nx->nx->nx->idx)
			break ;
		t = sa(stack);
		if (t->idx > t->nx->idx && t->idx > t->nx->nx->idx
			&& t->idx > t->nx->nx->nx->idx)
			break ;
	}
}

int	in_order(t_lst **stack, int size)
{
	t_lst	*tmp;

	tmp = *stack;
	if (size == 4)
	{
		if (tmp->idx > tmp->nx->idx && tmp->nx->idx > tmp->nx->nx->idx
			&& tmp->nx->nx->idx > tmp->nx->nx->nx->idx)
			return (1);
	}
	if (size == 5)
	{
		if (tmp->idx > tmp->nx->idx && tmp->nx->idx > tmp->nx->nx->idx
			&& tmp->nx->nx->idx > tmp->nx->nx->nx->idx
			&& tmp->nx->nx->nx->idx > tmp->nx->nx->nx->nx->idx)
			return (1);
	}
	return (0);
}
