/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_three_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:55:31 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/11 23:45:53 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*create_stack_numbers(t_stacks *global)
{
	int	i;
	int	*stack_numbers;

	stack_numbers = (int *)malloc(sizeof(int) * global->total);
	i = 0;
	while (global->stack1[i])
	{
		stack_numbers[i] = ft_atoi(global->stack1[i]);
		i++;
	}
	return (stack_numbers);
}

/*
Max 5 cases
	Case 1: SA
	Case 2: sa, rra
	Case 3: ra
	Case 4: sa, ra
	Case 5: rra
*/
int	get_case(int *number)
{
	if (number[2] > number[0] && number[2] > number[1] && number[1] < number[0])
		return (1);
	else if (number[2] < number[0] && number[2] < number[1]
		&& number[1] < number[0])
		return (2);
	else if (number[2] < number[0] && number[2] > number[1]
		&& number[1] < number[0])
		return (3);
	else if (number[2] > number[0] && number[2] < number[1]
		&& number[1] > number[0])
		return (4);
	else if (number[2] < number[0] && number[2] < number[1]
		&& number[1] > number[0])
		return (5);
	else
		return (0);
}

void	resolve_three_numbers(t_stacks *global)
{
	int	*stack_numbers;

	stack_numbers = create_stack_numbers(global);
	if (get_case(stack_numbers) == 1)
		action_sa(global->stack1, 1);
	else if (get_case(stack_numbers) == 2)
	{
		action_sa(global->stack1, 1);
		action_rra(global->stack1, 1);
	}
	else if (get_case(stack_numbers) == 3)
		action_ra(global->stack1, 1);
	else if (get_case(stack_numbers) == 4)
	{
		action_sa(global->stack1, 1);
		action_ra(global->stack1, 1);
	}
	else if (get_case(stack_numbers) == 5)
		action_rra(global->stack1, 1);
}
