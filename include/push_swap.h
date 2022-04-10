#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stacks
{
	char	**stack1;
	int		*aint;
	char	**stack2;
	int		total;
}	t_stacks;

void	show_error_msg(char *str);
void	validate_argv_arguments(char **argv);
void	validate_arguments(char *str);
void	validate_duplicates(char *number, char **argv);
int		solved(t_stacks *global);
char	**create_stack_b(t_stacks *global,char **argv);
char	**create_stack_a(t_stacks *global,char **argv);
void	create_and_save_stacks(t_stacks *global,char **argv);
void	action_ss(char **stacka, char **stackb);
void	action_sb(char **stack, int writ);
void	action_sa(char **stack, int writ);
void	action_rrr(char **stacka, char **stackb);
void	action_rrb(char **stack, int writ);
void	action_rra(char **stack, int writ);
void	action_rr(char **stacka, char **stackb);
void	action_rb(char **stack, int writ);
void	action_ra(char **stack, int writ);
void	action_pb(char **stacka, char **stackb);
void	delNumberFromStack(char **stackb);
char	**addNumberToStack(char **stacka, char *number_add);
void	action_pa(char **stacka, char **stackb);

int *create_stack_numbers(t_stacks *global);
int get_case(int *number);
void resolve_three_numbers(t_stacks *global);


#endif