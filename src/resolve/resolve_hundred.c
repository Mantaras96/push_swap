/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_hundred.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:16:28 by amantara          #+#    #+#             */
/*   Updated: 2022/04/24 15:33:08 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
	extreme->smallest_flag ? action_ra(rules, 1) : 0;
	(extreme->big_flag || !rules->b) ? extreme->after_rotate++ : 0;
	reset_obj_extreme(extreme);
}

void    push_big_or_small_hundred(t_rules *rules, t_stack *stack, t_stack *stack_end, t_extreme *extreme)
{
	while (1)
	{
		while (stack->nbr !=  extreme->smallest && stack->nbr != extreme->biggest)
			stack = stack->next;
		if (stack->nbr == extreme->smallest || stack->nbr == extreme->biggest)
		{
			rotate_and_push_to_a_hundred(rules, extreme);
			break ;
		}
		else
			stack = stack->next;
		if (stack == stack_end)
			break;
		stack = rules->b;
	}
}

void    resolve_hundred(t_rules *rules, t_extreme *extreme)
{
    int split;
    ft_putstr_fd("Menos 100 resolve\n", 1);
    split = 1;
    find_median(rules, rules->a, extreme);
    while (rules->a && split < 3)
    {
		ft_putstr_fd("Menos 100 resolve while\n", 1);
        push_median_to_b(rules, extreme, split);
        //while(rules->b)
        //{
			ft_putstr_fd("Menos 100 extrmee while\n", 1);
            find_biggest_b(rules, extreme);
			ft_putstr_fd("biggest:", 1);
			ft_putnbr_fd(extreme->biggest, 1);
            ft_putstr_fd("\n", 1);
			find_smallest_b(rules, extreme);
			ft_putstr_fd("smallest:", 1);
			ft_putnbr_fd(extreme->smallest, 1);
			ft_putstr_fd("\n", 1);
            find_movements(rules, extreme);
			if(rules->b && (extreme->smallest_rotate >= 0 || extreme->smallest_rrotate >= 0 || extreme->big_rotate >= 0 || extreme->big_rrotate >= 0))
			push_big_or_small_hundred(rules, rules->b, rules->b->prev, extreme);
        //}
		while(--extreme->after_rotate)
			action_ra(rules, 1);
		split++;
    }
}