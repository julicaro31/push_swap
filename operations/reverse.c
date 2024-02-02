/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:16:59 by juliacaro         #+#    #+#             */
/*   Updated: 2023/11/27 20:39:51 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

void	reverse(t_stack **x)
{
	t_stack	*first;
	t_stack	*prev_last;
	t_stack	*last;

	if (stack_len(x) > 1)
	{
		first = *x;
		prev_last = *x;
		last = *x;
		while (last -> next)
		{
			prev_last = last;
			last = last -> next;
		}
		last -> next = first;
		prev_last -> next = NULL;
		*x = last;
	}
}
