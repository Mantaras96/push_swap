/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_ra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:07:24 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/10 19:46:18 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void action_ra(char **stack, int writ)
{
    int     i;
    char    *temp;

    i = 0;
    temp = stack[0];
    while (stack[i] && stack[i + 1]){
        stack[i] = stack[i + 1];
        stack[i + 1] = temp;
        i++;
    }
    stack[i] = temp;
    if (writ)
    write(1, "ra\n", 3);
}

void action_rb(char **stack, int writ)
{
    int     i;
    char    *temp;

    i = 0;
    temp = stack[0];
    while (stack[i] && stack[i + 1]){
        stack[i] = stack[i + 1];
        stack[i + 1] = temp;
        i++;
    }
    stack[i] = temp;
    if (writ)
    write(1, "rb\n", 3);
}

void action_rr(char **stacka, char **stackb)
{
    action_ra(stacka, 0);
    action_rb(stackb, 0);
    write(1, "rr\n", 3);
}
