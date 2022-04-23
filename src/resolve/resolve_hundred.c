/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_hundred.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:16:28 by amantara          #+#    #+#             */
/*   Updated: 2022/04/23 20:33:49 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void    resolve_hundred(t_rules *rules, t_extreme *extreme)
{
    int split;
    
    find_median(rules, rules->a, extreme);
    while (rules->b)
    {
        while(rules->b)
        {
            find_biggest_b(rules, extreme);
            find_smallest_b(rules, extreme);
            
        }
    }
    
}