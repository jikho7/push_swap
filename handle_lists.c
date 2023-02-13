/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:36:18 by jdefayes          #+#    #+#             */
/*   Updated: 2023/02/13 15:26:17 by jdefayes         ###   ########.fr       */
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

void insertion(t_list *list, t_data *data)
{
	(void)data;
    /* Création du nouvel élément */
    t_element *new_element = malloc(sizeof(*new_element));
    if (list == NULL || new_element == NULL)
        exit(0);
    new_element->nbr = data->tab[data->j];

    /* Insertion de l'élément au début de la liste */
    new_element->next = list->first;
    list->first = new_element;
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
