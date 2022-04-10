/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solved.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:26:51 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/10 20:47:23 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Function return 0 if stack1 != solved. 
int solved(t_stacks *global)
{
    int i;

    i = 0;
    while (global->stack1[i] && global->stack1[i + 1]){
        if(ft_atoi(global->stack1[i]) > ft_atoi(global->stack1[i + 1]))
            return (0);
        i++;
    }
    return (1);
}