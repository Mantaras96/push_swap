/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:03:29 by amantara          #+#    #+#             */
/*   Updated: 2022/04/22 20:36:36 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_mirartodobien(t_rules *rules)
{
	t_stack *lst;
	int	count;

	lst = rules->a;
	count = 0;
	while (count < rules->argc - 1)
	{
		ft_putnbr_fd(lst->nbr, 1);
		lst = lst->next;
		count++;
	}
	return (count);
}

int main (int argc, char **argv)
{
	t_rules		*rules;
	t_extreme	*extreme;
	
	rules = NULL;
	extreme = NULL;
	if (argc < 2)
	{
		show_error_msg("Error numero de parametros");
	}
	rules = start_obj_rules(rules, argv);
	extreme = start_obj_extreme(extreme);
	save_numbers_on_stack(argc - 1, argv, rules);
	write(1, "x", 1);
	ft_mirartodobien(rules);
}