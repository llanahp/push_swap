/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:21:34 by ralopez-          #+#    #+#             */
/*   Updated: 2022/10/22 11:21:35 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstmin(t_list **list_x)
{
	int		value;
	t_list	*aux;

	aux = (*list_x);
	if (list_x == NULL || aux == NULL)
		return (-1);
	else
	{
		value = ft_atoi(aux->content);
		while (aux)
		{
			if (ft_atoi(aux->content) < value)
				value = ft_atoi(aux->content);
			aux = aux->next;
		}
	}
	return (value);
}

int	ft_lstmax(t_list **list_a)
{
	int		value;
	t_list	*aux;

	aux = (*list_a);
	if (list_a == NULL || aux == NULL)
		return (-1);
	else
	{
		value = ft_atoi(aux->content);
		while (aux)
		{
			if (ft_atoi(aux->content) > value)
				value = ft_atoi(aux->content);
			aux = aux->next;
		}
	}
	return (value);
}

int	is_sort(t_list **list_x)
{
	int		n;
	t_list	*aux;

	n = MIN;
	aux = (*list_x);
	while (aux != NULL)
	{
		if (n > ft_atoi(aux->content))
			return (0);
		n = ft_atoi(aux->content);
		aux = aux->next;
	}
	return (1);
}
