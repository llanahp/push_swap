/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:48:02 by ralopez-          #+#    #+#             */
/*   Updated: 2022/10/22 09:48:03 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **list_a, int print)
{
	t_list	*aux;

	aux = NULL;
	if (list_a != NULL && (*list_a) != NULL)
	{
		aux = ft_lstnew(ft_lstlast((*list_a))->content);
		ft_lstadd_front(list_a, aux);
		ft_lstdelete_last(list_a);
	}
	if (print == 1)
		ft_printf("rra\n");
}

void	rrb(t_list **list_b, int print)
{
	t_list	*aux;

	aux = NULL;
	if (list_b != NULL && (*list_b) != NULL)
	{
		aux = ft_lstnew(ft_lstlast((*list_b))->content);
		ft_lstadd_front(list_b, aux);
		ft_lstdelete_last(list_b);
	}
	if (print == 1)
		ft_printf("rrb\n");
}

void	rrr(t_list **list_a, t_list **list_b)
{
	rra(list_a, 0);
	rrb(list_b, 0);
	ft_printf("rrr\n");
}
