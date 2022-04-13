/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:35:33 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/13 00:37:15 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void create_list_argv(int argc, char **str, t_stacks *stack)
{
	int				i;
	t_number_list	*number;

	i = 1;
	while (i <= argc){
		check_numbers(str[i]);
		number = malloc(sizeof(t_number_list));
		ft_lstadd_back(&stack->a, number);
		stack->nbr_of_element++;
		number->nbr = ft_atoi(str[i], &stack->a);
		verify_number_duplicate(ft_atoi(str[i], &stack->a),
			&stack->a);
		i++;
	}
}


void save_numbers_on_stack(int argc, char **argv, t_stacks *stack){
	if (argc == 0){
		show_error_msg("Numeros introducidos 0");
	} else if (argc == 1) {
		create_list_str(argv[1], stack);
	} else 
		create_list_argv(argc, argv, stack);

}

int	main(int argc, char **argv)
{
	t_stacks	stack;
	
	ft_memset(&stack, 0, sizeof(stack));
	save_numbers_on_stack(argc - 1, argv, &stack);
	
}