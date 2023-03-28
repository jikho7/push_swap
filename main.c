/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:09:20 by jdefayes          #+#    #+#             */
/*   Updated: 2023/03/28 19:29:54 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

char *args_handle(char **str, int ac);
int check_only_nb(char *str);
int verif_split(char **tab);
void handle_str(char *av, char c);

int main (int ac, char **av)
{
	int *tab;
	int i;
	int j;

	t_lst *tmp;
	t_lst *stack_a;
	t_lst *stack_b;
	i = 0;
	j = 1;

	if(ac == 2)
	{
		handle_str(av[1], ' ');
	}
	if (ac > 1)
	{
		stack_a = ft_lstnew(ft_atoi(av[1]));
		i = 2;
		while (i < ac)
		{
			tmp = ft_lstnew(ft_atoi(av[i]));
			add_back2(&stack_a, tmp);
			i++;
		}
		tab = create_tab(&stack_a, ac);
		bubble_sort(tab, ac - 1);
		indexation(&stack_a, tab, ac);
		push_swap(&stack_a, &stack_b, ac);
//		display_lst(&stack_b, "STACK B");
//		display_lst(&stack_a, "STACK A");
		ft_lstclear(&stack_a);
		free(tab);
	}
	else
		return (0);
}

int verif_split(char **tab)
{
	int i;
	int j;

	i = 0;
	while(tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if(tab[i][j] == '-' && tab[i][j - 1] == '-')		//probleme
			{
				write(1, "error", 5);
			 	exit(1);
			}
			else if((tab[i][j] == '-' && tab[i][j + 1] < '0') || ((tab[i][j] == '-' && tab[i][j + 1] > '9')))
			{
				write(1, "error", 5);
			 	exit(1);
			}
			else if((tab[i][j] > 47 && tab[i][j] < 58) || tab[i][j] == 32 || tab[i][j] == 45)
			{
				write(1, "", 0);
			}
			else
			{
				write(1, "error", 5);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return(i);
}

void handle_str(char *av, char c)
{
	int i;
	int size_tab;
	char **res_split;
	int *tab;

	i = 0;
	res_split = ps_split(&av[1], c);
	size_tab = verif_split(res_split);
	tab = malloc(sizeof(int) * size_tab);
	while(res_split[i])
	{
		tab[i] = ft_atoi(res_split[i]);
		i++;
	}
//	check_doublon(tab);
	// i = 0;
	// while(i < size_tab)
	// {
	// 	printf("%d\n", tab[i]);
	// 	i++;
	// }
}

// void check_doublon(int *tab)
// {

// }
