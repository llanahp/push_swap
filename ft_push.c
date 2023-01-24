/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:48:45 by ralopez-          #+#    #+#             */
/*   Updated: 2022/10/22 09:48:47 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **list_a, t_list **list_b)
{
	t_list	*aux;

	aux = NULL;
	if (list_b != NULL && (*list_b) != NULL)
	{
		aux = ft_lstnew((*list_b)->content);
		ft_lstadd_front(list_a, aux);
		aux = (*list_b);
		if ((*list_b)->next != NULL)
			(*list_b) = (*list_b)->next;
		else
			(*list_b) = NULL;
		ft_lstdelone(aux, NULL);
	}
	ft_printf("pa\n");
}

void	pb(t_list **list_a, t_list **list_b)
{
	t_list	*aux;

	aux = NULL;
	if (list_a != NULL && (*list_a) != NULL)
	{
		aux = ft_lstnew((*list_a)->content);
		ft_lstadd_front(list_b, aux);
		aux = (*list_a);
		if ((*list_a)->next != NULL)
			(*list_a) = (*list_a)->next;
		else
			(*list_a) = NULL;
		ft_lstdelone(aux, NULL);
	}
	ft_printf("pb\n");
}
