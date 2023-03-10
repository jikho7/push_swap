/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:36:18 by jdefayes          #+#    #+#             */
/*   Updated: 2023/03/08 14:42:38 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void push_front(t_lst ** ptr_to_head, t_data *val)		// el ajouter entre head et 2 eme el, H->new->2eme
{
    t_lst * new_node;
    new_node = (t_lst *) malloc(sizeof(t_lst));

    new_node->nbr = val->tab[val->j];
	new_node->idx = val->j;
    new_node->nx = *ptr_to_head;		// new_node pointe sur 1er el
    *ptr_to_head = new_node;			// head pointe sur new_el
}

void add_front2(t_lst **head, t_lst *node_to_add)	// adresse head -> 0x860, adresse node_add -> 0x880
{
	t_lst *first_node = *head;	// first_node contient adresse head = 0x860

	node_to_add->nx = first_node;	// node_to_add place devant first_node	|| node_add nx pointe sur adresse first, 0x860
	*head = node_to_add;			// adresse de node_to add mise dans head. nouvelle tete	|| ptr sur head contient adresse node_add, 0x880
}

void push_end(t_lst *head, t_data *val)
{
    t_lst *current = head;			// to traverse the list
    while (current->nx != NULL)	// go fin de liste
	{
        current = current->nx;
    }
	t_lst *new_node = (t_lst*)malloc(sizeof(t_lst));	// new node created
	current->nx = new_node;	// creation lien
	new_node->nbr = val->tab[val->j];
	new_node->idx = val->j;
	new_node->nx = NULL;
	new_node->back = current;
}

void add_back2(t_lst **head, t_lst *node_to_add)
{
	t_lst *current = *head;

	while(current->nx)
	{
		current = current->nx;
	}
	node_to_add->nx = NULL;
	current->nx = node_to_add;
}

void add_front(t_lst **ptr_to_head, int x)	//	ptr pointe sur ptr adresse 820
{
	t_lst *ptr = *ptr_to_head;	// adresse du premier el "stockee" dans ptr, permet de ne pas perdre le lien list chainee
	//printf("adresse ptr:%p\n", ptr);
	t_lst *new_node = (t_lst*)malloc(sizeof(t_lst));
	if (new_node == NULL)
		exit(1);
	new_node->nx = ptr;	//nouvel el pointe sur l ancienne head 820
	new_node->nbr = x;
	*ptr_to_head = new_node;	// adresse de new_node devient la nouvelle adresse de head, *->change la valeur (adresse) dans memoire. Pointing head to new node.
}

void add_back(t_lst **ptr_to_head, int x)
{
	t_lst *current = *ptr_to_head;	//creation current pour parcourir liste til end
	t_lst *new_node = (t_lst*)malloc(sizeof(t_lst));	// creation new_node

	while(current->nx)	// parcours til end
	{
		current = current->nx;	//lst incrementation
	}
	new_node->nbr = x;
	new_node->nx = NULL; 	// car fin de lst
	current->nx = new_node; // current,avant dernier, link new_node to the lst.
}

t_lst	*del_first(t_lst **head)
{
	t_lst *tmp;
	if (head == NULL || *head == NULL)
		return (NULL);

	tmp = *head;	//addresse de head stocke dans var tmp, pour pouvoir del first node (head)
	*head = (*head)->nx;	//moving head to the nx node, on avance la head de un.

	tmp->nx = NULL;
	return (tmp);
}

