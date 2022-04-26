/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:12:29 by amantara          #+#    #+#             */
/*   Updated: 2022/04/26 19:59:19 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	moves_rrotate(t_rules *rules, int element)
{
	t_stack	*temp1;
	int		count_moves;

	count_moves = 0;
	temp1 = rules->b;
	while (temp1->nbr != element)
	{
		count_moves++;
		temp1 = temp1->prev;
	}
	return (count_moves);
}

void	moves_biggest(t_rules *rules, t_extreme *extreme)
{
	if (rules->b)
	{
		extreme->big_rotate = moves_rotate(rules, extreme->biggest);
		extreme->big_rrotate = moves_rrotate(rules, extreme->biggest);
		if (extreme->big_rotate <= extreme->big_rrotate)
			extreme->big_rrotate = -1;
		else
			extreme->big_rotate = -1;
	}
}

void	moves_smallest(t_rules *rules, t_extreme *extreme)
{
	if (rules->b)
	{
		extreme->smallest_rotate = moves_rotate(rules, extreme->smallest);
		extreme->smallest_rrotate = moves_rrotate(rules, extreme->smallest);
		if (extreme->smallest_rotate <= extreme->smallest_rrotate)
			extreme->smallest_rrotate = -1;
		else
			extreme->smallest_rotate = -1;
	}
}

void	set_rotate_flag(t_extreme *e)
{
	if (e->big_rotate != -1 && (e->big_rotate >= e->smallest_rotate
			&& e->big_rotate >= e->smallest_rrotate))
	{
		e->big_rotate = -1;
		e->smallest_flag = 1;
	}
	else if (e->big_rrotate != -1 && (e->big_rrotate >= e->smallest_rotate
			&& e->big_rrotate >= e->smallest_rrotate))
	{
		e->big_rrotate = -1;
		e->smallest_flag = 1;
	}
	else if (e->smallest_rotate != -1 && (e->big_rrotate <= e->smallest_rotate
			&& e->big_rotate <= e->smallest_rotate))
	{
		e->smallest_rotate = -1;
		e->big_flag = 1;
	}
	else if (e->smallest_rrotate != -1 && (e->big_rrotate <= e->smallest_rrotate
			&& e->big_rotate <= e->smallest_rrotate))
	{
		e->smallest_rrotate = -1;
		e->big_flag = 1;
	}
}

void	find_movements(t_rules *rules, t_extreme *extreme)
{
	t_stack	*s;

	s = rules->b;
	moves_smallest(rules, extreme);
	moves_biggest(rules, extreme);
	set_rotate_flag(extreme);
}
