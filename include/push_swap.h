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

void operation_sa(char **stack);
void show_error_msg(char *str);

#endif