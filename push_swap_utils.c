/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:24:39 by jcaro             #+#    #+#             */
/*   Updated: 2023/11/30 19:24:47 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include "include/libft.h"

int	ft_atoi_2(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * sign);
}

void	free_array(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

t_stack	*clear_stack(t_stack **first)
{
	t_stack	*temp;
	t_stack	*current;

	current = *first;
	while (current)
	{
		temp = current;
		current = current -> next;
		free(temp);
	}
	return (NULL);
}

t_stack	*add_back(t_stack **first, int content)
{
	t_stack	*new;
	t_stack	*temp;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	temp = *first;
	if (!temp)
		*first = new;
	else
	{
		while (temp -> next)
			temp = temp -> next;
		temp -> next = new;
	}
	return (new);
}

t_stack	*init_stack(char **argv)
{
	t_stack	*x;
	int		i;
	int		num;

	i = 0;
	x = NULL;
	while (argv[i])
	{
		num = ft_atoi_2(argv[i]);
		if (!dup_check(&x, num) || !add_back(&x, num))
		{
			ft_putstr_fd("Error\n", 2);
			return (clear_stack(&x));
		}
		i++;
	}
	return (x);
}
