/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:27:37 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/14 21:23:13 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	action_rra(t_stacks *stacks)
{
	t_number_list	*temp1;
	t_number_list	*temp2;

	if (!stacks->a || !stacks->a->next)
		return (0);
	temp1 = stacks->a;
	while (temp1->next)
		temp1 = temp1->next;
	temp2 = temp1->next;
	temp1->next = 0;
	temp2->next = stacks->a;
	stacks->a = temp2;
	return (0);
}

void	action_rrb(t_stacks *stacks)
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
	return (0);
}

void	action_rrr(t_stacks *stacks)
{
	action_rra(stacks);
	action_rrb(stacks);
	return(0);
}
