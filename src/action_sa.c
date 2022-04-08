/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:40:52 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/08 16:06:56 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void operation_sa(char **stack){
    char  *temp;

    temp = stack[0];
    stack[0] = stack[1];
    stack[1] = temp;
    write(1, "sa\n", 3);
}

void operation_sb(char **stack){
    char  *temp;

    temp = stack[0];
    stack[0] = stack[1];
    stack[1] = temp;
    write(1, "sb\n", 3);
}

void operation_ss(char **stacka, char **stackb){
    operation_sa(stacka);
    operation_sb(stackb);
    write(1, "ss\n", 1);
}


void operation_rra(char **stack){
    int lenght;
    char *temp;

    lenght = get_lenght_stack(stack);
    
}

