/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:35:33 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/15 12:21:16 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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