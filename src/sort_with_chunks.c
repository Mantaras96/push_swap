/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_with_chunks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:44:30 by amantara          #+#    #+#             */
/*   Updated: 2022/04/18 13:11:21 by amantara         ###   ########.fr       */
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

//	El numero base se encarga de que el y todos los numeros 
// inferiores se envien al stack b y procedera a ordenarlos.
//	El numero base se calcula de la siguiente manera 
// ( count(nbr < numerobase) = size_stacks / numero de chunks);
void	sort_stack_chunks(t_stacks *stacks)
{
	int	chunks;
	int	base_number;

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
	while (chunks > 1)
	{
		base_number = find_number(chunks, stacks->a, ft_stacklen(stacks->a));
		send_under_base_to_b(base_number, stacks);
		chunks--;
		if (chunks == 0)
		{
			order_twenty_numbers(stacks);
			order_two_three_numbers(stacks);
		}
	}
	send_to_a_in_order(stacks);
}

	// else if (chunks == 2)
	//     order_fifty_numbers(stacks);
	// else if (chunks == 6)
	//     order_two_hundred(stacks);