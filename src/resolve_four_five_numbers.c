/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_four_five_numbers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:21:46 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/10 16:06:13 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    resolve_four_five_numbers(t_stacks *global)
{
    if (global->total == 4)
    action_pb(global->stack1, global->stack2);
    else {
        action_pb(global->stack1, global->stack2);
        action_pb(global->stack1, global->stack2);
    }
    resolve_three_numbers(global);
}