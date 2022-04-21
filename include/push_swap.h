/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:58:56 by amantara          #+#    #+#             */
/*   Updated: 2022/04/18 13:11:34 by amantara         ###   ########.fr       */
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
int		action_ss(t_stacks *stacks);
int		action_sb(t_stacks *stacks, int i);
int		action_sa(t_stacks *stacks, int i);
int		action_rra(t_stacks *stacks, int i);
int		action_rrb(t_stacks *stacks, int i);
int		action_rrr(t_stacks *stacks);
int		action_pa(t_stacks *stacks);
int		action_pb(t_stacks *stacks);
int		action_ra(t_stacks *stacks, int i);
int		action_rb(t_stacks *stacks, int i);
int		action_rr(t_stacks *stacks);

//Order
void	sort_stack_chunks(t_stacks *stacks);
int		calcule_chunks(t_stacks *stacks);
void	order_two_three_numbers(t_stacks *stacks);
void	order_twenty_numbers(t_stacks *stacks);
int		find_fourth_big_number(t_number_list *lst, int size);
int		ft_stacklen(t_number_list *lst);
int		get_biggest_number_i(t_number_list *lst);

void	send_under_base_to_b(int base_number, t_stacks *stacks);
void	find_number_and_send(t_stacks *stacks, int base_number, int size);
int		count_numbers_less_or_equal(int number, t_number_list *lst);
int		find_number(int chunks, t_number_list *lst, int size);

void	send_number_stack_b(int size, int index, t_stacks *stack);
#endif