/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:58:05 by jdefayes          #+#    #+#             */
/*   Updated: 2023/04/05 18:35:04 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

long	ft_atoi(const char *str, t_lst *stack, char **res_split)
{
	long int	result;
	int			sign;

	(void) res_split;
	result = 0;
	sign = 1;
	while (*str == 32)
		str++;
	exceptions_atoi(str);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + *(str++) - '0';
	exceptions_atoi_2(str, result * sign, stack);
	return (result * sign);
}

int	exceptions_atoi(const char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	if ((str[i] == '+' && str[i +1] == '+') || (str[i] == '-'
			&& str[i + 1] == '-'))
		error();
	if ((str[i] == '+' && str[i +1] == '-') || (str[i] == '-'
			&& str[i + 1] == '+'))
		error();
	if ((str[i] < '0' || str[i] > '9') && (str[i] != ' '
			&& str[i] != '+' && str[i] != '-'))
		error();
	if ((str[i] == '-' && !((str[i + 1] >= '0' && *str <= '9'))))
		error();
	return (res);
}

void	exceptions_atoi_2(const char *str, long result, t_lst *stack)
{
	if (*str && !(*str >= '0' && *str <= '9'))
	{
		ft_lstclear(&stack);
		error();
	}
	if (result > 2147483647 || result < -2147483648)
	{
		error();
		ft_lstclear(&stack);
	}
}
