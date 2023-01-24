/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:36:39 by ralopez-          #+#    #+#             */
/*   Updated: 2022/10/22 11:36:40 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble(int **list, int len)
{
	int	i;
	int	a;
	int	aux;

	i = 0;
	while (i < len)
	{
		a = 0;
		while (a < len)
		{
			if (a != i && (*list)[i] < (*list)[a])
			{
				aux = (*list)[i];
				(*list)[i] = (*list)[a];
				(*list)[a] = aux;
			}
			a++;
		}
		i++;
	}
}

int	midpoint(t_list **list_a)
{
	int		*list;
	t_list	*aux;
	int		i;
	int		r;

	i = 0;
	aux = (*list_a);
	list = malloc(sizeof(int) * ft_lstsize((*list_a)) + 1);
	while (aux != NULL)
	{
		list[i] = ft_atoi(aux->content);
		aux = aux->next;
		i++;
	}
	bubble((&list), ft_lstsize((*list_a)));
	r = list[(ft_lstsize((*list_a)) / 2)];
	free(list);
	return (r);
}

void	rotate(t_list **list_a, t_list **list_b, t_info *info, int aux)
{
	while (aux && info->size_a > 2)
	{
		if (ft_atoi((*list_a)->content) < info->pivot)
		{
			pb(list_a, list_b);
			if (info->size_b > 1
				&& (ft_atoi((*list_b)->content) < midpoint(list_b)))
			{
				if (ft_atoi((*list_b)->content) > info->pivot)
					rr(list_a, list_b);
				else
					rb(list_b, 1);
			}
			info->size_a--;
			info->size_b++;
		}
		else
			ra(list_a, 1);
		aux--;
	}
}

void	to_stack_a(t_list **list_a, t_list **list_b, t_info *info)
{
	int	top_b;

	while (info->size_b)
	{
		top_b = 0;
		if (find_element(ft_lstmax(list_b), list_b) < ft_lstsize(*list_b) / 2)
			top_b = 1;
		while (ft_lstmax(list_b) != ft_lstfirst(list_b))
		{
			if (top_b == 1)
				rb(list_b, 1);
			else
				rrb(list_b, 1);
		}
		pa(list_a, list_b);
		info->size_a++;
		if (info->size_a >= 2
			&& ft_atoi((*list_a)->content) > ft_atoi((*list_a)->next->content))
			sa(list_a, 1);
		info->size_b--;
	}
}

void	sort_big(t_list **list_a, t_list **list_b, t_info *info)
{
	info->size_a = ft_lstsize((*list_a));
	info->size_b = 0;
	if (is_sort(list_a) == 1)
		return ;
	while (info->size_a > 2)
	{
		info->pivot = midpoint(list_a);
		rotate(list_a, list_b, info, info->size_a);
		ft_lstsize((*list_a));
	}
	pb(list_a, list_b);
	pb(list_a, list_b);
	info->size_b += 2;
	info->size_a -= 2;
	to_stack_a(list_a, list_b, info);
}
