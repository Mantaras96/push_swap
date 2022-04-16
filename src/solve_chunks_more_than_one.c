/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_chunks_more_than_one.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:11:31 by amantara          #+#    #+#             */
/*   Updated: 2022/04/16 12:27:06 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

find_lower_nubr(int chunks, t_number_list *lst)
{
	int i;
	int lower_nubr;
	t_number_list *temp1;

	i = 0;
	temp1 = lst;
	lower_nubr = lst->nbr;
	while(temp1)
	{
		temp1 = temp1->next;
	}
	
}