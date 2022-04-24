/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:36:25 by amantara          #+#    #+#             */
/*   Updated: 2022/04/24 10:52:54 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_rules	*start_obj_rules(t_rules *frame, char **argv)
{
	frame = (t_rules *)malloc(sizeof(t_rules));
	frame->a = NULL;
	frame->b = NULL;
	frame->argv = argv;
	frame->argc = 0;
	frame->line = NULL;
	frame->str = NULL;
	frame->print_stacks = 0;
	frame->stack_len = 0;
	frame->quarter = 0;
	frame->median = 0;
	frame->three_quarters = 0;
	return (frame);
}

t_extreme	*start_obj_extreme(t_extreme *extreme)
{
	extreme = (t_extreme *)malloc(sizeof(t_extreme));
	extreme->biggest = 0;
	extreme->big_rotate = 0;
	extreme->big_rrotate = 0;
	extreme->big_flag = 0;
	extreme->smallest = 0;
	extreme->smallest_rotate = 0;
	extreme->smallest_rrotate = 0;
	extreme->smallest_flag = 0;
	extreme->after_rotate = 0;
	return (extreme);
}

void reset_obj_extreme(t_extreme *extreme)
{
	extreme->biggest = 0;
	extreme->big_rotate = 0;
	extreme->big_rrotate = 0;
	extreme->big_flag = 0;
	extreme->smallest = 0;
	extreme->smallest_rotate = 0;
	extreme->smallest_rrotate = 0;
	extreme->smallest_flag = 0;
}
