/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_save.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:54:20 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/09 17:03:29 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

create_and_save_stacks(t_stacks *global,char **argv)
{
        global->stack1 = create_stack_a(global, argv);
        global->stack2 = create_stack_b(global, argv);
}

char **create_stack_a(t_stacks *global,char **argv)
{
    char **str;
    int i;
    
    i = 1;
    str = (char **)malloc(sizeof(char *) * global->total);
    if (!str)
        return (NULL);
    while(argv[i]){
        str[i - 1] = argv[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char **create_stack_b(t_stacks *global,char **argv)
{
    char **str;
    int i;
    
    str = (char **)malloc(sizeof(char *) * 1);
    str[0] = '\0';
    return (str);
}