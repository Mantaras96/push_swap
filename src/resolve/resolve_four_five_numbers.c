/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_four_five_numbers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:28:50 by amantara          #+#    #+#             */
/*   Updated: 2022/04/23 18:53:11 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	resolve_five(t_rules *rules, t_extreme *extreme)
{
	t_stack	*temp1;
	t_stack	*temp1_end;
	int		flag;

	flag = 0;
	temp1 = rules->a;
	temp1_end = rules->a->prev;
	find_median(rules, rules->a, extreme);
	while (flag != 1)
	{
		if (rules->a == temp1_end)
			flag = 1;
		if (rules->a->nbr < rules->median)
			action_pb(rules);
		else
			action_ra(rules, 1);
	}
	resolve_three_numbers(rules);
	temp1 = rules->b->next;
	if (rules->b->nbr < temp1->nbr)
		action_sb(rules, 1);
	action_pa(rules);
	action_pa(rules);
}

void	resolve_four(t_rules *rules, t_extreme *extreme)
{
	t_stack	*temp1;

	temp1 = rules->a;
	find_smallest_a(rules, extreme);
	while (temp1->nbr != extreme->smallest)
	{
		action_ra(rules, 1);
		temp1 = temp1->next;
	}
	action_pb(rules);
	resolve_three_numbers(rules);
	action_pa(rules);
}

void	resolve_4_or_5(t_rules *rules, t_extreme *extreme)
{
	if (rules->argc == 4)
	{
		resolve_four(rules, extreme);
	}
	else if (rules->argc == 5)
	{
		resolve_five(rules, extreme);
	}
}
