/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:28:59 by jdefayes          #+#    #+#             */
/*   Updated: 2023/03/07 20:33:26 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

t_lst *push_swap(t_lst **stack_a, t_lst **stack_b, int ac)
{
	int ro;
	int sw;

	sw = 1;
	ro = 1;
	//printf("entry push_swap function\n");
	if (ac < 7)
	{
		below_5_numbers(stack_a, stack_b, ac);
		//printf("Below 5 done\n");
		return (*stack_a);
	}
	halving(stack_a, stack_b, ac);
	while (ro == 1 || sw == 1)
	{
		ro = rotate(stack_a, stack_b);
		sw = swap(stack_a, stack_b);
		//printf("push_swap\n");
	}
	return(*stack_a);
}

void halving(t_lst **stack_a, t_lst **stack_b, int ac)
{
	t_lst *tmp_a;
	int size;
	int i;
	int multi;

	tmp_a = *stack_a;
	i = 1;
	multi = 10;
	size = ac / 2;
	//printf("size: %d\n", size);
	while(i < (ac / 2))
	{
		while(tmp_a != NULL)
		{
			if (tmp_a->idx < multi)
			{
				pb(stack_a, stack_b);
				i++;
			}
			tmp_a = tmp_a->next;
		}
		multi = multi + 20;
		tmp_a = *stack_a;
	}
}


int rotate(t_lst **stack_a, t_lst **stack_b)
{
	t_lst *tmp_a;
	t_lst *tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;

	if (tmp_a->idx > tmp_a->next->idx && tmp_b->idx < tmp_b->next->idx)
	{
		rr(stack_a, stack_b);
		printf("RR\n");
		return (1);
	}
	if (tmp_a->idx > tmp_a->next->idx && tmp_b->idx > tmp_b->next->idx)
	{
		ra(stack_a);
		printf("RA\n");
		return (1);
	}
	if (tmp_a->idx < tmp_a->next->idx && tmp_b->idx < tmp_b->next->idx)
	{
		rb(stack_b);
		printf("RB\n");
		return (1);
	}
	return (0);
}

int swap(t_lst **stack_a, t_lst **stack_b)
{
	t_lst *tmp_a;
	t_lst *tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;

	if (tmp_a->idx < tmp_a->next->idx && tmp_b->idx > tmp_b->next->idx)
	{
		ss(stack_a, stack_b);
		return (1);
	}
	if (tmp_a->idx < tmp_a->next->idx && tmp_b->idx < tmp_b->next->idx)
	{
		sa(stack_a);
		return(1);
	}
	if (tmp_a->idx > tmp_a->next->idx && tmp_b->idx > tmp_b->next->idx)
	{
		sb(stack_b);
		return(1);
	}
	return (0);
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
	return (new_element);
}

t_lst	*ft_lstnew_b()
{
	t_lst	*new_element;

	new_element = ft_calloc(1, (sizeof(t_lst)));
	if (new_element == NULL)
		return (NULL);
	new_element->next = NULL;
	return (new_element);
}
void display_lst(t_lst **ptr_to_head, char *name)
{
	t_lst *current_node;
	int count;
	current_node = *ptr_to_head;




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

// ROTATE
// RR si
// 	- A: 	nbr1 > nbr2 ( 433, 412, 401) -> 412, 401, 433.
// &&
// 	- B: nbr1 < nbr2 (5, 12, 24) -> 12, 24, 5.


// RA si
// 	- A: 	nbr1 > nbr2 ( 433, 412, 401) -> 412, 401, 433.
// &&
// 	- B: nbr1 > nbr2 (12, 5, 14)


// RB si
// 	- A: 	nbr1 < nbr2 ( 412, 433, 401)
// &&
// 	- B: nbr1 < nbr2 (5, 12, 24) -> 12, 24, 5.


// SWAP
// SS si
// 	- A: 	nbr1 < nbr2 ( 412, 433, 401) -> 433, 412, 401
// &&
// 	- B: nbr1 > nbr2 (12, 5,  24) -> 5, 12, 24.


// SA si
// 	- A: 	nbr1 < nbr2 ( 412, 433, 401) -> 433, 412, 401
// &&
// 	- B: nbr1 < nbr2 (5, 12, 14)


// SB si
// 	- A: 	nbr1 > nbr2 ( 433, 412, 401)
// &&
// 	- B: nbr1 > nbr2 (12, 5, 24) -> 5, 12, 24
