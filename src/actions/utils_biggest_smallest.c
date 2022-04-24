/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_biggest_smallest.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:27:06 by amantara          #+#    #+#             */
/*   Updated: 2022/04/24 19:33:12 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	find_biggest_a(t_rules *rules, t_extreme *extreme)
{
	t_stack	*lst;
	int		count;

	lst = rules->a;
	count = 0;
	extreme->biggest = lst->nbr;
	while (count < rules->argc)
	{
		if (lst->nbr > extreme->biggest)
			extreme->biggest = lst->nbr;
		lst = lst->next;
		count++;
	}
}

void	find_smallest_a(t_rules *rules, t_extreme *extreme)
{
	t_stack	*lst;
	int		count;

	lst = rules->a;
	count = 0;
	extreme->smallest = lst->nbr;
	while (count < rules->argc)
	{
		if (lst->nbr < extreme->smallest)
			extreme->smallest = lst->nbr;
		lst = lst->next;
		count++;
	}
}

void	find_biggest_b(t_rules *rules, t_extreme *extreme)
{
	t_stack	*lst;
	int		count;

	lst = rules->b;
	count = 0;
	extreme->biggest = lst->nbr;
	while (count < rules->argc)
	{
		if (lst->nbr > extreme->biggest)
			extreme->biggest = lst->nbr;
		lst = lst->next;
		count++;
	}
}

void	find_smallest_b(t_rules *rules, t_extreme *extreme)
{
	t_stack	*lst;
	int		count;

	lst = rules->b;
	count = 0;
	extreme->smallest = lst->nbr;
	while (count < rules->argc)
	{
		if (lst->nbr < extreme->smallest)
			extreme->smallest = lst->nbr;
		lst = lst->next;
		count++;
	}
}
