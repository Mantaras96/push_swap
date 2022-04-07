/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:40:52 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/07 23:58:58 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void operation_sa(char **stack){
    char  *temp;

    temp = stack[0];
    stack[0] = stack[1];
    stack[1] = temp;
    write(1, "sa\n", 3);
}