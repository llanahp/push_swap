/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:48:33 by ralopez-          #+#    #+#             */
/*   Updated: 2022/10/22 09:48:34 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **list_a, int print)
{
	t_list	*aux;

	aux = NULL;
	if (list_a != NULL && (*list_a) != NULL)
	{
		aux = ft_lstnew((*list_a)->content);
		ft_lstadd_back(list_a, aux);
		aux = (*list_a);
		if ((*list_a)->next != NULL)
			(*list_a) = (*list_a)->next;
		else
			(*list_a) = NULL;
		ft_lstdelone(aux, NULL);
	}
	if (print == 1)
		ft_printf("ra\n");
}

void	rb(t_list **list_b, int print)
{
	t_list	*aux;

	aux = NULL;
	if (list_b != NULL && (*list_b) != NULL)
	{
		aux = ft_lstnew((*list_b)->content);
		ft_lstadd_back(list_b, aux);
		aux = (*list_b);
		if ((*list_b)->next != NULL)
			(*list_b) = (*list_b)->next;
		else
			(*list_b) = NULL;
		ft_lstdelone(aux, NULL);
	}
	if (print == 1)
		ft_printf("rb\n");
}

void	rr(t_list **list_a, t_list **list_b)
{
	ra(list_a, 0);
	rb(list_b, 0);
	ft_printf("rr\n");
}
