/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_piles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:11:11 by jdefayes          #+#    #+#             */
/*   Updated: 2023/02/21 22:18:31 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
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

void rotate(t_lst **head)
{
	t_lst *to_rotate;

	to_rotate = del_first(head);
	add_back2(head, to_rotate);
}

void swap2(t_lst **head)
{
	t_lst *first_node;
	t_lst *second_node;

	first_node = del_first(head);
	second_node = del_first(head);

	add_front2(head, first_node);
	add_front2(head, second_node);
}
