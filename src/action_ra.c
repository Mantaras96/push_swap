/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_ra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:07:24 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/14 21:14:00 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	action_ra(t_stacks *stacks)
{
	t_number_list temp1;
	t_number_list temp2;

	if (!stacks->a || !stacks->a->next)
		return (0);

	temp1 = stacks->a->next;
	temp2 = temp1;
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = stacks->a;
	stacks->a->next = 0;
	stacks->a = temp1;
	return(0);
}

void	action_rb(t_stacks *stacks)
{
	t_number_list temp1;
	t_number_list temp2;

	if (!stacks->b || !stacks->b->next)
		return (0);

	temp1 = stacks->b->next;
	temp2 = temp1;
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = stacks->b;
	stacks->b->next = 0;
	stacks->b = temp1;
	return(0);
}

void	action_rr(t_stacks *stacks)
{
	action_ra(stacks);
	action_rb(stacks);
	return(0);
}
