/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:35:33 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/11 23:42:41 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	global;

	if (argc <= 1)
		show_error_msg("Numero de parametros incorrecto");
	global.total = (argc - 1);
	validate_argv_arguments(argv);
	create_and_save_stacks(&global, argv);
	start_resolve(&global);
	return (0);
}

void	validate_argv_arguments(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		validate_arguments(argv[i]);
		validate_duplicates(argv[i], argv);
		i++;
	}
}

// Validar que todos los valores son digitos + no supera el limite de int.
void	validate_arguments(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '-')
		{
			i++;
			continue ;
		}
		if (!ft_isdigit(str[i]))
			show_error_msg("No todos los caracteres son numericos1");
		i++;
	}
}

void	validate_duplicates(char *number, char **argv)
{
	int	i;
	int	occurrences;

	i = 0;
	occurrences = 0;
	while (argv[i])
	{
		if (ft_atoi(number) == ft_atoi(argv[i]))
			occurrences++;
		if (occurrences >= 2)
			show_error_msg("No se admited valores duplicados");
		i++;
	}
}
