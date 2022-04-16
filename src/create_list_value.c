/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 10:10:50 by amantara          #+#    #+#             */
/*   Updated: 2022/04/15 23:12:33 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	create_list_argv_splitted(char **str, t_stacks *stack)
{
	int				i;
	t_number_list	*number;

	i = 0;
	while (str[i])
	{
		validate_arguments(str[i]);
		validate_duplicates(str[i], str);
		number = malloc(sizeof(t_number_list));
		ft_lstadd_back_number_list(&stack->a, number);
		stack->nbr_of_element++;
		number->nbr = ft_atoi(str[i]);
		i++;
	}
}

void	save_numbers_on_stack(int argc, char **argv, t_stacks *stack)
{
	if (argc == 0)
		show_error_msg("Numeros introducidos 0");
	else if (argc == 1)
		create_list_argv_splitted(ft_split(argv[1], 32), stack);
	else
		create_list_argv(argc, argv, stack);
}

void	create_list_argv(int argc, char **str, t_stacks *stack)
{
	int				i;
	t_number_list	*number;

	i = 1;
	while (i <= argc)
	{
		validate_arguments(str[i]);
		validate_duplicates(str[i], str);
		number = malloc(sizeof(t_number_list));
		ft_lstadd_back_number_list(&stack->a, number);
		stack->nbr_of_element++;
		number->nbr = ft_atoi(str[i]);
		i++;
	}
}
