/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:40:52 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/10 13:59:06 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void action_sa(char **stack, int writ)
{
    char  *temp;

    temp = stack[0];
    stack[0] = stack[1];
    stack[1] = temp;
    if (writ)
    write(1, "sa\n", 3);
}

void action_sb(char **stack, int writ)
{
    char  *temp;

    temp = stack[0];
    stack[0] = stack[1];
    stack[1] = temp;
    if (writ)
    write(1, "sb\n", 3);
}

void action_ss(char **stacka, char **stackb){
    action_sa(stacka, 0);
    action_sb(stackb, 0);
    write(1, "ss\n", 1);
}


void action_rra(char **stack){
    int lenght;
    char *temp;

    lenght = get_lenght_stack(stack);
    
}

