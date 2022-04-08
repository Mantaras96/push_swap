/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_ra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:07:24 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/08 17:26:59 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h";

// int get_lenght_stack(char **stack){
//     int i;
//     int j;

//     i = 0;
//     while(stack[i]){
//         j = 0;
//         while (stack[i][j]){
//             j++;
//         }
//         i++;
//     }
//     return (i);
// }

void operation_ra(char **stack){
    int     i;
    char    *temp;

    temp = stack[0];
    while (stack[i] && stack[i + 1]){
        stack[i] = stack[i + 1];
        stack[i + 1] = temp;
        i++;
    }
    stack[i] = temp;
    write(1, "ra\n", 3);
}

void operation_rb(char **stack){
    int     i;
    char    *temp;

    temp = stack[0];
    while (stack[i] && stack[i + 1]){
        stack[i] = stack[i + 1];
        stack[i + 1] = temp;
        i++;
    }
    stack[i] = temp;
    write(1, "rb\n", 3);
}

void operation_rr(char **stacka, char **stackb){
    operation_ra(stacka);
    operation_rb(stackb);
    write(1, "rr\n", 3);
}
