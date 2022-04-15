/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:58:56 by amantara          #+#    #+#             */
/*   Updated: 2022/04/15 12:01:03 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_number_list
{
	int						nbr;
	struct s_number_list	*next;
}				t_number_list;

typedef struct s_stacks
{
	int						nbr_of_element;
	struct s_number_list	*a;
	struct s_number_list	*b;
}				t_stacks;

void	show_error_msg(char *str);
void	create_list_argv(int argc, char **str, t_stacks *stack);
void	save_numbers_on_stack(int argc, char **argv, t_stacks *stack);
int		ft_mirartodobien(t_number_list *lst);
int		main(int argc, char **argv);
void	validate_duplicates(char *number, char **argv);
void	validate_arguments(char *str);
void	ft_lstadd_back_number_list(t_number_list **last, t_number_list *new);
int		is_sorted(t_stacks *stack);
void	create_list_argv_splitted(char **str, t_stacks *stack);

// Actions
void	action_ss(t_stacks *stacks);
void	action_sb(t_stacks *stacks);
void	action_sa(t_stacks *stacks);
void	action_rra(t_stacks *stacks);
void	action_rrb(t_stacks *stacks);
void	action_rrr(t_stacks *stacks);
void	action_pa(t_stacks *stacks);
void	action_pb(t_stacks *stacks);
void	action_ra(t_stacks *stacks);
void	action_rb(t_stacks *stacks);
void	action_rr(t_stacks *stacks);

#endif