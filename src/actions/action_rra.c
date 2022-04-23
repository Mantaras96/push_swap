/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:27:37 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/23 18:54:31 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	action_rra(t_rules *stacks, int i)
{
	if (stacks->a)
		stacks->a = stacks->a->prev;
	if (i)
		write(1, "rra\n", 4);
	return (0);
}

int	action_rrb(t_rules *stacks, int i)
{
	if (stacks->b)
		stacks->b = stacks->b->prev;
	if (i)
		write(1, "rrb\n", 4);
	return (0);
}

int	action_rrr(t_rules *stacks)
{
	action_rra(stacks, 0);
	action_rrb(stacks, 0);
	write(1, "rrr\n", 4);
	return (0);
}
