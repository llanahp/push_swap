/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:04:40 by ralopez-          #+#    #+#             */
/*   Updated: 2022/10/11 17:04:41 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	no_duplicate(t_list **list)
{
	t_list	**list_copy;
	t_list	*list_elem_cp;
	t_list	*list_element;
	int		result;

	result = 1;
	list_copy = list;
	list_element = (*list);
	list_elem_cp = (*list);
	while (result == 1 && list_element != NULL )
	{
		list_elem_cp = (*list);
		while (result == 1 && list_elem_cp != NULL)
		{
			if ((list_element != list_elem_cp)
				&& ft_strcmp(list_element->content, list_elem_cp->content) == 0)
				result = 0;
			list_elem_cp = list_elem_cp->next;
		}
		list_element = list_element ->next;
	}
	return (result);
}

int	ft_atoi_limits(const char *str)
{
	int						i;
	int						sig;
	unsigned long long int	num;

	num = 0;
	i = 0;
	sig = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sig = (sig * -1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if ((long long int)(num * sig) > 2147483647
		|| (long long int)(num * sig) < -2147483648)
		return (-1);
	return (sig * num);
}

int	out_limits(char *string)
{
	int		num;
	char	*cad;

	num = ft_atoi_limits(string);
	cad = ft_itoa(num);
	if (num > MAX || num < MIN || ft_strcmp(string, cad))
	{
		free(cad);
		return (1);
	}
	else
	{
		free(cad);
		return (0);
	}
}

int	validate_numbers(int argc, char **argv)
{
	int		i;
	int		a;
	char	**cad;
	int		res;

	i = 1;
	res = 1;
	while (i < argc && res)
	{
		cad = ft_split(argv[i], ' ');
		a = -1;
		while (cad[++a] && res)
		{
			if (out_limits(cad[a]) == 1)
				res = 0;
		}
		a = -1;
		while (cad[++a])
		{
			free(cad[a]);
		}
		free(cad);
		i++;
	}
	return (res);
}

int	validate_argv(int argc, char **argv)
{
	int	i;
	int	result;
	int	a;

	i = 0;
	result = 1;
	while (++i < argc && result)
	{
		a = 0;
		while (argv[i][a] && result)
		{
			if (!ft_isdigit((int)argv[i][a])
				&& ((int)argv[i][a] != '-' && (int)argv[i][a] != ' '))
				result = 0;
			a++;
		}
	}
	if (result == 0)
		return (0);
	else
		return (validate_numbers(argc, argv));
}
