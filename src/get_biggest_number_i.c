/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_biggest_number_i.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 03:03:17 by amantara          #+#    #+#             */
/*   Updated: 2022/04/16 03:41:37 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_biggest_number_i(t_number_list *lst)
{
	int				i;
	int				aux;
	int				nbr_max;
	t_number_list	*temp1;

	nbr_max = lst->nbr;
	temp1 = lst;
	i = 0;
	aux = 0;
	while (temp1)
	{
		if (temp1->nbr > nbr_max)
		{
			nbr_max = temp1->nbr;
			aux = i;
		}
	temp1 = temp1->next;
	i++;
	}
	return (aux);
}
