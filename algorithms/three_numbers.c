/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:56:56 by jcaro             #+#    #+#             */
/*   Updated: 2023/11/28 13:14:47 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

void	case_321(t_stack **a)
{
	times_operation(a, swap, 1, "sa");
	times_operation(a, reverse, 1, "rra");
}

void	case_132(t_stack **a)
{
	times_operation(a, reverse, 1, "rra");
	times_operation(a, swap, 1, "sa");
}

void	three_numbers(t_stack **a)
{
	int		number[3];
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *a;
	while (temp)
	{
		number[i] = temp -> content;
		temp = temp -> next;
		i++;
	}
	if (number[0] > number[1] && number[1] > number[2])
		case_321(a);
	else if (number[0] > number[2] && number[2] > number[1])
		times_operation(a, rotate, 1, "ra");
	else if (number[1] > number[2] && number[2] > number[0])
		case_132(a);
	else if (number[1] > number[0] && number[0] > number[2])
		times_operation(a, reverse, 1, "rra");
	else if (number[2] > number[0] && number[0] > number[1])
		times_operation(a, swap, 1, "sa");
}
