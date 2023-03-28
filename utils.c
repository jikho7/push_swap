/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:04:16 by jdefayes          #+#    #+#             */
/*   Updated: 2023/03/28 19:30:38 by jdefayes         ###   ########.fr       */
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
			if(tab[i] < tab [i + 1])
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

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	minus;

	result = 0;
	sign = 0;
	minus = 0;
	while (*str == 32)
		str++;
	while (*str == '-' || *str == '+' || *str == 32)
	{
		if (*str == '-')
			minus++;
		sign++;
		str++;
	}
	if (sign > 1 || minus > 1)
		return (0);
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + *(str++) - '0';
	if (result == -2147483648)
		return (-2147483648);
	if (minus == 1)
		result = result * -1;
	return (result);
}

int	ft_lstsize(t_lst *lst)
{
	int	nbr_element;

	nbr_element = 0;
	while (!lst)
		return (0);
	while (lst)
	{
		nbr_element++;
		lst = lst->nx;
	}
	return (nbr_element);
}

t_lst	*ft_lstlast(t_lst *lst)
{
	if (lst != NULL)
	{
		while (lst->nx)
			lst = lst->nx;
		return (lst);
	}
	else
		return (lst);
}

void	ft_lstclear(t_lst **lst)
{
	t_lst	*temp;

	if (lst)
	{
		while (*lst)
		{
			temp = (*lst)->nx;
			ft_lstdelone(*lst);
			(*lst) = temp;
		}
	}
	else
		*lst = NULL;
}

void	ft_lstdelone(t_lst *lst)
{
	lst->nx = NULL;
	free (lst);
}

int ps_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return(i);
}
