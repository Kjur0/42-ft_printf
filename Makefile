# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/30 17:19:04 by kjurkows          #+#    #+#              #
#    Updated: 2026/06/30 18:57:27 by kjurkows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a

SRCS_DIR	=	srcs
SRCS		=	ft_printf.c \
				ft_printf_utils1.c \
				ft_printf_utils2.c \

OBJS_DIR	=	objs
OBJS		=	$(SRCS:%.c=$(OBJS_DIR)/%.o)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I$(LIBFT_DIR) -Iincludes
LIBFT_FLAGS	=	-L$(LIBFT_DIR) -lft
AR			=	ar rcs
RM			=	rm -rf

RED			=	\033[;31m
GREEN		=	\033[;32m
YELLOW		=	\033[;33m
BLUE		=	\033[;34m
MAGENTA		=	\033[;35m
CYAN		=	\033[;36m
RESET		=	\033[0m
POSITION	=	\033[2K\r

MAKEFLAGS += --no-print-directory

all: $(NAME)
	@echo "$(GREEN)$(NAME) is ready to use.$(RESET)"

$(NAME): $(OBJS)
	@echo -n "$(BLUE)Creating $(NAME)...$(RESET)"
	@$(AR) $@ $^
	@echo "$(POSITION)$(GREEN)$(NAME) has been created successfully!$(RESET)"

$(LIBFT):
	@echo -n "$(BLUE)Initializing and updating libft submodule...$(RESET)"
	@git submodule update --init --recursive > /dev/null
	@echo "$(POSITION)$(GREEN)Libft submodule is ready!$(RESET)"
	@echo -n "$(BLUE)Compiling libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	@echo "$(POSITION)$(GREEN)Libft has been compiled successfully!$(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR) $(LIBFT)
	@echo -n "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(LIBFT_FLAGS)
	@echo "$(POSITION)$(GREEN)Compiled $(basename $(notdir $<)) successfully!$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "$(CYAN)Created objects directory.$(RESET)"

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null
	@$(RM) $(OBJS_DIR)
	@echo "$(RED)Cleaned object files.$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null
	@$(RM) $(NAME)
	@echo "$(RED)Fully cleaned all generated files.$(RESET)"


re: fclean all
	@echo "$(GREEN)Rebuild complete!$(RESET)"

.PHONY: all clean fclean re
