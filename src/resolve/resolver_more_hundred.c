/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver_more_hundred.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:55:48 by amantara          #+#    #+#             */
/*   Updated: 2022/04/24 19:29:20 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_quarts_to_b(t_rules *rules, t_extreme *extreme, int split, t_stack *stack)
{
	t_stack	*temp1_end;
	int		flag;

	temp1_end = rules->a->prev;
	flag = 0;
	find_smallest_a(rules, extreme);
	find_biggest_a(rules, extreme);
	while (flag != 1)
	{
		stack == temp1_end ? flag = 1 : 0;
		if (split == 1 && stack->nbr <= rules->quarter)
			push_first(rules);
		else if (split == 2 && stack->nbr > rules->quarter && stack->nbr <= rules->median)
			push_second(rules);
		else if (split == 3 && stack->nbr > rules->median && stack->nbr <= rules->three_quarters)
			push_three(rules);
		else if (split == 4 && stack->nbr > rules->three_quarters)
			push_quarts(rules);
		else if (split == 4 && stack->nbr == extreme->smallest)
			break ;
		else
			action_ra(rules, 1);
		stack = rules->a;
	}
	reset_obj_extreme(extreme);
}

void	resolve_more_hundred(t_rules *rules, t_extreme *extreme)
{
	int	split;

	split = 1;
	find_median(rules, rules->a, extreme);
	while (rules->a && split < 5)
	{
		push_quarts_to_b(rules, extreme, split, rules->a);
		while (rules->b)
		{
			find_biggest_b(rules, extreme);
			find_smallest_b(rules, extreme);
			find_movements(rules, extreme);
			if (rules->b && (extreme->smallest_rotate >= 0 || extreme->smallest_rrotate >= 0 || extreme->big_rotate >= 0 || extreme->big_rrotate >= 0))
				push_big_or_small_hundred(rules, rules->b, rules->b->prev, extreme);
		}
		while (--extreme->after_rotate)
			action_ra(rules, 1);
		split++;
	}
}
