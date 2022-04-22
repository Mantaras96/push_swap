/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_chunks_more_than_one.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:11:31 by amantara          #+#    #+#             */
/*   Updated: 2022/04/18 13:11:38 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


int	find_number(int chunks, t_number_list *lst, int size)
{
	int				number;
	int				i;
	t_number_list	*temp1;
	t_number_list	*temp2;

	temp1 = lst;
	temp2 = lst;
	while (temp1)
	{
		number = temp1->nbr;
		i = 0;
		while (temp2)
		{
			if (temp2->nbr < number)
				i++;
			temp2 = temp2->next;
		}
		if (i == size / chunks)
			break ;
		temp1 = temp1->next;
		temp2 = lst;
	}
	return (number);
}

int	count_numbers_less_or_equal(int number, t_number_list *lst)
{
	t_number_list	*temp1;
	int				count;

	temp1 = lst;
	count = 0;
	while (temp1)
	{
		if (temp1->nbr <= number)
			count++;
		temp1 = temp1->next;
	}
	return (count);
}

void	find_number_and_send(t_stacks *stacks, int base_number, int size)
{
	int				index;
	int				index_to_send;
	t_number_list	*temp1;

	index = 0;
	temp1 = stacks->a;
	while (temp1 && ++index)
	{
		if (temp1->nbr <= base_number && index--)
		{
			index_to_send = index;
			break ;
		}
	}
	while (temp1 && index < size / 2 && ++index)
		temp1 = temp1->next;
	while (temp1)
	{
		if (temp1->nbr <= base_number && index_to_send > size - index)
			index_to_send = index;
		index++;
		temp1 = temp1->next;
	}
	send_number_stack_b(size, index_to_send, stacks);
}

void	send_under_base_to_b(int base_number, t_stacks *stacks)
{
	int	numbers_less;
	int	size;

	numbers_less = count_numbers_less_or_equal(base_number, stacks->a);
	if (numbers_less)
	{
		size = ft_stacklen(stacks->a);
		find_number_and_send(stacks, base_number, size);
		numbers_less--;
	}	
}
