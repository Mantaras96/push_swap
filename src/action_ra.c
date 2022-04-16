/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_ra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:07:24 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/15 22:46:16 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	action_ra(t_stacks *stacks, int i)
{
	t_number_list	*temp1;
	t_number_list	*temp2;

	if (!stacks->a || !stacks->a->next)
		return (0);
	temp1 = stacks->a->next;
	temp2 = temp1;
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = stacks->a;
	stacks->a->next = 0;
	stacks->a = temp1;
	if (i)
		write(1, "ra", 2);
	return (0);
}

int	action_rb(t_stacks *stacks, int i)
{
	t_number_list	*temp1;
	t_number_list	*temp2;

	if (!stacks->b || !stacks->b->next)
		return (0);
	temp1 = stacks->b->next;
	temp2 = temp1;
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = stacks->b;
	stacks->b->next = 0;
	stacks->b = temp1;
	if (i)
		write(1, "rb", 2);
	return (0);
}

int	action_rr(t_stacks *stacks)
{
	action_ra(stacks, 0);
	action_rb(stacks, 0);
	write(1, "rr", 2);
	return (0);
}
