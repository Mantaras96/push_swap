/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 10:10:50 by amantara          #+#    #+#             */
/*   Updated: 2022/05/05 20:00:55 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	create_list_argv_splitted(char **str, t_rules *stack)
{
	int				i;

	i = 0;
	while (str[i])
	{
		validate_arguments(str[i]);
		validate_duplicates(str[i], str);
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
		validate_arguments(str[i]);
		validate_duplicates(str[i], str);
		add_value_end(stack, ft_atoi(str[i]));
		i++;
	}
	stack->argc = i - 1;
}
