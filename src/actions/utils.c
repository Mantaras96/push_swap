/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:11:39 by amantara          #+#    #+#             */
/*   Updated: 2022/04/22 20:34:16 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void    add_value_end(t_rules *frame, int num)
{
    t_stack **top;
    t_stack *tmp;

    top = &frame->a;
    if(*top)
    {
        write(1, "Y", 1);
        tmp = (t_stack *)malloc(sizeof(t_stack));
        tmp->next = *top;
        tmp->prev = (*top)->prev;
        (*top)->prev = tmp;
        tmp->prev->next = tmp;
        tmp->nbr = num;
    }
    else
    {
        write(1, "Q", 1);
        *top = (t_stack *)malloc(sizeof(t_stack));
        (*top)->next = *top;
        (*top)->prev = *top;
        (*top)->nbr = num;
    }
}