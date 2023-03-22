/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:28:59 by jdefayes          #+#    #+#             */
/*   Updated: 2023/03/22 18:23:52 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void verify_halving(t_lst **stack_a, t_lst **stack_b, int ac);
void finish(t_lst **stack_a, t_lst **stack_b);
void radix(t_lst **stack_a, t_lst **stack_b);
void sort_3(t_lst **stack_a, t_lst **stack_b);
int swap_a(t_lst **stack_a, int *check_a);
int rotate_a(t_lst **stack_a, int *check_a);
void sort_a(t_lst **stack_a);
void radix_2(t_lst **stack_a, t_lst **stack_b);
void convert_to_bits(int idx, int *tab);

t_lst *push_swap(t_lst **stack_a, t_lst **stack_b, int ac)
{
	int size;
//	t_lst *tmp_a;
//	t_lst *tmp_b;
//	int a = 1;
//	int b = 1;
//	int *check_a = &a;
//	int *check_b = &b;

	size = ft_lstsize(*stack_a);
	if (ac <= 6)
	{
		below_5_numbers(stack_a, stack_b, ac);
		return (*stack_a);
	}
	else
	{
		radix_2(stack_a, stack_b);
	//	display_lst(stack_a, "RADIX 1 step A");
	//	display_lst(stack_b, "RADIX 1step B");
	}
	/*
	else
	{
		halving(stack_a, stack_b, ac);
		verify_halving(stack_a, stack_b, ac);
	//	display_lst(stack_b, "Halving B");
	//	display_lst(stack_a, "Halving A");

		while (*check_a == 1 || *check_b == 1)
		{
			tmp_a = *stack_a;
			tmp_b = *stack_b;
			//printf("before check a; %d\n", *check_a);
			//printf("brefore check b; %d\n", *check_b);
			if(*check_a == 1)
				check_a = check_order(stack_a, 'a', check_a);
			if(*check_b == 1)
				check_b = check_order(stack_b, 'b', check_b);
			if(*check_a == 2 && *check_b == 2)
				break;
		//	printf("check a; %d\n", *check_a);
		//	printf("check b; %d\n", *check_b);
			if(tmp_a->idx == 0)
			{
				ra(stack_a);
			}
			if(tmp_b->idx == size - 1)
			{
				rb(stack_b);
			}
			if (*check_a == 1 || *check_b == 1)
			{
				rotate(stack_a, stack_b, size, check_a, check_b);
	//			display_lst(stack_a, "AFTER RO BOUCLE A");
	//			display_lst(stack_b, "AFTER RO BOUCLE B");
				swap(stack_a, stack_b, size, check_a, check_b);
	//			display_lst(stack_a, "AFTER SWAP BOUCLE A");
	//			display_lst(stack_b, "AFTER SWAP BOUCLE B");
			}
		}
	}
	*/
	//finish(stack_a, stack_b);
	return(*stack_a);
}

void finish(t_lst **stack_a, t_lst **stack_b)
{
	t_lst *tmp_b;

	tmp_b = *stack_b;
	while(tmp_b)
	{
		pa(stack_a, stack_b);
		tmp_b = tmp_b->nx;
	}
	pa(stack_a, stack_b);
}
void halving(t_lst **stack_a, t_lst **stack_b, int ac)
{
	t_lst *tmp_a;
	int count;
	int i;
	int j;
	int multi;
	int grow;
	int ac_maj;
	t_lst *last_a;

	tmp_a = *stack_a;
	i = 0;
	count = 0;
	grow = 0;
	ac_maj = ac;
	multi = set_multi(ac);
	while(i < (ac / 2))
	{
		while(tmp_a != NULL && i < (ac / 2))
		{
			if (tmp_a->idx >= ((ac / 2) - grow))
			{
				j = 0;
				if (count <= (ac / 2))
				{
					while (j < count)
					{
						ra(stack_a);
						j++;
					}
				}
				else if (count > (ac / 2))
				{
					while(j < (ac_maj - 1) - count)
					{
						rra(stack_a);
						j++;
					}
				}
				pb(stack_a, stack_b);
				ac_maj = ac_maj - 1;
			//	printf("AC :%d\n", ac_maj);
				i++;
				tmp_a = *stack_a;
				count = 0;
				//display_lst(stack_a, "A");
				//display_lst(stack_b, "B");
			}
			else
			{
				tmp_a = tmp_a->nx;
				count++;
			//	printf("ELSE count :%d\n", count);
			}

		}
		//printf("I :%d\n", i);
		//printf("count :%d\n", count);
		grow = grow + multi;
		//printf("grow :%d\n", grow);
		count = 0;
		tmp_a = *stack_a;
	}
	last_a = ft_lstlast(*stack_a);
//	display_node(last_a);
	//display_lst(stack_a, "A");
	//display_lst(stack_b, "B");
}

