/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solved.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:26:51 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/22 17:05:03 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Function return 0 if stack1 != solved. 
int	is_sorted(t_rules *stack)
{
	t_stack	*temp1;

	temp1 = stack->a;
	while (temp1 && temp1->next)
	{
		if (temp1->nbr > temp1->next->nbr)
			return (0);
		temp1 = temp1->next;
	}
	return (1);
}
