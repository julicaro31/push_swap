/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:09:18 by juliacaro         #+#    #+#             */
/*   Updated: 2023/11/30 19:24:07 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
	struct s_stack	*target;
	int				above_med;
}	t_stack;

int		int_check(char **argv);
int		dup_check(t_stack **x, int num);
int		ft_atoi_2(const char *str);
void	free_array(char **argv);
t_stack	*clear_stack(t_stack **first);
t_stack	*add_back(t_stack **first, int content);
t_stack	*init_stack(char **argv);
size_t	stack_len(t_stack **x);
void	swap(t_stack **x);
void	push(t_stack **x, t_stack **y);
void	rotate(t_stack **x);
void	reverse(t_stack **x);
int		is_sorted(t_stack **x);
void	sort(t_stack **a, t_stack **b);
int		find_min(t_stack **x);
void	three_numbers(t_stack **a);
void	big_sort(t_stack **a, t_stack **b);
void	min_to_top(t_stack **a);
void	times_operation(t_stack **x, void (*f)(t_stack **), int t, char *m);
void	push_print(t_stack **x, t_stack **y, char *msg);
void	set_target(t_stack **a, t_stack **b);
void	set_above_med(t_stack **x);
void	set_index(t_stack **x);
void	to_the_top(t_stack **a, t_stack **b, t_stack *node);

#endif