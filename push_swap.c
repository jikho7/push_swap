/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:28:59 by jdefayes          #+#    #+#             */
/*   Updated: 2023/02/08 12:25:59 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "push_swap.h"
void display_node(t_element *lst);

int main (int ac, char	**av)
{
	t_element *element;
	//t_list list;
	t_data data = {1, 0, 0, 0, NULL, &av[data.i]};
	data.tab = malloc(sizeof(int) * ac);
	data.i = 1;
	while (av[data.i])
	{
		data.tab[data.j] = atoi(av[data.i++]);
		data.size++;
		//printf("CONVERSION:%d\n", data.tab[data.j]);
		data.j++;
	}
	data.j = 0;
	bubble_sort(data.tab, data.size);
	// while (data.j < data.size)
	// 	printf("SORTED:%d\n", data.tab[data.j++]);
	int c = 0;
	while(c < 3)
	{
		printf("jksh");
		element = ft_lstnew(&data);
		display_node(element);
		data.j++;
		c++;
	}
	//printf("HOW:%d",ft_lstsize(&element));
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
void bubble_sort(int *tab, int size)
{
	int	tmp;
	int i;
	int swap;

	i = 0;
	swap = 1;
	while(swap >= 1)
	{
		swap = 0;
		while(i < size - 1)
		{
			if(tab[i] > tab [i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				swap++;
			}
			i++;
		}
		i = 0;
	}
}

t_element	*ft_lstnew(t_data *data)
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

void	*ft_calloc(size_t count, size_t size)
{
	void			*result;
	unsigned int	i;

	i = 0;
	result = malloc((size) * (count));
	if (result == NULL)
		return (NULL);
	if (size * count > 0)
		ft_bzero(result, (count * size));
	return (result);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*cs;

	cs = (char *)s;
	i = 0;
	while (i < n)
		cs[i++] = '\0';
}

int	ft_lstsize(t_element *lst)
{
	int	nbr_element;

	nbr_element = 0;
	while (!lst)
		return (0);
	while (lst)
	{
		nbr_element++;
		lst = lst->next;
	}
	return (nbr_element);
}

t_list *initialisation()
{
    t_list *list = malloc(sizeof(*list));
    t_element *element = malloc(sizeof(*element));

    if (list == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->nbr = 0;
    element->next = NULL;
    list->first = element;

    return (list);
}
