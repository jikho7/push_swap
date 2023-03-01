/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_piles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:11:11 by jdefayes          #+#    #+#             */
/*   Updated: 2023/03/01 15:51:36 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void pb(t_lst **stack_a, t_lst **stack_b);

/*
sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
Ne fait rien s’il n’y en a qu’un ou aucun.
sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
Ne fait rien s’il n’y en a qu’un ou aucun.
ss : sa et sb en même temps.
pa (push a) : Prend le premier élément au sommet de b et le met sur a.
Ne fait rien si b est vide.
pb (push b) : Prend le premier élément au sommet de a et le met sur b.
Ne fait rien si a est vide.
ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier.
rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
Le premier élément devient le dernier.
rr : ra et rb en même temps.

rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier.
rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
la pile b. Le dernier élément devient le premier.
rrr : rra et rrb en même temps.*/


void sa(t_lst **head)
{
	t_lst *tmp;
	t_lst *first_node;
	t_lst *second_node;

	tmp = *head;
		if(tmp->next != NULL)
		{
			first_node = del_first(head);
			second_node = del_first(head);
			add_front2(head, first_node);
			add_front2(head, second_node);
			//printf("After swap, stack A:\n");
			//printf("First element: %d\nSecond element: %d\n", second_node->nbr, first_node->nbr);
		}
		else
			printf("No swap\n");
		printf("SA\n");
}

void sb(t_lst **head)
{
	t_lst *tmp;
	t_lst *first_node;
	t_lst *second_node;

	tmp = *head;
		if(tmp != NULL && tmp->next != NULL)	// segementation fault with if(tmp->next != NULL && tmp != NULL)
		{
			first_node = del_first(head);
			second_node = del_first(head);
			add_front2(head, first_node);
			add_front2(head, second_node);
		//	printf("After swap, stack B:\n");
		//	printf("First element: %d\nSecond element: %d\n", second_node->nbr, first_node->nbr);
		}
		else
			printf("No swap\n");
		printf("SB\n");
}

void pb(t_lst **stack_a, t_lst **stack_b)
{
	t_lst *to_move;
	t_lst *tmp;

	tmp = *stack_a;
	if(tmp !=  NULL)
	{
		to_move = del_first(stack_a);
		add_front2(stack_b, to_move);
	}
	else
		printf("no push B\n");
	printf("PB\n");
}

void pa(t_lst **stack_a, t_lst **stack_b)
{
	t_lst *to_move;
	t_lst *tmp;

	tmp = *stack_b;
	if(tmp !=  NULL)
	{
		to_move = del_first(stack_b);
		add_front2(stack_a, to_move);
	}
	else
		printf("no push A\n");
	printf("PA\n");
}

void ra(t_lst **head)
{
	t_lst *to_move;
	t_lst *tmp;

	tmp = *head;
	if(tmp->next != NULL)
	{
		to_move = del_first(head);
		add_back2(head, to_move);
	}
	else
		printf("no rotate A\n");
	printf("RA\n");
}


void rb(t_lst **head)
{
	t_lst *to_move;
	t_lst *tmp;

	tmp = *head;
	if (tmp != NULL && tmp->next != NULL)
	{
		to_move = del_first(head);
		add_back2(head, to_move);
	}
	else
		printf("no rotate B\n");
	printf("RB\n");
}

void rr(t_lst **stack_a, t_lst **stack_b)
{
	t_lst *tmp;

	tmp = *stack_a;
	if (tmp != NULL && tmp->next != NULL)
		ra(stack_a);
	tmp = *stack_b;
	if (tmp != NULL && tmp->next != NULL)
		rb(stack_b);
	printf("RR\n");
}

void ss(t_lst **stack_a, t_lst **stack_b)
{
	t_lst *tmp;

	tmp = *stack_a;
	if (tmp != NULL && tmp->next != NULL)
		sa(stack_a);
	tmp = *stack_b;
	if (tmp != NULL && tmp->next != NULL)
		sb(stack_b);
	printf("SS\n");
}

void rra(t_lst **head)
{
	t_lst *tmp;
	t_lst *to_add;
	int size;

	tmp = *head;
	size = ft_lstsize(*head);
	while(tmp->next)
	{
		tmp = tmp->next;
	}
	to_add = tmp;
	to_add->next = *head;
	tmp = to_add;
	add_front2(head, to_add);
	while (size > 1)
	{
		tmp = tmp->next;
		size--;
	}
	tmp->next = NULL;
	printf("RRA\n");
}
