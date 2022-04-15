/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:35:33 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/15 09:56:23 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	save_numbers_on_stack(int argc, char **argv, t_stacks *stack)
{
	if (argc == 0)
		show_error_msg("Numeros introducidos 0");
	else
		create_list_argv(argc, argv, stack);
}

int	ft_mirartodobien(t_number_list *lst)
{
	size_t	count;

	count = 0;
	while (lst)
	{
		ft_putnbr_fd(lst->nbr, 1);
		lst = lst->next;
		count++;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	t_stacks	stack;

	ft_memset(&stack, 0, sizeof(stack));
	save_numbers_on_stack(argc - 1, argv, &stack);
	ft_mirartodobien(stack.a);
	if (!is_sorted(&stack))
		sort_stack_chunks(&stack);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_stacks	stack;
// 	ft_memset(&stack, 0, sizeof(stack));
// 	save_numbers_on_stack(argc - 1, argv, &stack);
//	action
// 	ft_mirartodobien(stack.a);
// 	sort_stack_a_chunks(&stacks);
// 	return (0);	
// }