# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlink <mlink@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 12:58:54 by mlink             #+#    #+#              #
#    Updated: 2020/08/12 13:35:24 by mlink            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c \
		ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
		ft_lstmap.c ft_lstnew.c ft_lstprint.c ft_lstsize.c ft_memalloc.c \
		ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
		ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c \
		ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c ft_putstr.c \
		ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
		ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
		ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
		ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
		ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c \
		ft_strtrim.c ft_tolower.c ft_toupper.c get_next_line.c

OBJ = $(SRC:.c=.o)

S_DIR = src
O_DIR = obj

SRCS = $(addprefix $(S_DIR)/, $(SRC))
OBJS = $(addprefix $(O_DIR)/, $(OBJ))

HEADER = ./include/

FLAGS = -Wall -Wextra -Werror -c 

RESET = \033[0m
YELLOW = \033[0;33m
GREEN = \033[0;32m
BOLD_BLUE = \033[1;34m

all: $(NAME)

$(O_DIR)/%.o: $(S_DIR)/%.c
	@/bin/mkdir -p $(O_DIR)
	@gcc $(FLAGS) -I $(HEADER) $< -o $@

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "	$(GREEN)<<$(RESET)$(YELLOW)$(NAME) is ready to use$(GREEN)>>$(RESET)"

clean:
	@/bin/rm -rf $(O_DIR)
	@echo "	$(GREEN)<<$(RESET)$(YELLOW)all $(NAME) .o files are deleted$(GREEN)>>$(RESET)"

fclean:
	@/bin/rm -rf $(O_DIR)
	@/bin/rm -f $(NAME)
	@echo "	$(GREEN)<<$(RESET)$(YELLOW)$(NAME) deleted$(GREEN)>>$(RESET)"

re: 	fclean all

.PHONY: all clean fclean re
