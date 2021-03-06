/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_ra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:07:24 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/23 18:54:40 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	action_ra(t_rules *stacks, int i)
{	
	if (stacks->a)
		stacks->a = stacks->a->next;
	if (i)
		write(1, "ra\n", 3);
	return (0);
}

int	action_rb(t_rules *stacks, int i)
{
	if (stacks->b)
		stacks->b = stacks->b->next;
	if (i)
		write(1, "rb\n", 3);
	return (0);
}

int	action_rr(t_rules *stacks)
{
	action_ra(stacks, 0);
	action_rb(stacks, 0);
	write(1, "rr\n", 3);
	return (0);
}
