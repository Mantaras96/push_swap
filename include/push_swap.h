/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:58:56 by amantara          #+#    #+#             */
/*   Updated: 2022/04/15 10:00:32 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

//V1 de mi stack
// typedef struct s_stacks
// {
// 	char	**stack1;
// 	int		*aint;
// 	char	**stack2;
// 	int		total;
// }	t_stacks;

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

// void	validate_argv_arguments(char **argv);
// void	validate_arguments(char *str);
// void	validate_duplicates(char *number, char **argv);
// int		solved(t_stacks *global);
// char	**create_stack_b();
// char	**create_stack_a(t_stacks *global,char **argv);
// void	create_and_save_stacks(t_stacks *global,char **argv);
// void	action_ss(t_stacks *stacks);
// void	action_sb(t_stacks *stacks);
// void	action_sa(t_stacks *stacks);
// void	action_rrr(char **stacka, char **stackb);
// void	action_rrb(char **stack, int writ);
// void	action_rra(char **stack, int writ);
// void	action_rr(char **stacka, char **stackb);
// void	action_rb(char **stack, int writ);
// void	action_ra(char **stack, int writ);
// void	action_pa(t_stacks *stacks);
// void	del_number_from_stack(char **stackb);
// char	**add_number_to_stack(char **stacka, char *number_add);
// void	action_pb(t_stacks *stacks);

// int		*create_stack_numbers(t_stacks *global);
// int		get_case(int *number);
// void 	resolve_three_numbers(t_stacks *global);
// void    resolve_four_five_numbers(t_stacks *global);
// void    start_resolve(t_stacks *global);

void	show_error_msg(char *str);
void	create_list_argv(int argc, char **str, t_stacks *stack);
void	save_numbers_on_stack(int argc, char **argv, t_stacks *stack);
int		ft_mirartodobien(t_number_list *lst);
int		main(int argc, char **argv);
void	validate_duplicates(char *number, char **argv);
void	validate_arguments(char *str);
void	ft_lstadd_back_number_list(t_number_list **last, t_number_list *new);
int		is_sorted(t_stacks *stack);

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