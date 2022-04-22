/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 00:01:44 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/23 00:22:27 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	show_error_msg(char *str)
{
	ft_putstr_fd(str, 1);
	exit(0);
}

void	show_error_and_free(char *str, t_rules *rules, t_extreme *extreme)
{
	ft_putstr_fd(str, 1);
	if (rules)
	{
		if (rules->a)
			free_stack(rules->a);
		if (rules->b)
			free_stack(rules->b);
		if (rules->line)
			free(rules->line);
		if (rules->str)
			free(rules->str);
		if (rules->argv)
			free(rules->argv);
		free(rules);
	}
	if (extreme)
		free (extreme);
	exit (0);
}
