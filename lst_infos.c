/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:16:57 by jdefayes          #+#    #+#             */
/*   Updated: 2023/04/03 17:47:48 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_lst *lst)
{
	int	nbr_element;

	nbr_element = 0;
	while (!lst)
		return (0);
	while (lst)
	{
		nbr_element++;
		lst = lst->nx;
	}
	return (nbr_element);
}

t_lst	*ft_lstlast(t_lst *lst)
{
	if (lst != NULL)
	{
		while (lst->nx)
			lst = lst->nx;
		return (lst);
	}
	else
		return (lst);
}

void	display_lst(t_lst **ptr_to_head, char *name)
{
	t_lst	*current_node;
	int		count;

	current_node = *ptr_to_head;
	count = 0;
	printf("\n%s :\n", name);
	if (*ptr_to_head != NULL)
	{
		while (current_node->nx != NULL)
		{
			printf("Index = %d : ", count);
			display_node(current_node);
			current_node = current_node->nx;
			count++;
		}
		printf("Index = %d : ", count);
		display_node(current_node);
	}
	else
	{
		printf("The stack is empty.\n");
	}
	printf("\n");
}

void	display_node(t_lst *lst)
{
	if (lst != NULL)
	{
		printf("[%p] {value = %ld | indice = %d | nx = %p}\n", lst,
			lst->nbr,
			lst->idx,
			lst->nx);
	}
}
