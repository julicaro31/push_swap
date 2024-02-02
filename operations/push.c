/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:12:38 by jcaro             #+#    #+#             */
/*   Updated: 2023/11/27 20:39:42 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

void	push(t_stack **x, t_stack **y)
{
	t_stack	*first_x;
	t_stack	*first_y;
	t_stack	*second_y;

	if (stack_len(y) > 0)
	{
		first_x = *x;
		first_y = *y;
		second_y = first_y -> next;
		first_y -> next = first_x;
		*x = first_y;
		*y = second_y;
	}
}
