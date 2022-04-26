/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_hundred.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:16:28 by amantara          #+#    #+#             */
/*   Updated: 2022/04/26 21:04:05 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	evaluate_params(t_rules *rules, t_extreme *extreme)
{
	if (extreme->smallest_flag)
		action_ra(rules, 1);
	else
		extreme->smallest_flag = 0;
	if (extreme->big_flag || !rules->b)
	{
		extreme->after_rotate++;
	}
}

void	rotate_and_push_to_a_hundred(t_rules *rules, t_extreme *extreme)
{
	if (extreme->smallest_rotate >= 0)
		while (extreme->smallest_rotate--)
			action_rb(rules, 1);
	else if (extreme->smallest_rrotate >= 0)
		while (extreme->smallest_rrotate--)
			action_rrb(rules, 1);
	else if (extreme->big_rotate >= 0)
		while (extreme->big_rotate--)
			action_rb(rules, 1);
	else if (extreme->big_rrotate >= 0)
		while (extreme->big_rrotate--)
			action_rrb(rules, 1);
	action_pa(rules);
	evaluate_params(rules, extreme);
	reset_obj_extreme(extreme);
}

void	push_big_or_small_hundred(t_rules *rules, t_stack *stack,
		t_stack *stack_end, t_extreme *extreme)
{
	while (1)
	{
		while (stack->nbr != extreme->smallest
			&& stack->nbr != extreme->biggest)
			stack = stack->next;
		if (stack->nbr == extreme->smallest || stack->nbr == extreme->biggest)
		{
			rotate_and_push_to_a_hundred(rules, extreme);
			break ;
		}
		else
			stack = stack->next;
		if (stack == stack_end)
			break ;
		stack = rules->b;
	}
}

void	resolve_hundred(t_rules *rules, t_extreme *extreme)
{
	int	split;

	split = 1;
	find_median(rules, rules->a, extreme);
	while (rules->a && split < 3)
	{
		push_median_to_b(rules, extreme, split);
		while (rules->b)
		{
			find_biggest_b(rules, extreme);
			find_smallest_b(rules, extreme);
			find_movements(rules, extreme);
			if (rules->b && (extreme->smallest_rotate >= 0
					|| extreme->smallest_rrotate >= 0
					|| extreme->big_rotate >= 0 || extreme->big_rrotate >= 0))
				push_big_or_small_hundred(rules, rules->b,
					rules->b->prev, extreme);
		}
		while (--extreme->after_rotate)
			action_ra(rules, 1);
		split++;
	}
}
