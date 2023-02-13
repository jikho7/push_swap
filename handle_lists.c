/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:36:18 by jdefayes          #+#    #+#             */
/*   Updated: 2023/02/13 18:16:53 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
/*
t_list	*ps_lstlast(t_list *lst)
{
	if (lst != NULL)
	{
		while (lst->next)
			lst = lst->next;
		return (lst);
	}
	else
		return (lst);
}
*/

/*
void insertion(t_element *list, t_data *data)
{
	(void)data;

    t_element *new_element = malloc(sizeof(*new_element));
    if (list == NULL || new_element == NULL)
        exit(0);
    new_element->nbr = data->tab[data->j];

    new_element->next = list->first;
    list->first = new_element;
}
*/

void push_front(t_lst ** head, t_data *val)
{
    t_lst * new_node;
    new_node = (t_lst *) malloc(sizeof(t_lst));

    new_node->nbr = val->tab[val->j];
	new_node->idx = val->j;
    new_node->next = *head;
    *head = new_node;
}

void push_end(t_lst *head, t_data *val)
{
    t_lst *current = head;
    while (current->next != NULL)
	{
        current = current->next;
    }
    /* now we can add a new variable */
    current->next = (t_lst*) malloc(sizeof(t_lst));
    current->next->nbr = val->tab[val->j];
	current->next->idx = val->j;
    current->next->next = NULL;
	//current->next->back = current->next;
}

/*
int	ps_lstsize(t_list *lst)
{
	int	nbr_element;

	nbr_element = 0;
	while (!lst)
		return (0);
	while (lst)
	{
		nbr_element++;
	//	lst = lst->next;
	}
	return (nbr_element);
}


void	ps_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}
*/


/*
t_element	*ps_lstnew(t_data *data)
{
	t_element	*new_element;
	new_element = ft_calloc(1, (sizeof(t_list)));
	if (new_element == NULL)
		return (NULL);
	(*new_element).nbr = data->tab[data->j];
	(*new_element).idx = data->j;
	new_element->next = NULL;
	new_element->back = NULL;
	return (new_element);
}
*/

/*
void	ps_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst)
		new->next = NULL;
	else
		new->next = *lst;
	*lst = new;
}
*/
