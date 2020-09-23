# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlink <mlink@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/10 13:32:58 by mlink             #+#    #+#              #
#    Updated: 2020/09/23 09:15:32 by mlink            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER = checker
NAME_PUSH_SWAP = push_swap

SRC_CHECKER =	main.c steps_p.c steps_r.c steps_rr.c steps_s.c \
				print.c stack.c
SRC_PUSH_SWAP = main.c check.c print.c put_bigger_or_smaller.c \
				solve.c sort.c stacks.c steps_p.c steps_r.c \
				steps_rr.c steps_s.c find_next.c help.c \
				get_next.c


SRC_CHECKER_DIR = src_checker
OBJ_CHECKER_DIR = obj_checker
SRCC = $(addprefix $(SRC_CHECKER_DIR)/, $(SRC_CHECKER))

SRC_PUSH_SWAP_DIR = src_push_swap
OBJ_PUSH_SWAP_DIR = obj_puch_swap
SRCP = $(addprefix $(SRC_PUSH_SWAP_DIR)/, $(SRC_PUSH_SWAP))

FLAGS = -Wall -Wextra -Werror

HEADER = -I includes
LIBFT_HEADER = -I libft/includes

LIBFT = libft/libft.a

RESET = \033[0m
YELLOW = \033[0;33m
GREEN = \033[0;32m
BOLD_BLUE = \033[1;34m

all: $(NAME_CHECKER) $(NAME_PUSH_SWAP)

$(OBJ_CHECKER_DIR)/%.o: $(SRC_CHECKER_DIR)%.c
	@/bin/mkdir -p $(OBJ_CHECKER_DIR)
	@gcc $(FLAGS) -c $(LIBFT_HEADER) $(HEADER) $< -o $@

$(NAME_CHECKER): $(SRCC)
	@echo "	$(GREEN)<<$(RESET)$(YELLOW)$(NAME_CHECKER) is compiling...$(GREEN)>>$(RESET)"
	@make -C libft
	@gcc $(FLAGS) -o $@ $^ $(LIBFT_HEADER) $(HEADER) $(LIBFT)
	@echo "	$(GREEN)<<$(RESET)$(YELLOW)$(NAME_CHECKER) is ready to use$(GREEN)>>$(RESET)"

$(OBJ_PUSH_SWAP_DIR)/%.o: $(SRC_PUSH_SWAP_DIR)%.c
	@/bin/mkdir -p $(OBJ_PUSH_SWAP_DIR)
	@gcc $(FLAGS) -c $(LIBFT_HEADER) $(HEADER) $< -o $@
	
$(NAME_PUSH_SWAP):  $(SRCP)
	@echo "	$(GREEN)<<$(RESET)$(YELLOW)$(NAME_PUSH_SWAP) is compiling...$(GREEN)>>$(RESET)"
	@gcc $(FLAGS) -o $@ $^ $(LIBFT_HEADER) $(HEADER) $(LIBFT)
	@echo "	$(GREEN)<<$(RESET)$(YELLOW)$(NAME_PUSH_SWAP) is ready to use$(GREEN)>>$(RESET)"

clean:
	@/bin/rm -rf $(OBJ_CHECKER_DIR) $(OBJ_PUSH_SWAP_DIR)
	@make -C libft clean
	@echo "	$(GREEN)<<$(RESET)$(YELLOW)all $(NAME_CHECKER) .o files and all $(NAME_PUSH_SWAP) .o files are deleted$(GREEN)>>$(RESET)"

fclean:
	@/bin/rm -rf $(OBJ_CHECKER_DIR) $(OBJ_PUSH_SWAP_DIR)
	@/bin/rm -f $(NAME_CHECKER) $(NAME_PUSH_SWAP)
	@make -C libft fclean
	@echo "	$(GREEN)<<$(RESET)$(YELLOW)$(NAME_CHECKER) and $(NAME_PUSH_SWAP) deleted$(GREEN)>>$(RESET)"

re: fclean all

.PHONY: all clean fclean re