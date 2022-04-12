/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_resolve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:15:44 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/11 23:43:30 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	start_resolve(t_stacks *global)
{
	if (solved(global) == 1)
		ft_putstr_fd("Ordenado", 1);
	else
	{
		if (global->total == 2)
			action_sa(global->stack1, 1);
		else if (global->total == 3)
			resolve_three_numbers(global);
		else if (global->total <= 5)
			resolve_four_five_numbers(global);
	}	
}
