/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:41:55 by ralopez-          #+#    #+#             */
/*   Updated: 2022/10/11 14:41:58 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define MAX 2147483647
# define MIN -2147483648

typedef struct s_info
{
	int	size_a;
	int	size_b;
	int	mid;
	int	pivot;
}	t_info;

int		ft_strcmp(char *s1, char *s2);
int		no_duplicate(t_list **list_a);
int		validate_argv(int argc, char **argv);
void	sa(t_list **list_a, int print);
void	sb(t_list **list_b, int print);
void	ss(t_list **list_a, t_list **list_b);
void	pa(t_list **list_a, t_list **list_b);
void	pb(t_list **list_a, t_list **list_b);
void	ra(t_list **list_a, int print);
void	rb(t_list **list_a, int print);
void	rr(t_list **list_a, t_list **list_b);
void	rra(t_list **list_a, int print);
void	rrb(t_list **list_a, int print);
void	rrr(t_list **list_a, t_list **list_b);
void	ft_lstdelete_last(t_list **list_a);
int		is_sort(t_list **list_x);
int		ft_lstmax(t_list **list_a);
int		ft_lstmin(t_list **list_a);
void	pass_elements(t_list **list_a, t_list **list_b);
void	sort_small(t_list **list_a, t_list **list_b);
int		find_element(int min, t_list **list_a);
void	sort_big(t_list **list_a, t_list **list_b, t_info *info);
int		ft_lstfirst(t_list **list_a);
#endif