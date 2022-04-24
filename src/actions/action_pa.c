/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_pa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 10:46:17 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/24 15:55:32 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	delete_first_element(t_rules *rules, int stack)
{
	t_stack	**temp1;
	t_stack	*temp2;

	if (stack == 1)
		temp1 = &rules->a;
	else
		temp1 = &rules->b;
	if (*temp1)
	{
		if ((*temp1)->next == *temp1)
		{
			free(*temp1);
			*temp1 = NULL;
		}
		else
		{
			temp2 = *temp1;
			*temp1 = (*temp1)->next;
			temp2->prev->next = *temp1;
			(*temp1)->prev = temp2->prev;
			free(temp2);
		}
	}
}

void	add_first_element(t_rules *rules, int stack, int num)
{
	t_stack	**temp1;
	t_stack	*temp2;

	if (stack == 1)
		temp1 = &rules->a;
	else
		temp1 = &rules->b;
	if (*temp1)
	{
		temp2 = (t_stack *)malloc(sizeof(t_stack));
		temp2->next = *temp1;
		temp2->prev = (*temp1)->prev;
		(*temp1)->prev = temp2;
		temp2->prev->next = temp2;
		temp2->nbr = num;
		*temp1 = (*temp1)->prev;
	}
	else
	{
		*temp1 = (t_stack *)malloc(sizeof(t_stack));
		(*temp1)->next = *temp1;
		(*temp1)->prev = *temp1;
		(*temp1)->nbr = num;
	}
}

int	action_pa(t_rules *stacks)
{
	long int	aux_num;

	if (stacks->b)
	{
		aux_num = stacks->b->nbr;
		delete_first_element(stacks, 2);
		add_first_element(stacks, 1, aux_num);
	}
	write(1, "pa\n", 3);
	return (0);
}

int	action_pb(t_rules *stacks)
{
	long int	aux_num;

	if (stacks->a)
	{
		aux_num = stacks->a->nbr;
		delete_first_element(stacks, 1);
		add_first_element(stacks, 2, aux_num);
	}
	write(1, "pb\n", 3);
	return (0);
}
