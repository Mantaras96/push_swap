/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:40:52 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/18 15:36:03 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	action_sa(t_stacks *stacks, int i)
{
	int	temp1;

	if (!stacks->a || !stacks->a->next)
		return (0);
	temp1 = stacks->a->nbr;
	stacks->a->nbr = stacks->a->next->nbr;
	stacks->a->next->nbr = temp1; 
	if (i)
		write(1, "sa\n", 3);
	return (0);
}

int	action_sb(t_stacks *stacks, int i)
{
	int	temp1;

	if (!stacks->b || !stacks->b->next)
		return (0);
	temp1 = stacks->b->nbr;
	stacks->b->nbr = stacks->b->next->nbr;
	stacks->b->next->nbr = temp1; 
	if (i)
		write(1, "sb\n", 3);
	return (0);
}

int	action_ss(t_stacks *stacks)
{
	action_sa(stacks, 0);
	action_sb(stacks, 0);
	write(1, "ss\n", 3);
	return (0);
}
