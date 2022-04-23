/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 10:10:50 by amantara          #+#    #+#             */
/*   Updated: 2022/04/23 10:31:36 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	create_list_argv_splitted(char **str, t_rules *stack)
{
	int				i;

	i = 0;
	while (str[i])
	{
		add_value_end(stack, ft_atoi(str[i]));
		i++;
	}
	stack->argc = i;
}

void	save_numbers_on_stack(int argc, char **argv, t_rules *stack)
{
	if (argc == 0)
		show_error_msg("Numeros introducidos 0");
	else if (argc == 1)
		create_list_argv_splitted(ft_split(argv[1], 32), stack);
	else
		create_list_argv(argc, argv, stack);
}

void	create_list_argv(int argc, char **str, t_rules *stack)
{
	int				i;

	i = 1;
	while (i <= argc)
	{
		add_value_end(stack, ft_atoi(str[i]));
		i++;
	}
	stack->argc = i - 1;
}
