/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_pa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 10:46:17 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/09 11:57:13 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void action_pa(char **stacka, char **stackb){
    stacka = addNumberToStack(stacka, stackb[0]),
    delNumberFromStack(stackb);
    write(1, "pa\n", 3);
}

char **addNumberToStack(char **stacka, char *number_add)
{
    int i;
    int j;
    char **str;

    while (stacka[i])
        i++;
    str = (char **)malloc(sizeof (char *) * (i + 2));
    if (!str)
        return (NULL);

    str[0] = number_add;
    i = 0;
    j = 1;
    while (stacka[i]){
        str[j++] = stacka[i++];
    }
    str[j] = "\0";
    free(stacka);
    return (str);
}

void delNumberFromStack(char **stackb)
{
    int i;
    char **str;

    while(stackb[i])
        i++;
    str = (char **)malloc(sizeof(char *) * i);
    if (!str)
        return (NULL);
    i = 1;
    while(stackb[i])
    {
        str[i - 1] = str[i];
        i++;
    }
}

void action_pb(char **stacka, char **stackb)
{
    stackb = addNumberToStack(stackb, stacka[0]),
    delNumberFromStack(stacka);
    write(1, "pb\n", 3);
}