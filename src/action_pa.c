/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_pa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 10:46:17 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/11 23:33:52 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	action_pa(char **stacka, char **stackb)
{
	stacka = add_number_to_stack(stacka, stackb[0]);
	del_number_from_stack(stackb);
	write(1, "pa\n", 3);
}

char	**add_number_to_stack(char **stacka, char *number_add)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	while (stacka[i])
		i++;
	str = (char **)malloc(sizeof (char *) * (i + 2));
	if (!str)
		return (NULL);
	str[0] = number_add;
	i = 0;
	j = 1;
	while (stacka[i])
		str[j++] = stacka[i++];
	str[j] = "\0";
	free(stacka);
	return (str);
}

void	del_number_from_stack(char **stackb)
{
	int		i;
	char	**str;

	i = 0;
	while (stackb[i])
		i++;
	str = (char **)malloc(sizeof(char *) * i);
	if (!str)
		show_error_msg("Error de memoria");
	i = 1;
	while (stackb[i])
	{
		str[i - 1] = str[i];
		i++;
	}
}

void	action_pb(char **stacka, char **stackb)
{
	stacka = add_number_to_stack(stacka, stackb[0]);
	del_number_from_stack(stackb);
	write(1, "pb\n", 3);
}
