/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_the_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:24:44 by jcaro             #+#    #+#             */
/*   Updated: 2023/11/30 19:10:04 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

void	both_above(t_stack **a, t_stack **b, int index_a, int index_b)
{
	while (index_a > 0 && index_b > 0)
	{
		rotate(a);
		rotate(b);
		ft_putendl_fd("rr", 1);
		index_a--;
		index_b--;
	}
	times_operation(a, rotate, index_a, "ra");
	times_operation(b, rotate, index_b, "rb");
}

void	both_below(t_stack **a, t_stack **b, int index_a, int index_b)
{
	index_a = stack_len(a) - index_a;
	index_b = stack_len(b) - index_b;
	while (index_a > 0 && index_b > 0)
	{
		reverse(a);
		reverse(b);
		ft_putendl_fd("rrr", 1);
		index_a--;
		index_b--;
	}
	times_operation(a, reverse, index_a, "rra");
	times_operation(b, reverse, index_b, "rrb");
}

void	to_the_top(t_stack **a, t_stack **b, t_stack *node)
{
	int	index_a;
	int	index_b;

	index_a = node -> target -> index;
	index_b = node -> index;
	if (node -> above_med && node -> target -> above_med)
		both_above(a, b, index_a, index_b);
	else if (!(node -> above_med) && !(node -> target -> above_med))
		both_below(a, b, index_a, index_b);
	else if (node -> above_med && !(node -> target -> above_med))
	{
		times_operation(a, reverse, stack_len(a) - index_a, "rra");
		times_operation(b, rotate, index_b, "rb");
	}
	else if (!(node -> above_med) && node -> target -> above_med)
	{
		times_operation(a, rotate, index_a, "ra");
		times_operation(b, reverse, stack_len(b) - index_b, "rrb");
	}
}
