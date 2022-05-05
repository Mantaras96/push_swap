/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:03:29 by amantara          #+#    #+#             */
/*   Updated: 2022/05/05 23:48:08 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	if (!is_sorted(rules))
		solve_numbers(rules, extreme);
	show_error_and_free("Fin", rules, extreme);
	return (0);
}
