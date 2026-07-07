# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/30 17:19:04 by kjurkows          #+#    #+#              #
#    Updated: 2026/07/07 11:08:41 by kjurkows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

LIBFT_DIR	=	libft
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

LIBFTA_OBJS	=	ft_isalpha.o \
				ft_isdigit.o \
				ft_isalnum.o \
				ft_isascii.o \
				ft_isprint.o \
				ft_strlen.o \
				ft_memset.o \
				ft_bzero.o \
				ft_memcpy.o \
				ft_memmove.o \
				ft_strlcpy.o \
				ft_strlcat.o \
				ft_toupper.o \
				ft_tolower.o \
				ft_strchr.o \
				ft_strrchr.o \
				ft_strncmp.o \
				ft_memchr.o \
				ft_memcmp.o \
				ft_strnstr.o \
				ft_atoi.o \
				ft_calloc.o \
				ft_strdup.o \
				ft_substr.o \
				ft_strjoin.o \
				ft_strtrim.o \
				ft_split.o \
				ft_itoa.o \
				ft_strmapi.o \
				ft_striteri.o \
				ft_putchar_fd.o \
				ft_putstr_fd.o \
				ft_putendl_fd.o \
				ft_putnbr_fd.o \
				ft_lstnew.o \
				ft_lstadd_front.o \
				ft_lstsize.o \
				ft_lstlast.o \
				ft_lstadd_back.o \
				ft_lstdelone.o \
				ft_lstclear.o \
				ft_lstiter.o \
				ft_lstmap.o

OBJS_DIR	=	objs
OBJS		=	$(SRCS:%.c=$(OBJS_DIR)/%.o)
BONUS_OBJS	=	$(BONUS_SRCS:%.c=$(OBJS_DIR)/bonus/%.o)
LIBFT_OBJS	=	$(LIBFTA_OBJS:%.o=$(OBJS_DIR)/libft/%.o)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I$(LIBFT_DIR) -Iincludes -fPIC
AR			=	ar rcs
ARX			=	ar xo --output=$(OBJS_DIR)/libft
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

$(NAME): $(OBJS) $(LIBFT_OBJS)
	@echo -n "$(BLUE)Creating $(NAME)...$(RESET)"
	@$(AR) $(NAME) $^
	@echo "$(POSITION)$(GREEN)$(NAME) has been created successfully!$(RESET)"

bonus: $(BONUS_OBJS) $(LIBFT_OBJS)
	@echo -n "$(BLUE)Creating $(NAME) with bonus...$(RESET)"
	@$(AR) $(NAME) $^
	@echo "$(POSITION)$(GREEN)$(NAME) with bonus has been created successfully!$(RESET)"

$(LIBFT):
	@echo -n "$(BLUE)Initializing and updating libft submodule...$(RESET)"
	@git submodule update --init --recursive > /dev/null
	@echo "$(POSITION)$(GREEN)Libft submodule is ready!$(RESET)"
	@echo -n "$(BLUE)Compiling libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	@echo "$(POSITION)$(GREEN)Libft has been compiled successfully!$(RESET)"

$(OBJS_DIR)/libft/%.o: $(LIBFT) | $(OBJS_DIR)
	@$(ARX) $(LIBFT) $(notdir $@)
	
$(OBJS_DIR)/bonus/%.o: $(SRCS_DIR)/bonus/%.c | $(OBJS_DIR)
	@echo -n "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(POSITION)$(GREEN)Compiled $(basename $(notdir $<)) successfully!$(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@echo -n "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(POSITION)$(GREEN)Compiled $(basename $(notdir $<)) successfully!$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/libft
	@mkdir -p $(OBJS_DIR)/bonus
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

.PHONY: all clean fclean re bonus
