/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:47:51 by ralopez-          #+#    #+#             */
/*   Updated: 2022/10/22 09:47:52 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstfirst(t_list **list_a)
{
	if ((*list_a) != NULL)
		return (ft_atoi((*list_a)->content));
	else
		return (-1);
}

void	ft_lstdelete_last(t_list **list_a)
{
	t_list	*aux;

	if ((*list_a) != NULL)
	{
		if ((*list_a) != NULL && (*list_a)->next == NULL)
		{
			ft_lstdelone((*list_a), NULL);
			list_a = NULL;
		}
		else
		{
			aux = (*list_a);
			while (aux->next->next != NULL)
				aux = aux->next;
			ft_lstdelone(aux->next, NULL);
			aux->next = NULL;
		}
	}
}

int	all_sorted(t_list **list_a, t_list **list_b)
{
	int		n;
	t_list	*aux;

	n = -1;
	if (list_b != NULL)
		return (0);
	else
	{
		aux = (*list_a);
		while (aux != NULL)
		{
			if (n > ft_atoi(aux->content))
				return (0);
			n = ft_atoi(aux->content);
			aux = aux->next;
		}
		return (1);
	}
}
