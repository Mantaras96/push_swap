/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_four_five_numbers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:21:46 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/10 20:32:15 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// int put_middle(t_stacks *global, int i)
// {
	
// }

void	resolve_the_middle(t_stacks *global)
{
	int	i;

	i = 0;
	while (global->stack1[i] && global->stack1[i + 1])
	{
		if (ft_atoi(global->stack1[i]) < ft_atoi(global->stack2[0])
			&& ft_atoi(global->stack2[0]) < ft_atoi(global->stack1[i + 1]))
			{
			//return (put_middle(global, i + 1));
		}
		i++;
	}			
}

void    resolve_stackb_to_stacka(t_stacks *global)
{
	if (ft_atoi(global->stack1[0]) < ft_atoi(global->stack2[0]))
		action_pb(global->stack2, global->stack1);
	else if (ft_atoi(global->stack1[2]) < ft_atoi(global->stack2[0])){
		action_pb(global->stack2, global->stack1);
		action_ra(global->stack1, 1);   
	}
	else 
	{
		resolve_the_middle(global);	
	}
}


void    resolve_four_five_numbers(t_stacks *global)
{
	if (global->total == 4)
	action_pb(global->stack1, global->stack2);
	else {
		action_pb(global->stack1, global->stack2);
		action_pb(global->stack1, global->stack2);
	}
	resolve_three_numbers(global);
	resolve_stackb_to_stacka(global);
}