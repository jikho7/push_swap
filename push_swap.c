/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:28:59 by jdefayes          #+#    #+#             */
/*   Updated: 2023/02/22 11:20:49 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
/*
int main (int ac, char	**av)
{
	int c = 0;
	char name[] = "liste A";
	t_lst *element;
	t_lst *head;

	t_data data = {1, 0, 0, 0, NULL, &av[data.i]};
	data.tab = malloc(sizeof(int) * ac);
	data.i = 1;
	while (av[data.i])
	{
		data.tab[data.j] = atoi(av[data.i++]);
		data.size++;
		//printf("CONVERSION:%d\n", data.tab[data.j]);
		data.j++;
	}
	data.j = 0;
	bubble_sort(data.tab, data.size);
	//while (data.j < data.size)
	// 	printf("SORTED:%d\n", data.tab[data.j++]);
	data.j = 0;

	element = ft_lstnew(&data);
	printf("first node:\n");
	display_node(element);
	head = element;
	//printf("first node copy:\n");
	//display_node(head);

	while(c < ac - 2)
	{
		push_end(element, &data);
		display_node(element->next);
		data.j++;
		element = element->next;
		c++;
	}
	display_lst(&head, name);
}
*/

int main ()
{
	int j;
	int tab_test[7] = {42,-98,47,21,6578,214748,0};

	t_lst *lst;
	lst = ft_lstnew(tab_test[0]);
	t_lst *tmp;

	int i = 1;
	while (i < 7)
	{
		tmp = ft_lstnew(tab_test[i]);
		add_front2(&lst, tmp);
		i++;
	}

	display_lst(&lst, "name");
	swap2(&lst);
	printf("\n");
	display_lst(&lst, "name");

	bubble_sort(tab_test, 7);
	j = 0;
	while(j < 7)
	{
		printf("%d\n", tab_test[j]);
		j++;
	}
	j = 0;
	tmp = lst;
	if (tmp != NULL)
	{
		while(tmp->next)
		{
			while(tmp->nbr != tab_test[j])
				j++;
			tmp->idx = j;
			tmp = tmp->next;
			j = 0;
		}
			while(tmp->nbr != tab_test[j])
				j++;
			tmp->idx = j;
			tmp = tmp->next;
	}
display_lst(&lst, "name");
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

