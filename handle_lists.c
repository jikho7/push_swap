/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:36:18 by jdefayes          #+#    #+#             */
/*   Updated: 2023/02/21 17:59:07 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void push_front(t_lst ** ptr_to_head, t_data *val)		// el ajouter entre head et 2 eme el, H->new->2eme
{
    t_lst * new_node;
    new_node = (t_lst *) malloc(sizeof(t_lst));

    new_node->nbr = val->tab[val->j];
	new_node->idx = val->j;
    new_node->next = *ptr_to_head;		// new_node pointe sur 1er el
    *ptr_to_head = new_node;			// head pointe sur new_el
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

void add_front2(t_lst **head, t_lst *node_to_add)
{
	t_lst *first_node = *head;

	node_to_add->next = first_node;	// node_to_add place devant first_node
	*head = node_to_add;			// adresse de node_to add mise dans head. nouvelle tete

}

void push_end(t_lst *head, t_data *val)
{
    t_lst *current = head;			// to traverse the list
    while (current->next != NULL)	// go fin de liste
	{
        current = current->next;
    }
	t_lst *new_node = (t_lst*)malloc(sizeof(t_lst));	// new node created
	current->next = new_node;	// creation lien
	new_node->nbr = val->tab[val->j];
	new_node->idx = val->j;
	new_node->next = NULL;
	new_node->back = current;
    // current->next = (t_lst*) malloc(sizeof(t_lst)); 	// creation + malloc new node
    // current->next->nbr = val->tab[val->j];
	// current->next->idx = val->j;
    // current->next->next = NULL;
	// current->next->back = current;
}

/*
int main(int ac, char **av)
{
	(void)ac;
	t_lst *head;

	head = ft_lstnew(atoi(av[1]));
	add_front(&head, atoi(av[2]));
	add_front(&head, atoi(av[3]));
	add_front(&head, atoi(av[4]));

	display_list(&head);
	printf("\n");

	//swap2(&head);

	//display_node(head);
	rotate(&head);
	//printf("\n");
	display_list(&head);
	return (0);

}
*/




void rotate(t_lst **head)
{
	t_lst *to_rotate;

	to_rotate = del_first(head);
	add_back2(head, to_rotate);
}

void add_back2(t_lst **head, t_lst *node_to_add)
{
	t_lst *current = *head;

	while(current->next)
	{
		current = current->next;
	}
	node_to_add->next = NULL;
	current->next = node_to_add;
}



void add_front(t_lst **ptr_to_head, int x)	//	ptr pointe sur ptr adresse 820
{
	t_lst *ptr = *ptr_to_head;	// adresse du premier el "stockee" dans ptr, permet de ne pas perdre le lien list chainee
	//printf("adresse ptr:%p\n", ptr);
	t_lst *new_node = (t_lst*)malloc(sizeof(t_lst));
	if (new_node == NULL)
		exit(1);
	new_node->next = ptr;	//nouvel el pointe sur l ancienne head 820
	new_node->nbr = x;
	*ptr_to_head = new_node;	// adresse de new_node devient la nouvelle adresse de head, *->change la valeur (adresse) dans memoire. Pointing head to new node.
}

void add_back(t_lst **ptr_to_head, int x)
{
	t_lst *current = *ptr_to_head;	//creation current pour parcourir liste til end
	t_lst *new_node = (t_lst*)malloc(sizeof(t_lst));	// creation new_node

	while(current->next)	// parcours til end
	{
		current = current->next;	//lst incrementation
	}
	new_node->nbr = x;
	new_node->next = NULL; 	// car fin de lst
	current->next = new_node; // current,avant dernier, link new_node to the lst.
}

t_lst	*del_first(t_lst **head)
{
	t_lst *tmp;
	if (head == NULL || *head == NULL)
		return (NULL);

	tmp = *head;	//addresse de head stocke dans var tmp, pour pouvoir del first node (head)
	*head = (*head)->next;	//moving head to the next node, on avance la head de un.

	tmp->next = NULL;
	return (tmp);
}

