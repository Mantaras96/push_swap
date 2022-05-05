/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:58:56 by amantara          #+#    #+#             */
/*   Updated: 2022/05/05 23:48:39 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	long int		nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct s_rules
{
	struct s_stack	*a;
	struct s_stack	*b;

	char			**argv;
	int				argc;
	char			*line;
	char			*str;

	int				print_stacks;
	int				stack_len;
	long			quarter;
	long			median;
	long			three_quarters;
}					t_rules;

typedef struct s_extreme
{
	long	biggest;
	int		big_rotate;
	int		big_rrotate;
	int		big_flag;

	long	smallest;
	int		smallest_rotate;
	int		smallest_rrotate;
	int		smallest_flag;
	int		after_rotate;
}				t_extreme;

// Actions
int			action_ss(t_rules *stacks);
int			action_sb(t_rules *stacks, int i);
int			action_sa(t_rules *stacks, int i);
int			action_rra(t_rules *stacks, int i);
int			action_rrb(t_rules *stacks, int i);
int			action_rrr(t_rules *stacks);
int			action_pa(t_rules *stacks);
int			action_pb(t_rules *stacks);
int			action_ra(t_rules *stacks, int i);
int			action_rb(t_rules *stacks, int i);
int			action_rr(t_rules *stacks);
//Mostrar mensaje de error. (error.c)
void		show_error_msg(char *str);
void		show_error_and_free(char *str, t_rules *rules, t_extreme *extreme);
//Check if sorted (is_sorted.c)
int			is_sorted(t_rules *stack);
//Start structs (start_obj.c)
t_extreme	*start_obj_extreme(t_extreme *extreme);
t_rules		*start_obj_rules(t_rules *frame, char **argv);
void		reset_obj_extreme(t_extreme *extreme);
//Save values on struct (create_list_value.c)
void		create_list_argv_splitted(char **str, t_rules *stack);
void		create_list_argv(int argc, char **str, t_rules *stack);
void		save_numbers_on_stack(int argc, char **argv, t_rules *stack);
//Some utils can be fine (utils.c)
void		add_value_end(t_rules *frame, int num);
void		find_median(t_rules *rules, t_stack *stack, t_extreme *extreme);
void		push_median_to_b(t_rules *rules, t_extreme *extreme, int split);
int			moves_rotate(t_rules *rules, int element);
int			moves_rrotate(t_rules *rules, int element);
void		moves_biggest(t_rules *rules, t_extreme *extreme);
void		moves_smallest(t_rules *rules, t_extreme *extreme);
void		set_rotate_flag(t_extreme *extreme);
void		find_movements(t_rules *rules, t_extreme *extreme);
//Some utils biggest smallest (utils_biggest_smallest.c)
void		find_biggest_a(t_rules *rules, t_extreme *extreme);
void		find_smallest_a(t_rules *rules, t_extreme *extreme);
void		find_biggest_b(t_rules *rules, t_extreme *extreme);
void		find_smallest_b(t_rules *rules, t_extreme *extreme);
//Start solver (solve_numbers.c)
void		solve_numbers(t_rules *rules, t_extreme *extreme);
void		order_two_three_numbers(t_rules *stacks);
void		resolve_three_numbers(t_rules *stacks);
//Resolve when send 4 or 5 numbers
void		resolve_4_or_5(t_rules *rules, t_extreme *extreme);
void		resolve_four(t_rules *rules, t_extreme *extreme);
//Resolve 5 - 99 numbers (resolve_hundred.c)
void		resolve_hundred(t_rules *rules, t_extreme *extreme);
void		push_big_or_small_hundred(t_rules *rules, t_stack *stack,
				t_stack *stack_end, t_extreme *extreme);
void		rotate_and_push_to_a_hundred(t_rules *rules, t_extreme *extreme);
void		push_first(t_rules *rules);
void		push_second(t_rules *rules);
void		push_three(t_rules *rules);
void		push_quarts(t_rules *rules);
//Resolve 100 - XXX numbers (resolve_more_hundred.c)
void		resolve_more_hundred(t_rules *r, t_extreme *e);
//Validate arguments (validations.c)
void		validate_duplicates(char *number, char **argv);
void		validate_arguments(char *str);

#endif