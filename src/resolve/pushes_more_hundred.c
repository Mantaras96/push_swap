/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes_more_hundred.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:21:37 by amantara          #+#    #+#             */
/*   Updated: 2022/04/24 19:33:02 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_first(t_rules *rules)
{
	if (rules->b && rules->b->nbr > (rules->quarter / 2))
		action_rb(rules, 1);
	action_pb(rules);
}

void	push_second(t_rules *rules)
{
	if (rules->b && rules->b->nbr > (rules->median / 4) * 3)
		action_rb(rules, 1);
	action_pb(rules);
}

void	push_three(t_rules *rules)
{
	if (rules->b && rules->b->nbr > (rules->median / 4) * 5)
		action_rb(rules, 1);
	action_pb(rules);
}

void	push_quarts(t_rules *rules)
{
	if (rules->b && rules->b->nbr > (rules->median / 4) * 7)
		action_rb(rules, 1);
	action_pb(rules);
}
