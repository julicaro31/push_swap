/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:49:56 by juliacaro         #+#    #+#             */
/*   Updated: 2023/11/27 21:56:18 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include "include/libft.h"

int	digit_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	size_check(char *str)
{
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	if (ft_strlen(str + i) > 10)
		return (0);
	if (ft_strlen(str + i) == 10)
	{
		if (sign == 1 && (ft_strncmp(str + i, "2147483647", 10) > 0))
			return (0);
		if (sign == -1 && (ft_strncmp(str + i, "2147483648", 10) > 0))
			return (0);
	}
	return (1);
}

int	int_check(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!digit_check(argv[i]) || !size_check(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	dup_check(t_stack **x, int num)
{
	t_stack	*temp;

	temp = *x;
	while (temp)
	{
		if (temp -> content == num)
			return (0);
		temp = temp -> next;
	}
	return (1);
}

int	is_sorted(t_stack **x)
{
	t_stack	*temp;
	t_stack	*temp_next;

	temp = *x;
	while (temp -> next)
	{
		temp_next = temp -> next;
		if (temp_next -> content < temp -> content)
			return (0);
		temp = temp -> next;
	}
	return (1);
}
