/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:48:34 by juliacaro         #+#    #+#             */
/*   Updated: 2023/11/30 21:29:56 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include "include/libft.h"

void	push_swap(char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = init_stack(argv);
	if (!a)
		return ;
	if (is_sorted(&a))
	{
		clear_stack(&a);
		return ;
	}
	b = NULL;
	sort(&a, &b);
	clear_stack(&a);
}

void	free_if(int ac, char **argv)
{
	if (ac == 2)
		free_array(argv);
}

int	main(int ac, char *argv[])
{
	if (ac < 2)
		exit(0);
	if (ac == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv || !argv[0])
		{
			ft_putstr_fd("Error\n", 2);
			if (argv)
				free(argv);
			exit(1);
		}
	}
	else
		argv++;
	if (!int_check(argv))
	{
		free_if(ac, argv);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	push_swap(argv);
	free_if(ac, argv);
	exit(0);
}
