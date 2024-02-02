/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:24:22 by jcaro             #+#    #+#             */
/*   Updated: 2023/11/23 15:31:43 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

void	swap(t_stack **x)
{
	t_stack	*first;
	t_stack	*second;

	if (stack_len(x) >= 2)
	{
		first = *x;
		second = first -> next;
		first -> next = second -> next;
		second -> next = first;
		*x = second;
	}
}
