/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_pa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 10:46:17 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/11 23:33:52 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	action_pa(t_stacks *stacks)
{
	t_number_list *temp1;

	if (!stacks->b)
		return (0);
	temp1 = stacks->b->next;
	stacks->b->next = stacks->a;
	stacks->a = stacks->b;
	stacks->b = temp1;
	return (0); 
}

void	action_pb(t_stacks *stacks)
{
	t_number_list *temp1;

	if (!stacks->a)
		return (0);
	temp1 = stacks->a->next;
	stacks->a->next = stacks->b;
	stacks->b = stacks->a;
	stacks->a = temp1;
	return (0);
}
