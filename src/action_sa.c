/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:40:52 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/15 22:45:55 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	action_sa(t_stacks *stacks, int i)
{
	t_number_list	*temp1;
	t_number_list	*temp2;

	if (!stacks->a || !stacks->a->next)
		return (0);
	temp1 = stacks->a;
	temp2 = stacks->a->next->next;
	stacks->a = stacks->a->next;
	stacks->a->next = temp1;
	stacks->a->next->next = temp2;
	if (i)
		write(1, "sa", 2);
	return (0);
}

int	action_sb(t_stacks *stacks, int i)
{
	t_number_list	*temp1;
	t_number_list	*temp2;

	if (!stacks->b || !stacks->b->next)
		return (0);
	temp1 = stacks->b;
	temp2 = stacks->b->next->next;
	stacks->b = stacks->b->next;
	stacks->b->next = temp1;
	stacks->b->next->next = temp2;
	if (i)
		write(1, "sb", 2);
	return (0);
}

int	action_ss(t_stacks *stacks)
{
	action_sa(stacks, 0);
	action_sb(stacks, 0);
	write(1, "ss", 2);
	return (0);
}
