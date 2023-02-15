/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlinked.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:14:55 by jdefayes          #+#    #+#             */
/*   Updated: 2023/02/15 15:23:46 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int nbr;
	struct node *next;
}t_node;

t_node	*ft_lstnew(int nbr);
void add_front(t_node **ptr_to_head, int x);
void add_back(t_node **ptr_to_head, int x);
void	display_list(t_node **head);

#include <stdlib.h>
int main(int ac, char **av)
{
	(void)ac;
	t_node *head;
	head = ft_lstnew(atoi(av[1]));
	printf("adresse HEAD:%p\n", head);
	add_back(&head, atoi(av[2]));
	add_front(&head, atoi(av[3]));
	add_back(&head, atoi(av[4]));
	printf("adresse HEAD-AFTER:%p\n", head);
	display_list(&head);
	return (0);

}

t_node	*ft_lstnew(int nbr)
{
	t_node	*new_element;

	new_element = (t_node*)malloc((sizeof(t_node)));
	if (new_element == NULL)
		return (NULL);
	new_element->nbr = nbr;
	new_element->next = NULL;
	return (new_element);
}

void add_front(t_node **ptr_to_head, int x)	//	ptr pointe sur ptr adresse 820
{
	t_node *ptr = *ptr_to_head;	// adresse du premier el "stockee" dans ptr, permet de ne pas perdre le lien list chainee
	printf("adresse ptr:%p\n", ptr);
	t_node *new_node = (t_node*)malloc(sizeof(t_node));
	if (new_node == NULL)
		exit(1);
	new_node->next = ptr;	//nouvel el pointe sur l ancienne head 820
	new_node->nbr = x;
	*ptr_to_head = new_node;	// adresse de new_node devient la nouvelle adresse de head, *->change la valeur (adresse) dans memoire
}

void add_back(t_node **ptr_to_head, int x)
{
	t_node *current = *ptr_to_head;	//creation current pour parcourir liste til end
	t_node *new_node = (t_node*)malloc(sizeof(t_node));	// creation new_node

	while(current->next)	// parcours til end
	{
		current = current->next;	//lst incrementation
	}
	new_node->nbr = x;
	new_node->next = NULL; 	// car fin de lst
	current->next = new_node; // current,avant dernier, link new_node to the lst
}
void	display_list(t_node **head)
{
	t_node *ptr;

	ptr = *head;
	while(ptr)
	{
		printf("value = %d    ", ptr->nbr);
		printf("adresse = %p\n", ptr);
		ptr = ptr->next;
	}
}
