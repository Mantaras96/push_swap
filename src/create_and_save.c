/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_save.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:54:20 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/11 23:29:51 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	create_and_save_stacks(t_stacks *global, char **argv)
{
		global->stack1 = create_stack_a(global, argv);
		global->stack2 = create_stack_b();
}

char	**create_stack_a(t_stacks *global, char **argv)
{
	char	**str;
	int		i;

	i = 1;
	str = (char **)malloc(sizeof(char *) * global->total);
	if (!str)
		return (NULL);
	while (argv[i])
	{
		str[i - 1] = argv[i];
		i++;
	}
	str[i] = "\0";
	return (str);
}

char	**create_stack_b(void)
{
	char	**str;

	str = (char **)malloc(sizeof(char *) * 1);
	str[0] = "\0";
	return (str);
}
