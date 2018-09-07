# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/05 10:43:18 by tkiselev          #+#    #+#              #
#    Updated: 2018/09/07 21:01:49 by tkiselev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Werror -Wextra

CHECKER=checker
PUSH_SWAP=push_swap
RANDOMIZER=rand

SRC_DIR=./src/
INCLUDES=includes/
PUSH_SWAP_HEADER=push_swap.h
LIBFT_DIR=libft/
LIBFT=libft.a
LIBFT_HEADER=libft.h

CHECKER_SRC_NAMES=checker.c\
				  commands.c\
				  operation.c\
				  operation_functions_1.c\
				  operation_functions_2.c\
				  preparation.c\
				  output_stacks.c\
				  staff.c

PUSH_SWAP_SRC_NAMES=push_swap.c\
					commands.c\
					get_median.c\
					operation.c\
					operation_functions_1.c\
					operation_functions_2.c\
					output_stacks.c\
					patterns_1.c\
					patterns_2.c\
					preparation.c\
					sort.c\
					sort_router.c\
					staff.c\
					divide_stack.c

RANDOMIZER_SRC=$(SRC_DIR)randomizer.c

CHECKER_SRC=$(addprefix $(SRC_DIR), $(CHECKER_SRC_NAMES))
PUSH_SWAP_SRC=$(addprefix $(SRC_DIR), $(PUSH_SWAP_SRC_NAMES))

CHECKER_OBJ=$(CHECKER_SRC:%.c=%.o)
PUSH_SWAP_OBJ=$(PUSH_SWAP_SRC:%.c=%.o)

all: $(LIBFT) $(CHECKER) $(PUSH_SWAP) rand

$(CHECKER): $(CHECKER_OBJ)
	$(CC) $(CFLAGS) $(CHECKER_OBJ) -o $(CHECKER) -I $(INCLUDES) -I $(LIBFT_DIR) $(LIBFT_DIR)$(LIBFT)

$(PUSH_SWAP): $(PUSH_SWAP_OBJ)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) -o $(PUSH_SWAP) -I $(INCLUDES) -I $(LIBFT_DIR) $(LIBFT_DIR)$(LIBFT)

rand: $(RANDOMIZER_SRC:.c=.o)
	$(CC) $(CFLAGS) $(RANDOMIZER_SRC) -o $(RANDOMIZER) -I $(LIBFT_DIR) $(LIBFT_DIR)$(LIBFT)

%.o: %.c $(INCLUDES)$(PUSH_SWAP_HEADER) $(LIBFT_DIR)$(LIBFT_HEADER)
	$(CC) -c $(CFLAGS) $< -I $(INCLUDES) -I $(LIBFT_DIR) -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(CHECKER_OBJ)
	rm -f $(PUSH_SWAP_OBJ)
	rm -f $(RANDOMIZER)
	rm -f $(RANDOMIZER_SRC:.c=.o)

fclean:
	make fclean -C $(LIBFT_DIR)
	make clean
	rm -f $(CHECKER)
	rm -f $(PUSH_SWAP)

re: fclean all
