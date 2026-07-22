# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/30 17:19:04 by kjurkows          #+#    #+#              #
#    Updated: 2026/07/22 17:04:56 by kjurkows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

LIBFT_DIR	=	libft
LIBFT_MAKE	=	$(LIBFT_DIR)/Makefile
LIBFT_H		=	$(LIBFT_DIR)/libft.h
LIBFT		=	$(LIBFT_DIR)/libft.a

SRCS_DIR	=	srcs
SRCS		=	ft_printf.c \
				ft_printf_utils1.c \
				ft_printf_utils2.c

BONUS_SRCS	=	ft_printf_bonus.c \
				ft_printf_flags_bonus.c \
				ft_printf_utils_bonus.c \
				ft_printf_c_bonus.c \
				ft_printf_s_bonus.c \
				ft_printf_p_bonus.c \
				ft_printf_di_bonus.c \
				ft_printf_u_bonus.c \
				ft_printf_x_bonus.c

OBJS_DIR	=	objs
OBJS		=	$(SRCS:%.c=$(OBJS_DIR)/%.o)
BONUS_OBJS	=	$(BONUS_SRCS:%.c=$(OBJS_DIR)/bonus/%.o)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I$(LIBFT_DIR) -Iincludes -fPIC
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

$(NAME): $(OBJS) $(LIBFT)
	@echo -n "$(BLUE)Creating $(NAME)...$(RESET) "
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(POSITION)$(GREEN)$(NAME) has been created successfully!$(RESET)"

bonus: $(BONUS_OBJS) $(LIBFT)
	@echo -n "$(BLUE)Creating $(NAME) with bonus...$(RESET) "
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(BONUS_OBJS)
	@echo "$(POSITION)$(GREEN)$(NAME) with bonus has been created successfully!$(RESET)"

$(LIBFT): $(LIBFT_MAKE)
	@echo -n "$(BLUE)Compiling libft...$(RESET) "
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	@echo "$(POSITION)$(GREEN)Libft has been compiled successfully!$(RESET)"

$(LIBFT_H): $(LIBFT_MAKE)

$(LIBFT_MAKE):
	@echo -n "$(BLUE)Initializing and updating libft submodule...$(RESET) "
	@git submodule update --init --recursive > /dev/null 2> /dev/null
	@echo "$(POSITION)$(GREEN)Libft submodule is ready!$(RESET)"

$(OBJS_DIR)/bonus/%.o: $(SRCS_DIR)/bonus/%.c $(LIBFT_H) | $(OBJS_DIR)
	@echo -n "$(YELLOW)Compiling $(basename $(notdir $<))...$(RESET) "
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(POSITION)$(GREEN)Compiled $(basename $(notdir $<)) successfully!$(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(LIBFT_H) | $(OBJS_DIR)
	@echo -n "$(YELLOW)Compiling $(basename $(notdir $<))...$(RESET) "
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(POSITION)$(GREEN)Compiled $(basename $(notdir $<)) successfully!$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/bonus
	@echo "$(CYAN)Created objects directory.$(RESET)"

clean:
	@if [ -f $(LIBFT_MAKE) ]; then \
		echo -n "$(YELLOW)Cleaning libft...$(RESET) "; \
		$(MAKE) -C $(LIBFT_DIR) clean > /dev/null; \
		echo "$(POSITION)$(RED)Libft cleaned successfully!$(RESET)"; \
	fi
	@echo -n "$(YELLOW)Cleaning object files...$(RESET) "
	@$(RM) $(OBJS_DIR)
	@echo "$(POSITION)$(RED)Cleaned object files.$(RESET)"

fclean: clean
	@if [ -f $(LIBFT_MAKE) ]; then \
		echo -n "$(YELLOW)Fully cleaning libft...$(RESET) "; \
		$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null; \
		echo "$(POSITION)$(RED)Libft fully cleaned successfully!$(RESET)"; \
	fi
	@echo -n "$(YELLOW)Removing $(NAME)...$(RESET) "
	@$(RM) $(NAME)
	@echo "$(POSITION)$(RED)Fully cleaned all generated files.$(RESET)"


re: fclean all
	@echo "$(GREEN)Rebuild complete!$(RESET)"

.PHONY: all clean fclean re bonus
