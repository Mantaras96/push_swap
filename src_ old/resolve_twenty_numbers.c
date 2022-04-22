/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_twenty_numbers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:32:45 by amantara          #+#    #+#             */
/*   Updated: 2022/04/16 03:40:07 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_fourth_big_number(t_number_list *lst, int size)
{
	int				fourth_big;
	int				i;
	t_number_list	*temp1;
	t_number_list	*temp2;

	if (!lst)
		return (0);
	temp1 = lst;
	while (temp1)
	{
		i = 0;
		fourth_big = temp1->nbr;
		temp2 = lst;
		while (temp2)
		{
			temp1->nbr > temp2->nbr && i++;
			temp2 = temp2->next;
		}
		if (i == size - 4)
			break ;
		temp1 = temp1->next;
	}
	return (fourth_big);
}

int	less_equal_fourth_number(int number, t_number_list *lst)
{
	while (lst)
	{
		if (lst->nbr <= number)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	send_number_stack_b(int size, int index, t_stacks *stack)
{
	if (index <= size / 2)
	{
		while (index)
		{
			action_ra(stack, 1);
			index--;
		}	
	}
	else
	{
		while (size - index)
		{
			action_rra(stack, 1);
			index++;
		}
	}
	action_pb(stack);
}

void	choose_send_nbr(int fourth_number, int size, t_stacks *stack)
{
	int				i;
	int				nbr_to_send;
	t_number_list	*temp1;

	i = 0;
	temp1 = stack->a;
	while (temp1 && i < size && ++i)
	{
		if (temp1->nbr <= fourth_number && i--)
		{
			nbr_to_send = i;
			break ;
		}
		temp1 = temp1->next;
	}
	while (temp1 && i < size / 2 && ++i)
		temp1 = temp1->next;
	while (temp1)
	{
		if (temp1->nbr <= fourth_number && nbr_to_send > size - i)
			nbr_to_send = i;
		i++;
		temp1 = temp1->next;
	}
	send_number_stack_b(size, nbr_to_send, stack);
}

void	order_twenty_numbers(t_stacks *stacks)
{
	int	size;
	int	fourth_big_number;

	size = ft_stacklen(stacks->a);
	fourth_big_number = find_fourth_big_number(stacks->a, size);
	while (less_equal_fourth_number(fourth_big_number, stacks->a))
	{
		size = ft_stacklen(stacks->a);
		choose_send_nbr(fourth_big_number, size, stacks);
	}
}
