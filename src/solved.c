/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solved.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:26:51 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/10 11:58:19 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Function return 0 if stack1 != solved. 
int solved(t_stacks *global)
{
    int i;

    while (global->stack1[i] && global->stack1[i + 1]){
        if(ft_atoi(global->stack1[i]) > global->stack1[i + 1])
            return (0);
    }
    return (1);
}