int set_multi(int size)
{
	if (size <= 10)
		return (1);
	if (size > 10 && size <= 20)
		return (2);
	if (size > 20 && size <= 100)
		return (5);
	if (size > 100 && size <= 500)
		return (12);
	return (0);
}

void verify_halving(t_lst **stack_a, t_lst **stack_b, int ac)
{
	t_lst *tmp;
	int count;

	tmp = *stack_a;
	count = 0;
	while(tmp->nx)
	{
		if(tmp->idx >= ((ac / 2) - 1))
		{
			while(count > 0)
			{
				ra(stack_a);
				count--;
			}
			pb(stack_a, stack_b);
			break;
		}
		tmp = tmp->nx;
		count++;
	}
}

int *check_order(t_lst **stack, char which_stack, int *check)
{
	t_lst *t;

	t = *stack;
	if (which_stack == 'a')
	{
		while (t->nx != NULL)
		{
			if(t->idx < t->nx->idx)
			{
				*check = 1;
				return(check);
			}
			t = t->nx;
		}
	}
	else if (which_stack == 'b')
	{
		while (t->nx != NULL)
		{
			if(t->idx > t->nx->idx)
			{
				*check = 1;
				return(check);
			}
			t = t->nx;
		}
	}
	*check = 2;
	return (check);
}

int rotate(t_lst **stack_a, t_lst **stack_b, int total_size, int *check_a, int *check_b)
{
	t_lst *tmp_a;
	t_lst *tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	if(tmp_a->idx == 0 && *check_a == 1)
	{
		ra(stack_a);
		tmp_a = *stack_a;
	//	printf("RA idx == 0\n");
	}
	if(tmp_b->idx == total_size - 1 && *check_b == 1)
	{
		rb(stack_b);
		tmp_b = *stack_b;
	//	printf("RB idx == max\n");
	}
	if (tmp_a->idx > tmp_a->nx->idx && tmp_b->idx < tmp_b->nx->idx && (*check_a == 1 && *check_b == 1))
	{
		rr(stack_a, stack_b);
	//	printf("rr ROTATE\n");	modif b
		return (1);
	}
	else if (tmp_a->idx > tmp_a->nx->idx && *check_a == 1)
	{
		ra(stack_a);
	//	printf("ra ROTATE\n");		modif b
		return (1);
	}
	else if (tmp_b->idx < tmp_b->nx->idx && *check_b == 1)
	{
		rb(stack_b);
	//	printf("rb ROTATE\n");
		return (1);
	}
	return (0);
}

