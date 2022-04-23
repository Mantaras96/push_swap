/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:11:39 by amantara          #+#    #+#             */
/*   Updated: 2022/04/23 20:27:01 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	add_value_end(t_rules *frame, int num)
{
	t_stack	**top;
	t_stack	*tmp;

	top = &frame->a;
	if (*top)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		tmp->next = *top;
		tmp->prev = (*top)->prev;
		(*top)->prev = tmp;
		tmp->prev->next = tmp;
		tmp->nbr = num;
	}
	else
	{
		*top = (t_stack *)malloc(sizeof(t_stack));
		(*top)->next = *top;
		(*top)->prev = *top;
		(*top)->nbr = num;
	}
}

void	sort_array(long *array, int len)
{
	long	tmp;
	int		i;

	tmp = 0;
	i = 0;
	while (i < len - 1)
	{
		if (array[i] <= array[i + 1])
			i++;
		else
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}	
}

void	find_median(t_rules *rules, t_stack *stack, t_extreme *extreme)
{
	long	*array;
	int		i;
	int		quarter_len;

	(void) extreme;
	array = (long *)malloc(sizeof(long) * (rules->argc + 1));
	quarter_len = (rules->argc / 4);
	i = 0;
	while (i < rules->argc)
	{
		array[i++] = stack->nbr;
		stack = stack->next;
	}
	sort_array(array, rules->argc);
	rules->quarter = array[quarter_len];
	rules->median = array[quarter_len * 2];
	rules->three_quarters = array[quarter_len * 3];
	ft_putnbr_fd(rules->quarter, 1);
	ft_putnbr_fd(rules->median, 1);
	ft_putnbr_fd(rules->three_quarters, 1);
	free(array);
}
