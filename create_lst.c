/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:59:26 by jdefayes          #+#    #+#             */
/*   Updated: 2023/04/03 15:15:48 by jdefayes         ###   ########.fr       */
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
	//	printf("ac ==2\n");
		stack_a = handle_str(res_split);
	}
	else if (ac > 2)
	{
	//	printf("ac +2\n");
		stack_a = ft_lstnew(ft_atoi(av[1], stack_a));
		i = 2;
		while (i < ac)
		{
			tmp = ft_lstnew(ft_atoi(av[i], stack_a));
			add_back(&stack_a, tmp);
			i++;
		}
	}
//	display_lst(&stack_a, "create_lst result");
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
	stack_a = NULL;
	size_tab = verif_split(str);
	tab = malloc(sizeof(int) * size_tab);
//	printf("adresse handle_str; %p\n", tab);
	while (i < size_tab)
	{
	//	printf("boucle");
		tab[i] = ft_atoi(str[i], stack_a);
		i++;
	}
//	printf("tab[i], handle_str;%d\n", tab[0]);
	i = 1;
	stack_a = ft_lstnew(tab[0]);
	while (i < size_tab)
	{
		tmp = ft_lstnew(tab[i]);
		add_back(&stack_a, tmp);
		i++;
	}
//	display_lst(&stack_a, "handle_lst result");
	free(tab);
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

void	check_doublon(int *tab, int size, t_lst *stack_a)
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
			if (tab[i] == tab[j])
			{
				free(tab);
				ft_lstclear(&stack_a);
				error();
			}
			i++;
		}
		j++;
	}
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(2);
}
