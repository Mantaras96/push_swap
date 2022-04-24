/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:03:29 by amantara          #+#    #+#             */
/*   Updated: 2022/04/24 15:35:54 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// int	ft_mirartodobien(t_rules *rules)
// {
// 	t_stack	*lst;
// 	int		count;

// 	lst = rules->a;
// 	count = 0;
// 	while (count < rules->argc)
// 	{
// 		ft_putnbr_fd(lst->nbr, 1);
// 		lst = lst->next;
// 		count++;
// 	}
// 	ft_putstr_fd("Stack b;", 1);
// 	lst = rules->b;
// 	count = 0;
// 	return (count);
// }

	//ft_mirartodobien(rules);
int	main(int argc, char **argv)
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
	action_pb(rules);
	action_pa(rules);
	while (rules->b){
		write(1, "A", 1);
	}
	// if (!is_sorted(rules))
	// {
	// 	solve_numbers(rules, extreme);
	// }
	return (0);
}
