/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:36:18 by jdefayes          #+#    #+#             */
/*   Updated: 2023/03/29 17:13:27 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_lstnew(int nbr)
{
	t_lst	*new_element;

	new_element = ft_calloc(1, (sizeof(t_lst)));
	if (new_element == NULL)
		return (NULL);
	(*new_element).nbr = nbr;
	new_element->nx = NULL;
	return (new_element);
}

void	add_front(t_lst **head, t_lst *node_to_add)
{
	t_lst	*first_node;

	first_node = *head;
	node_to_add->nx = first_node;
	*head = node_to_add;
}

void	add_back(t_lst **head, t_lst *node_to_add)
{
	t_lst	*current;

	current = *head;
	while (current->nx)
	{
		current = current->nx;
	}
	node_to_add->nx = NULL;
	current->nx = node_to_add;
}

t_lst	*del_first(t_lst **head)
{
	t_lst	*tmp;

	if (head == NULL || *head == NULL)
		return (NULL);
	tmp = *head;
	*head = (*head)->nx;
	tmp->nx = NULL;
	return (tmp);
}

void	ft_lstdelone(t_lst *lst)
{
	lst->nx = NULL;
	free (lst);
}
