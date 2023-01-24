/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:21:50 by ralopez-          #+#    #+#             */
/*   Updated: 2022/10/22 11:21:51 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pass_elements(t_list **list_a, t_list **list_b)
{
	int		i;
	int		top;

	i = 0;
	top = 0;
	while (i++ < 2)
	{
		if (find_element(ft_lstmin(list_a), list_a) < ft_lstsize((*list_a)) / 2)
			top = 1;
		while (ft_atoi((*list_a)->content) != ft_lstmin(list_a))
		{
			if (top == 1)
				ra(list_a, 1);
			else
				rra(list_a, 1);
		}
		pb(list_a, list_b);
	}
}

void	sort_small(t_list **list_a, t_list **list_b)
{
	t_list	*aux;
	int		size;

	if (is_sort(list_a))
		return ;
	size = ft_lstsize((*list_a));
	if (size > 3)
		pass_elements(list_a, list_b);
	while (!is_sort(list_a))
	{
		aux = (*list_a);
		if (ft_atoi(aux->content) >= ft_lstmax(list_a))
			ra(list_a, 1);
		else if (ft_atoi(aux->content) > ft_atoi(aux->next->content))
			sa(list_a, 1);
		else
			ra(list_a, 1);
	}
	if (size > 3)
	{
		pa(list_a, list_b);
		pa(list_a, list_b);
	}
}
