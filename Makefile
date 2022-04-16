# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amantara <amantara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 19:02:21 by albertmanta       #+#    #+#              #
#    Updated: 2022/04/16 03:21:17 by amantara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRC	=	main.c \
		validations.c \
		error.c \
		solved.c \
		create_list_value.c \
		sort_with_chunks.c \
		resolve_three_numbers.c \
		action_pa.c \
		action_ra.c \
		action_rra.c \
		action_sa.c \
		resolve_twenty_numbers.c \
		get_biggest_number_i.c \
		# create_and_save.c \
		# resolve_four_five_numbers.c \
		# resolve_three_numbers.c \
		# solved.c \
		# start_resolve.c \

OBJ	= $(addprefix objs/,$(SRC:.c=.o))

CC	=	gcc
CFLAGS	= -Wall -Wextra -Werror

objs/%.o:src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) -o $@ $^

all:	$(NAME)

$(NAME): $(OBJ)
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
