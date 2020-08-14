# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlink <mlink@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/10 13:32:58 by mlink             #+#    #+#              #
#    Updated: 2020/08/12 15:20:38 by mlink            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHEKER = checker
NAME_PUSH_SWAP = push_swap

SRC_CHEKER = main.c steps_p.c steps_r.c steps_rr.c steps_s.c
SRC_PUSH_SWAP = main.c 

SRC_CHECHER_DIR = src_checker/
OBJ_CHEKER_DIR = obj_checker
SRCC = $(addprefix $(SRC_CHECHER_DIR), $(SRC_CHEKER))

SRC_PUSH_SWAP_DIR = src_push_swap/
OBJ_PUSH_SWAP_DIR = obj_puch_swap
SRCP = $(addprefix $(SRC_PUSH_SWAP_DIR), $(SRC_PUSH_SWAP))

FLAGS = -Wall -Wextra -Werror

HEADER = -I ./includes/
LIBFT_HEADER = -I ./libft/includes/

LIBFT = libft/libft.a

RESET = \033[0m
YELLOW = \033[0;33m
GREEN = \033[0;32m
BOLD_BLUE = \033[1;34m

all: $(NAME_CHEKER) $(NAME_PUSH_SWAP)

$(OBJ_CHEKER_DIR)/%.o: $(SRC_CHECHER_DIR)/%.c
	@/bin/mkdir -p $(OBJ_CHEKER_DIR)
	gcc $(FLAGS) -c $(LIBFT_HEADER) $(HEADER) $< -o $@

$(NAME_CHEKER): $(SRCC)
	@echo "	$(GREEN)<<$(RESET)$(YELLOW)$(NAME_CHEKER) is compiling...$(GREEN)>>$(RESET)"
	@make -C ./libft/
	gcc $(FLAGS) -o $@ $^ $(LIBFT_HEADER) $(HEADER) $(LIBFT)
	@echo "	$(GREEN)<<$(RESET)$(YELLOW)$(NAME_CHEKER) is ready to use$(GREEN)>>$(RESET)"

$(OBJ_PUSH_SWAP_DIR)/%.o: $(SRC_PUSH_SWAP_DIR)/%.c
	/bin/mkdir -p $(OBJ_PUSH_SWAP_DIR)
	gcc $(FLAGS) -c $(LIBFT_HEADER) $(HEADER) $< -o $@
	
$(NAME_PUSH_SWAP):  $(SRCP)
	@echo "	$(GREEN)<<$(RESET)$(YELLOW)$(NAME_PUSH_SWAP) is compiling...$(GREEN)>>$(RESET)"
	@make -C ./libft/
	gcc $(FLAGS) -o $@ $^ $(LIBFT_HEADER) $(HEADER) $(LIBFT)
	@echo "	$(GREEN)<<$(RESET)$(YELLOW)$(NAME) is ready to use$(GREEN)>>$(RESET)"

clean:
	#@rm -rf $(OBJ_CHEKER_DIR) $(OBJ_PUSH_SWAP_DIR)
	@make -C libft clean
	@echo "	$(GREEN)<<$(RESET)$(YELLOW)all $(NAME_PUSH_SWAP) .o files are deleted$(GREEN)>>$(RESET)"

fclean:
	#@rm -rf $(OBJ_CHEKER_DIR) $(OBJ_PUSH_SWAP_DIR)
	#@rm -f $(NAME_CHEKER) $(NAME_PUSH_SWAP)
	@make -C libft fclean
	@echo "	$(GREEN)<<$(RESET)$(YELLOW)$(NAME_CHEKER) and $(NAME_PUSH_SWAP) deleted$(GREEN)>>$(RESET)"

re: fclean all

.PHONY: all clean fclean re