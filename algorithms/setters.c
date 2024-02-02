/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:07:15 by jcaro             #+#    #+#             */
/*   Updated: 2023/11/30 18:50:47 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

int	change_target(t_stack *node_a, t_stack *node_b, t_stack *target)
{
	int	result;

	result = 0;
	if (node_a -> content > node_b -> content)
		result = 1;
	if (!target || node_a -> content < target -> content)
		return (result);
	else
		return (0);
}

void	set_target(t_stack **a, t_stack **b)
{
	t_stack	*node_b;
	t_stack	*node_a;
	t_stack	*min;

	node_b = *b;
	while (node_b)
	{
		node_a = *a;
		node_b -> target = NULL;
		min = NULL;
		while (node_a)
		{
			if (change_target(node_a, node_b, node_b -> target))
				node_b -> target = node_a;
			if (!min || node_a -> content < min -> content)
				min = node_a;
			node_a = node_a -> next;
		}
		if (!(node_b -> target))
			node_b -> target = min;
		node_b = node_b -> next;
	}
}

void	set_above_med(t_stack **x)
{
	t_stack	*temp;
	int		size;

	temp = *x;
	size = stack_len(x);
	while (temp)
	{
		if (temp -> index <= size / 2)
			temp -> above_med = 1;
		else
			temp -> above_med = 0;
		temp = temp -> next;
	}
}

void	set_index(t_stack **x)
{
	int		index;
	t_stack	*temp;

	index = 0;
	temp = *x;
	while (temp)
	{
		temp -> index = index;
		temp = temp -> next;
		index++;
	}
}
