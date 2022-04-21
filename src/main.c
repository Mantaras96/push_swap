/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:35:33 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/18 16:43:08 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//TODO: Delete function at end.
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
	action_ra(&stack, 0);
	write(1, " ", 1);
	ft_mirartodobien(stack.a);
	// if (!is_sorted(&stack))
	// 	sort_stack_chunks(&stack);
	return (0);
}
