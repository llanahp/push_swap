/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:46:00 by ralopez-          #+#    #+#             */
/*   Updated: 2022/11/03 11:04:49 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **list_x, int print)
{
	t_list	*first;
	t_list	*aux;

	if ((*list_x) != NULL && (*list_x)->next != NULL)
	{
		first = (*list_x);
		aux = (*list_x)->next;
		first->next = aux->next;
		aux->next = NULL;
		ft_lstadd_front(list_x, aux);
	}
	if (print == 1)
		ft_printf("sa\n");
}

void	sb(t_list **list_x, int print)
{
	t_list	*first;
	t_list	*aux;

	if ((*list_x) != NULL && (*list_x)->next != NULL)
	{
		first = (*list_x);
		aux = (*list_x)->next;
		first->next = aux->next;
		aux->next = NULL;
		ft_lstadd_front(list_x, aux);
	}
	if (print == 1)
		ft_printf("sb\n");
}

void	ss(t_list **list_a, t_list **list_b)
{
	sa(list_a, 0);
	sb(list_b, 0);
	ft_printf("ss\n");
}
