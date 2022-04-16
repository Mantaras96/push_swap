/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_pa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 10:46:17 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/15 22:46:51 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	action_pa(t_stacks *stacks)
{
	t_number_list	*temp1;

	if (!stacks->b)
		return (0);
	temp1 = stacks->b->next;
	stacks->b->next = stacks->a;
	stacks->a = stacks->b;
	stacks->b = temp1;
	write(1, "pa", 2);
	return (0);
}

int	action_pb(t_stacks *stacks)
{
	t_number_list	*temp1;

	if (!stacks->a)
		return (0);
	temp1 = stacks->a->next;
	stacks->a->next = stacks->b;
	stacks->b = stacks->a;
	stacks->a = temp1;
	write(1, "pb", 2);
	return (0);
}
