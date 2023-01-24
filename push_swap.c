/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:15:59 by ralopez-          #+#    #+#             */
/*   Updated: 2022/11/10 09:51:36 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_content(void *string)
{
	if (string != NULL)
		free(string);
}

void	fill_list(int argc, char **argv, t_list **list_a)
{
	int		i;
	int		a;
	char	**cad;
	t_list	*aux;

	i = 1;
	while (i < argc)
	{
		cad = ft_split(argv[i], ' ');
		a = -1;
		while (cad[++a])
		{
			aux = ft_lstnew((void *)ft_itoa((ft_atoi(cad[a]))));
			ft_lstadd_back(list_a, aux);
		}
		ft_split_clear(cad, &free_content);
		i++;
	}
}

int	find_element(int min, t_list **list_a)
{
	int		position;
	t_list	*aux;

	position = 0;
	aux = (*list_a);
	if (list_a == NULL || aux == NULL)
		return (-1);
	else
	{
		while (aux)
		{
			if (ft_atoi(aux->content) == min)
				return (position);
			aux = aux->next;
			position++;
		}
	}
	return (-1);
}

void	short_list(t_list **list_a, t_list **list_b, t_info *info)
{
	if (ft_lstsize((*list_a)) > 8)
		sort_big(list_a, list_b, info);
	else
		sort_small(list_a, list_b);
	ft_lstclear(list_a, &free_content);
	ft_lstclear(list_b, &free_content);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	t_info	info;

	list_a = NULL;
	list_b = NULL;
	if (argc == 1)
		return (0);
	if (validate_argv(argc, argv) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	fill_list(argc, argv, &list_a);
	if (no_duplicate(&list_a) == 0)
	{
		ft_lstclear(&list_a, &free_content);
		ft_printf("Error\n");
		return (0);
	}
	short_list(&list_a, &list_b, &info);
	return (0);
}
