/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliacaro <juliacaro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:06:07 by jcaro             #+#    #+#             */
/*   Updated: 2023/10/11 18:15:01 by juliacaro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;
	t_list	*current;

	current = *lst;
	while (current)
	{
		aux = current -> next;
		ft_lstdelone(current, del);
		current = aux;
	}
	*lst = NULL;
}
