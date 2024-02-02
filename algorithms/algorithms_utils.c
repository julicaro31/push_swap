/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliacaro <juliacaro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:36:21 by jcaro             #+#    #+#             */
/*   Updated: 2023/11/29 00:19:47 by juliacaro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

int	find_min(t_stack **x)
{
	t_stack	*temp;
	int		min;
	int		i_min;
	int		i;

	temp = *x;
	min = temp -> content;
	i_min = 0;
	i = 0;
	while (temp -> next)
	{
		temp = temp -> next;
		i++;
		if (temp -> content < min)
		{
			min = temp -> content;
			i_min = i;
		}
	}
	return (i_min);
}

void	times_operation(t_stack **x, void (*f)(t_stack **), int t, char *m)
{
	while (t > 0)
	{
		f(x);
		ft_putendl_fd(m, 1);
		t--;
	}
}

void	push_print(t_stack **x, t_stack **y, char *msg)
{
	push(x, y);
	ft_putendl_fd(msg, 1);
}

void	min_to_top(t_stack **a)
{
	int	len;
	int	i;
	int	i_min;

	len = stack_len(a);
	i = 0;
	while (i < len)
	{
		i_min = find_min(a);
		if (i_min > 0 && i_min <= len / 2)
			times_operation(a, rotate, i_min, "ra");
		else if (i_min > 0)
			times_operation(a, reverse, len - i_min, "rra");
		i++;
	}
}

size_t	stack_len(t_stack **x)
{
	t_stack	*temp;
	size_t	count;

	count = 0;
	temp = *x;
	while (temp)
	{
		temp = temp -> next;
		count++;
	}
	return (count);
}
