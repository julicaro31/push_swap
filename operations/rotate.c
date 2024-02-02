/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:05:49 by jcaro             #+#    #+#             */
/*   Updated: 2023/11/23 16:28:58 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

void	rotate(t_stack **x)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*second;

	if (stack_len(x) > 1)
	{
		first = *x;
		second = first -> next;
		last = *x;
		while (last -> next)
			last = last -> next;
		last -> next = first;
		first -> next = NULL;
		*x = second;
	}
}
