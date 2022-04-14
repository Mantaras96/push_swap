/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:57:47 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/14 00:17:22 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


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

void	ft_lstadd_back_number_list(t_number_list **alst, t_number_list *new)
{
	t_number_list	*s;

	if (!new || !alst)
		return ;
	s = *alst;
	new->next = 0;
	if (!s)
	{
		*alst = new;
		return ;
	}
	while (s->next)
		s = s->next;
	s->next = new;
}