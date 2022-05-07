/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver_more_hundred.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:55:48 by amantara          #+#    #+#             */
/*   Updated: 2022/05/07 16:56:28 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	value_flag(t_stack *stack, t_stack *temp1_end)
{
	if (stack == temp1_end)
	{
		return (1);
	}
	return (0);
}

int	select_for_push(int sp, t_stack *s, t_rules *r)
{
	if (sp == 1 && s->nbr <= r->quarter)
		push_first(r);
	else if (sp == 2 && s->nbr > r->quarter
		&& s->nbr <= r->median)
		push_second(r);
	else if (sp == 3 && s->nbr > r->median && s->nbr <= r->three_quarters)
		push_three(r);
	else if (sp == 4 && s->nbr > r->three_quarters)
		push_quarts(r);
	else
		return (1);
	return (0);
}

void	push_quarts_to_b(t_rules *r, t_extreme *extreme,
		int sp, t_stack *s)
{
	t_stack	*temp1_end;
	int		flag;
	int		flag2;

	temp1_end = r->a->prev;
	flag = 0;
	flag2 = 0;
	find_smallest_a(r, extreme);
	find_biggest_a(r, extreme);
	while (flag != 1)
	{
		flag = value_flag(s, temp1_end);
		flag2 = select_for_push(sp, s, r);
		if ((sp == 4 && s->nbr == extreme->smallest) && flag2 == 1)
			break ;
		else if (flag2 == 1)
			action_ra(r, 1);
		s = r->a;
	}
	reset_obj_extreme(extreme);
}

void	resolve_more_hundred(t_rules *r, t_extreme *e)
{
	int	split;

	split = 1;
	find_median(r, r->a, e);
	while (r->a && split < 5)
	{
		push_quarts_to_b(r, e, split, r->a);
		while (r->b)
		{
			find_biggest_b(r, e);
			find_smallest_b(r, e);
			find_movements(r, e);
			if (r->b && (e->smallest_rotate >= 0 || e->smallest_rrotate >= 0
					|| e->big_rotate >= 0 || e->big_rrotate >= 0))
				push_big_or_small_hundred(r, r->b, r->b->prev, e);
		}
		while (--e->after_rotate)
			action_ra(r, 1);
		split++;
	}
}
