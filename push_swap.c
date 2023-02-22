/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:28:59 by jdefayes          #+#    #+#             */
/*   Updated: 2023/02/22 14:12:57 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void indexation(t_lst **lst, int *tab);
int *create_tab(t_lst **lst, int size);

int main (int ac, char **av)
{
	int *tab;
	int i;
	t_lst *tmp;
	t_lst *lst;

	lst = ft_lstnew(atoi(av[1]));
	i = 2;
	while (i < ac)
	{
		tmp = ft_lstnew(atoi(av[i]));
		add_front2(&lst, tmp);
		i++;
	}
	display_lst(&lst, "LIST CREATED");
	tab = create_tab(&lst, ac);

	//swap2(&lst);
	printf("\n");
	//display_lst(&lst, "swaped");
	bubble_sort(tab, ac - 1);
	indexation(&lst, tab);
	display_lst(&lst, "FIN");
}

int *create_tab(t_lst **lst, int size)
{
	t_lst *tmp;
	int *tab;
	int i;

	i = 0;
	tab = malloc(sizeof(int) * size - 1);
	tmp = *lst;
	while (i < size - 1)
	{
		tab[i] = tmp->nbr;
		tmp = tmp->next;
		i++;
	}
	return(tab);
}


void indexation(t_lst **lst, int *tab)
{
	int j;
	t_lst *tmp = *lst;

	j = 0;
	if (tmp != NULL)
	{
		while(tmp->next)
		{
			while(tmp->nbr != tab[j])
				j++;
			tmp->idx = j;
			tmp = tmp->next;
			j = 0;
		}
			while(tmp->nbr != tab[j])
				j++;
			tmp->idx = j;
			tmp = tmp->next;
	}
}


void display_node(t_lst *lst)
{
	if (lst != NULL)
	{
		printf("[%p] {value = %d | indice = %d | next = %p | back = %p}\n", lst,
			lst->nbr,
			lst->idx,
			lst->next,
			lst->back);
	}
}

t_lst	*ft_lstnew(int nbr)
{
	t_lst	*new_element;

	new_element = ft_calloc(1, (sizeof(t_lst)));
	if (new_element == NULL)
		return (NULL);

	(*new_element).nbr = nbr;
	new_element->next = NULL;
	//new_element->back = NULL;
	//new_element->idx = 0;

	return (new_element);
}

void display_lst(t_lst **ptr_to_head, char *name)
{
	t_lst *current_node;
	int count;
	current_node = *ptr_to_head;
	count = 0;
	printf("\n%s :\n", name);
	if (*ptr_to_head != NULL)
	{
		while (current_node->next != NULL)
		{
			printf("Index = %d : ", count);
			display_node(current_node);
			current_node = current_node->next;
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

