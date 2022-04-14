# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 19:02:21 by albertmanta       #+#    #+#              #
#    Updated: 2022/04/14 00:18:02 by albertmanta      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRC	=	main.c \
		validations.c \
		error.c \
		# action_pa.c \
		# action_ra.c \
		# action_rra.c \
		# action_sa.c \
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

fclean:	clean
	@make fclean -C libft
	@rm -f $(NAME)

re:	fclean all

.PHONY: all re clean fclean
