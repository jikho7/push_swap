/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:28:59 by jdefayes          #+#    #+#             */
/*   Updated: 2023/03/27 22:48:41 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static int	bit_size(int size);

t_lst *push_swap(t_lst **stack_a, t_lst **stack_b, int ac)
{
	int size;

	size = ft_lstsize(*stack_a);
	if (ac <= 6)
	{
		below_5_numbers(stack_a, stack_b, ac);
		return (*stack_a);
	}
	else
		radix_3(stack_a, stack_b, ac);
	return(*stack_a);
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
		tmp = tmp->nx;
		i++;
	}
	return(tab);
}


void indexation(t_lst **lst, int *tab, int size)
{
	int j;
	int k;
	(void)size;
	t_lst *tmp = *lst;
	j = 0;
	k = 1;
	if (tmp != NULL)
	{
		while(tmp->nx)
		{
			while(tmp->nbr != tab[j++])
				k++;
			tmp->idx = k;
			tmp = tmp->nx;
			j = 0;
			k = 1;
		}
			while(tmp->nbr != tab[j++])
				k++;
			tmp->idx = k;
			tmp = tmp->nx;
	}
}

void display_node(t_lst *lst)
{
	if (lst != NULL)
	{
		printf("[%p] {value = %d | indice = %d | nx = %p | back = %p}\n", lst,
			lst->nbr,
			lst->idx,
			lst->nx,
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
	new_element->nx = NULL;
	return (new_element);
}

t_lst	*ft_lstnew_b()
{
	t_lst	*new_element;

	new_element = ft_calloc(1, (sizeof(t_lst)));
	if (new_element == NULL)
		return (NULL);
	new_element->nx = NULL;
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


void radix_3(t_lst **stack_a, t_lst **stack_b, int size)
{
	t_lst *tmp;
	int i;
	int j;
	i = 0;
	tmp = *stack_a;

	while (i < bit_size(size - 1)) // idx max = ac - 1
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
			{
				pb(stack_a, stack_b);
			}
			j++;
		}

		while(*stack_b)
		{
			pa(stack_a, stack_b);
		}
		i++;
	}
}

static int	bit_size(int size)
{
	int	bit_max;

	bit_max = 0;
	while (size >> bit_max)
		bit_max++;
	return (bit_max);
}
