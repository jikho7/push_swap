/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:04:16 by jdefayes          #+#    #+#             */
/*   Updated: 2023/02/13 15:22:53 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

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

t_element	*ft_lstnew(t_data *data, t_list *list)
{
	t_element	*new_element;

	new_element = malloc(sizeof(*new_element));
	if (new_element == NULL || list != NULL)
		return (NULL);
	(*new_element).nbr = data->tab[data->j];
	(*new_element).idx = data->j;
	new_element->next = list->first;
	list->first = new_element;
	//new_element->back = NULL;
	return (new_element);
}
