/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 10:25:20 by amantara          #+#    #+#             */
/*   Updated: 2022/04/24 19:27:12 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	solve_numbers(t_rules *rules, t_extreme *extreme)
{
	if (rules->argc < 4)
	{
		order_two_three_numbers(rules);
	}
	else if (rules->argc <= 5)
		resolve_4_or_5(rules, extreme);
	else if (rules->argc <= 100)
		resolve_hundred(rules, extreme);
	else
		resolve_more_hundred(rules, extreme);
}
