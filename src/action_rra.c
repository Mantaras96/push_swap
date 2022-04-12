/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:27:37 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/11 23:37:38 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	action_rra(char **stack, int writ)
{
	int		i;
	char	*temp;

	i = 0;
	while (stack[i])
		i++;
	i--;
	temp = stack[i];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		stack[i - 1] = temp;
		i--;
	}
	stack[i] = temp;
	if (writ)
		write(1, "rra\n", 4);
}

void	action_rrb(char **stack, int writ)
{
	int		i;
	char	*temp;

	i = 0;
	while (stack[i])
		i++;
	i--;
	temp = stack[i];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		stack[i - 1] = temp;
		i--;
	}
	stack[i] = temp;
	if (writ)
		write(1, "rrb\n", 4);
}

void	action_rrr(char **stacka, char **stackb)
{
	action_rra(stacka, 0);
	action_rrb(stackb, 0);
	write(1, "rrr\n", 4);
}
