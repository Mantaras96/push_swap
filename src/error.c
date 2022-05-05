/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 00:01:44 by albertmanta       #+#    #+#             */
/*   Updated: 2022/05/05 23:47:57 by albertmanta      ###   ########.fr       */
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
	if (rules)
	{
		if (rules->a)
			free_stack_numbers(rules->a);
		if (rules->b)
			free_stack_numbers(rules->b);
		if (rules->line)
			free(rules->line);
		if (rules->argv)
			free(rules->argv);
		free(rules);
	}
	if (extreme)
		free (extreme);
	exit (0);
}
