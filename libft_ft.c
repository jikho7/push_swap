/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdefayes <jdefayes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:58:05 by jdefayes          #+#    #+#             */
/*   Updated: 2023/03/29 18:40:31 by jdefayes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exceptions_atoi(const char *str);

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
	exceptions_atoi(str);
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

int	exceptions_atoi(const char *str)
{
	int	res;
	int i;

	res = 0;
	i = 0;
	if ((str[i] == '+' && str[i +1] == '+') || (str[i] == '-' && str[i+ 1] == '-' ))
		error();
	if ((str[i] == '+' && str[i +1] == '-') || (str[i] == '-' && str[i+ 1] == '+' ))
		error();
	if ((str[i] < '0' || str[i] > '9') && (str[i] != ' ' && str[i] != '+' && str[i] != '-'))
		error();
	return (res);
}
