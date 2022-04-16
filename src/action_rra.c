/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:27:37 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/15 23:03:37 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	action_rra(t_stacks *stacks, int i)
{
	t_number_list	*temp1;
	t_number_list	*temp2;

	if (!stacks->a || !stacks->a->next)
		return (0);
	temp1 = stacks->a;
	while (temp1->next->next)
		temp1 = temp1->next;
	temp2 = temp1->next;
	temp1->next = 0;
	temp2->next = stacks->a;
	stacks->a = temp2;
	if (i)
		write(1, "rra", 3);
	return (0);
}

int	action_rrb(t_stacks *stacks, int i)
{
	t_number_list	*temp1;
	t_number_list	*temp2;

	if (!stacks->b || !stacks->b->next)
		return (0);
	temp1 = stacks->b;
	while (temp1->next)
		temp1 = temp1->next;
	temp2 = temp1->next;
	temp1->next = 0;
	temp2->next = stacks->b;
	stacks->b = temp2;
	if (i)
		write(1, "rrb", 3);
	return (0);
}

int	action_rrr(t_stacks *stacks)
{
	action_rra(stacks, 0);
	action_rrb(stacks, 0);
	write(1, "rrr", 3);
	return (0);
}
