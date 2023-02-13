/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:28:59 by jdefayes          #+#    #+#             */
/*   Updated: 2023/02/13 15:28:24 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new);

int main (int ac, char	**av)
{
	//t_element *element;
	t_list *list = NULL;
	list = malloc(sizeof(*list));
	t_data data = {1, 0, 0, 0, NULL, &av[data.i]};
	data.tab = malloc(sizeof(int) * ac);
	data.i = 1;
	//list = initialisation();
	while (av[data.i])
	{
		data.tab[data.j] = atoi(av[data.i++]);
		data.size++;
		//printf("CONVERSION:%d\n", data.tab[data.j]);
		data.j++;
	}
	data.j = 0;
	bubble_sort(data.tab, data.size);
	//while (data.j < data.size)
	// 	printf("SORTED:%d\n", data.tab[data.j++]);
	data.j = 0;
	int c = 0;
	while(c < 3)
	{
		insertion(list, &data);
		display_node(list->first);
		data.j++;
		c++;
	}
	//printf("HOW:%d",ft_lstsize(&list));
}

void display_node(t_element *lst)
{
	if (lst != NULL)
	{
		printf("[%p] {value = %d | indice = %d | previous = %p | next = %p}\n", lst,
			lst->nbr,
			lst->idx,
			lst->back,
			lst->next);
	}
}



// t_list *initialisation()
// {
//     t_list *list = malloc(sizeof(*list));
//     t_element *element = malloc(sizeof(*element));

//     if (list == NULL || element == NULL)
//         exit(0);

//     element->nbr = 0;
//     element->next = NULL;
//     list->first = element;

//     return (list);
// }

	// (*new_element).nbr = data->tab[data->j];
	// (*new_element).idx = data->j;
	// new_element->next = list->first;
	// list->first = new_element;


/*
void display_lst(t_lst **first_node, char *name)
{
t_lst *current_node;
int count;
current_node = *first_node;
count = 0;
printf("\n%s :\n", name);
if (*first_node != NULL)
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
*/
