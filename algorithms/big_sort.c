/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:23:40 by jcaro             #+#    #+#             */
/*   Updated: 2023/11/30 19:23:42 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

int	get_max(int n2, int n1)
{
	if (n2 > n1)
		return (n2);
	else
		return (n1);
}

int	get_cost(t_stack **a, t_stack **b, t_stack *node)
{
	int		cost;

	if (node -> above_med)
	{
		cost = node -> index;
		if (node -> target -> above_med)
			cost = get_max(cost, node -> target -> index);
		else
			cost += stack_len(a) - node -> target -> index;
	}
	else
	{
		cost = stack_len(b) - node -> index;
		if (node -> target -> above_med)
			cost += node -> target -> index;
		else
			cost = get_max(cost, stack_len(a) - node -> target -> index);
	}
	return (cost);
}

void	push_cheapest(t_stack **a, t_stack **b)
{
	int		min_cost;
	int		cost;
	t_stack	*cheapest;
	t_stack	*node;

	node = *b;
	min_cost = -1;
	while (node && min_cost != 0)
	{
		cost = get_cost(a, b, node);
		if (min_cost == -1 || cost < min_cost)
		{
			min_cost = cost;
			cheapest = node;
		}
		node = node -> next;
	}
	to_the_top(a, b, cheapest);
	push_print(a, b, "pa");
}

void	big_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_len(a);
	while (size > 3 && !is_sorted(a))
	{
		push_print(b, a, "pb");
		size--;
	}
	if (!is_sorted(a))
		three_numbers(a);
	size = stack_len(b);
	while (size > 0)
	{
		set_index(a);
		set_index(b);
		set_above_med(a);
		set_above_med(b);
		set_target(a, b);
		push_cheapest(a, b);
		size--;
	}
	min_to_top(a);
}
