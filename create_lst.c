/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:59:26 by jdefayes          #+#    #+#             */
/*   Updated: 2023/03/29 18:42:52 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*create_lst(int ac, char **av, char **res_split)
{
	int		i;
	int		j;
	t_lst	*tmp;
	t_lst	*stack_a;

	i = 0;
	j = 1;
	stack_a = NULL;
	if (ac == 2)
	{
		stack_a = handle_str(res_split);
	}
	else if (ac > 2)
	{
		stack_a = ft_lstnew(ft_atoi(av[1]));
		i = 2;
		while (i < ac)
		{
			tmp = ft_lstnew(ft_atoi(av[i]));
			add_back(&stack_a, tmp);
			i++;
		}
	}
	return (stack_a);
}

t_lst	*handle_str(char **str)
{
	int		i;
	int		size_tab;
	int		*tab;
	t_lst	*tmp;
	t_lst	*stack_a;

	i = 0;
	size_tab = verif_split(str);
	tab = malloc(sizeof(int) * size_tab);
	while (i < size_tab)
	{
		tab[i] = ft_atoi(str[i]);
		i++;
	}
	i = 1;
	stack_a = ft_lstnew(tab[0]);
	while (i < size_tab)
	{
		tmp = ft_lstnew(tab[i]);
		add_back(&stack_a, tmp);
		i++;
	}
	return (stack_a);
}

int	verif_split(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if ((tab[i][j] == '-' && tab[i][j + 1] < '0') || ((tab[i][j] == '-'
				&& tab[i][j + 1] > '9')))
				error();
			if ((tab[i][j] == '+' && tab[i][j + 1] < '0') || ((tab[i][j] == '+'
				&& tab[i][j + 1] > '9')))
				error();
			else if ((tab[i][j] > 47 && tab[i][j] < 58) || tab[i][j] == 32
				|| tab[i][j] == 45 || tab[i][j] == '+')
				write(1, "", 0);
			else
				error();
			j++;
		}
		i++;
	}
	return (i);
}

void	check_doublon_max_int(int *tab, int size)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < size)
	{
		i = 1 + j;
		while (i < size)
		{
			if (tab[i] == tab[j] || tab[i] == 2147483647
				|| tab[i] == -2147483648)
				error();
			i++;
		}
		j++;
	}
}

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}
