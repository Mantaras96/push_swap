/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_with_chunks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:44:30 by amantara          #+#    #+#             */
/*   Updated: 2022/04/16 03:38:13 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	calcule_chunks(t_stacks *stacks)
{
	if (stacks->nbr_of_element == 1 || is_sorted(stacks))
		return (-1);
	else if (stacks->nbr_of_element == 2 || stacks->nbr_of_element == 3)
		return (0);
	else if (stacks->nbr_of_element < 20)
		return (1);
	else if (stacks->nbr_of_element < 50)
		return (2);
	else if (stacks->nbr_of_element < 200)
		return (6);
	return (-1);
}

void	send_to_a_in_order(t_stacks *stacks)
{
	int	biggest_nbr_i;
	int	size;

	while (stacks->b)
	{
		size = ft_stacklen(stacks->b);
		biggest_nbr_i = get_biggest_number_i(stacks->b);
		if (biggest_nbr_i == 1)
		{
			action_sb(stacks, 1);
			continue ;
		}
		else
		{
			action_pa(stacks);
			continue ;
		}
		if (biggest_nbr_i <= size / 2)
			action_rb(stacks, 1);
		else
			action_rrb(stacks, 1);
	}
}

void	sort_stack_chunks(t_stacks *stacks)
{
	int	chunks;

	chunks = calcule_chunks(stacks);
	if (chunks == -1)
		return ;
	else if (chunks == 0)
		order_two_three_numbers(stacks);
	else if (chunks == 1)
	{
		order_twenty_numbers(stacks);
		order_two_three_numbers(stacks);
	}
	send_to_a_in_order(stacks);
}

	// else if (chunks == 2)
	//     order_fifty_numbers(stacks);
	// else if (chunks == 6)
	//     order_two_hundred(stacks);