# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amantara <amantara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 19:02:21 by albertmanta       #+#    #+#              #
#    Updated: 2022/04/24 14:35:17 by amantara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRC	=	main.c \
		error.c \
		start_obj.c \
		is_sorted.c \
		create_list_value.c \
		actions/action_pa.c \
		actions/action_ra.c \
		actions/action_rra.c \
		actions/action_sa.c \
		actions/utils.c \
		actions/utils_biggest_smallest.c \
		resolve/solve_numbers.c \
		resolve/resolve_three_numbers.c \
		resolve/resolve_four_five_numbers.c \
		resolve/resolve_hundred.c
		

OBJ	= $(addprefix objs/,$(SRC:.c=.o))

CC	=	gcc
CFLAGS	= -Wall -Wextra -Werror

objs/%.o:src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) -o $@ $^

all:	$(NAME)

$(NAME): $(OBJ) include/push_swap.h
	@make -C libft
	@$(CC) $(OBJ) libft/libft.a -o $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf ./objs

fclean:	clean
	@make fclean -C libft
	@rm -f $(NAME)

re:	fclean all

.PHONY: all re clean fclean
