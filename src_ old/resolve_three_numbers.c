/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_three_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:55:31 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/23 13:02:58 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*create_stack_numbers(t_stacks *global)
{
	int				i;
	t_number_list	*temp1;
	int				*stack_numbers;

	temp1 = global->a;
	stack_numbers = (int *)malloc(sizeof(int) * 4);
	i = 0;
	while (i <= 2)
	{
		stack_numbers[i] = temp1->nbr;
		if (temp1->next)
			temp1 = temp1->next;
		i++;
	}
	stack_numbers[i] = '\0';
	return (stack_numbers);
}



void	resolve_three_numbers(t_stacks *stacks)
{
	int	*stack_numbers;

	stack_numbers = create_stack_numbers(stacks);
	if (get_case(stack_numbers) == 1)
		action_sa(stacks, 1);
	else if (get_case(stack_numbers) == 2)
	{
		action_sa(stacks, 1);
		action_rra(stacks, 1);
	}
	else if (get_case(stack_numbers) == 3)
		action_ra(stacks, 1);
	else if (get_case(stack_numbers) == 4)
	{
		action_sa(stacks, 1);
		action_ra(stacks, 1);
	}
	else if (get_case(stack_numbers) == 5)
		action_rra(stacks, 1);
}

int	ft_stacklen(t_number_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	order_two_three_numbers(t_stacks *stacks)
{
	int	list_size;

	list_size = ft_stacklen(stacks->a);
	if (list_size == 2)
	{
		action_sa(stacks, 1);
	}
	else if (list_size == 3)
		resolve_three_numbers(stacks);
}
