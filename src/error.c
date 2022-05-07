/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 00:01:44 by albertmanta       #+#    #+#             */
/*   Updated: 2022/05/07 17:43:39 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	show_error_msg(char *str)
{
	ft_putstr_fd(str, 1);
}

void	free_stack_numbers(t_stack *stack)
{	
	t_stack	*next;
	t_stack	*delete;

	if (stack)
	{
		next = stack->next;
		while (next != stack)
		{
			delete = next;
			next = next->next;
			free(delete);
		}
		free(next);
	}
}

void	show_error_and_free(char *str, t_rules *rules, t_extreme *extreme)
{
	(void) str;
	(void) rules;
	(void) extreme;
	if (rules)
	{
		if (rules->a)
			free_stack_numbers(rules->a);
		if (rules->b)
			free_stack_numbers(rules->b);
		free(rules);
	}
	if (extreme)
		free (extreme);
}

void	free_matrix(char **str, int i)
{
	int	x;

	x = 0;
	while (x < i)
	{
		free(str[x]);
		x++;
	}
	free (str);
}
