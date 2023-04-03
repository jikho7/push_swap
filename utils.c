/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:04:16 by jdefayes          #+#    #+#             */
/*   Updated: 2023/04/03 15:48:33 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *tab, int size)
{
	int	tmp;
	int	i;
	int	swap;

	i = 0;
	swap = 1;
	while (swap >= 1)
	{
		swap = 0;
		while (i < size - 1)
		{
			if (tab[i] < tab [i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				swap++;
			}
			i++;
		}
		i = 0;
	}
}

int	*create_tab(t_lst **lst, int *ptr)
{
	t_lst	*tmp;
	int		*tab;
	int		i;
	int		size;

	i = 0;
	size = ft_lstsize(*lst);
	tab = malloc(sizeof(int) * size);
//	printf("adresse create tab; %p\n", tab);
	tmp = *lst;
	while (i < size)
	{
		tab[i] = tmp->nbr;
		tmp = tmp->nx;
		i++;
	}
	*ptr = size;
	return (tab);
}

void	indexation(t_lst **lst, int *tab)
{
	int		j;
	int		k;
	t_lst	*tmp;

	tmp = *lst;
	j = 0;
	k = 1;
	if (tmp != NULL)
	{
		while (tmp->nx)
		{
			while (tmp->nbr != tab[j++])
				k++;
			tmp->idx = k;
			tmp = tmp->nx;
			j = 0;
			k = 1;
		}
		while (tmp->nbr != tab[j++])
			k++;
		tmp->idx = k;
		tmp = tmp->nx;
	}
}

t_lst	*rra_twice(t_lst **stack)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		rra(stack);
		i++;
	}
	return (*stack);
}

void	ft_lstclear(t_lst **lst)
{
	t_lst	*temp;

	if (lst)
	{
		while (*lst)
		{
			temp = (*lst)->nx;
			ft_lstdelone(*lst);
			(*lst) = temp;
		}
	}
	else
		*lst = NULL;
}