int swap(t_lst **stack_a, t_lst **stack_b, int total_size, int *check_a, int *check_b)
{
	t_lst *tmp_a;
	t_lst *tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	if(tmp_a->idx == 0 && *check_a == 1)
	{
		ra(stack_a);
		tmp_a = *stack_a;
//		printf("RA idx, swap == 0\n");
	}
	if(tmp_b->idx == total_size - 1 && *check_b == 1)
	{
		rb(stack_b);
		tmp_b = *stack_b;
	//	printf("RB idx, swap == max\n");
	}
	if (tmp_a->idx < tmp_a->nx->idx && tmp_b->idx > tmp_b->nx->idx && (*check_a == 1 && *check_b == 1))
	{
		ss(stack_a, stack_b);
	//	printf("ss SWAP\n");
		return (1);
	}
	else if (tmp_a->idx < tmp_a->nx->idx && *check_a == 1)
	{
		sa(stack_a);
	//	printf("sa SWAP\n");
		return(1);
	}
	else if (tmp_b->idx > tmp_b->nx->idx && *check_b == 1)
	{
		sb(stack_b);
	//	printf("sb SWAP\n");
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
		tmp = tmp->nx;
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
		while(tmp->nx)
		{
			while(tmp->nbr != tab[j])
				j++;
			tmp->idx = j;
			tmp = tmp->nx;
			j = 0;
		}
			while(tmp->nbr != tab[j])
				j++;
			tmp->idx = j;
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

void sort_a(t_lst **stack_a)
{
	t_lst *tmp;
	int a = 1;
	int *check_a = &a;

	tmp = *stack_a;
	while (*check_a == 1)
	{
		if(*check_a == 1)
			check_a = check_order(stack_a, 'a', check_a);
		if(*check_a == 2)
			break;
		if(tmp->idx == 0)
		{
			ra(stack_a);
		}
		if (*check_a == 1)
		{
			rotate_a(stack_a, check_a);
			swap_a(stack_a, check_a);
		}
	}
}

int rotate_a(t_lst **stack_a, int *check_a)
{
	t_lst *tmp_a;

	tmp_a = *stack_a;
	if(tmp_a->idx == 0 && *check_a == 1)
	{
		ra(stack_a);
//		printf("ra rotate\n");
		tmp_a = *stack_a;
	}
	else if (tmp_a->idx > tmp_a->nx->idx && *check_a == 1)
	{
		ra(stack_a);
//		printf("ra rotate\n");
		return (1);
	}
//	display_lst(stack_a, "ROTATE A");
	return (0);
}

int swap_a(t_lst **stack_a, int *check_a)
{
	t_lst *tmp_a;

	tmp_a = *stack_a;
	if(tmp_a->idx == 0 && *check_a == 1)
	{
		ra(stack_a);
//		printf("ra swap\n");
		tmp_a = *stack_a;
	}
	else if (tmp_a->idx < tmp_a->nx->idx && *check_a == 1)
	{
		sa(stack_a);
//		printf("sa swap\n");
		return(1);
	}
//	display_lst(stack_a, "SWAP A");
	return (0);
}

void radix_2(t_lst **stack_a, t_lst **stack_b)
{
	t_lst *tmp_a;
	t_lst *tmp_b;
	int i = 0;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	while(tmp_a)
	{
		//printf("CONVERT\n");
		convert_to_bits(tmp_a->idx, tmp_a->tab);
		while(i < 9)
		{
			printf("%d", tmp_a->tab[i]);
			i++;
		}
		printf("\n");
		tmp_a = tmp_a->nx;
		i = 0;
	}

}

void convert_to_bits(int idx, int *tab)
{
	int to_add;
	int i;
	//int tab[9] = {0,0,0,0,0,0,0,0,0};
	float res;

	i = 8;
	while(i >= 0)
	{
		//printf("which idx;%d\n", idx);
		if (idx > 0)
		{
			res = idx / 2;
		//	printf("idx; %d\n", idx);
			if (idx % 2 == 1 || (res < 1 && res != 0))
				to_add = 1;
			else if (idx % 2 == 0)
				to_add = 0;
			tab[i] = to_add;
			//printf("tab: %d\n",tab[i]);
			idx = (int)res;
		}
		i--;
	}
}
