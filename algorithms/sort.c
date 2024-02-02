/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliacaro <juliacaro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:58:29 by jcaro             #+#    #+#             */
/*   Updated: 2023/11/29 00:18:09 by juliacaro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

void	sort(t_stack **a, t_stack **b)
{
	if (stack_len(a) == 2)
		times_operation(a, swap, 1, "sa");
	else if (stack_len(a) == 3)
		three_numbers(a);
	else
		big_sort(a, b);
}
