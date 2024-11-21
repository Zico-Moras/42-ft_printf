# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francima <francima@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 18:30:39 by francima          #+#    #+#              #
#    Updated: 2024/07/30 00:55:49 by francima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_REPO = git@github.com:Zico-Moras/42-libft.git
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = ./42-libft

SRC = ./files

PRINTF_SRCS = ft_printf.c ft_put_func.c ft_hex.c ft_putpointer.c

OBJS = $(PRINTF_SRCS:.c=.o)

CC = cc
AR = ar rcs
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
CP = cp

all:	$(NAME)

$(LIBFT): 
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
	echo "Cloning libft repository..."; \
	git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	else \
	echo "libft already exists"; \
	fi
	@echo "Building libft"
	$(MAKE) -C $(LIBFT_DIR)

$(NAME):	$(LIBFT) $(OBJS)
	$(CP) $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)


%.o:	$(SRC)/%.c
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(RM) $(OBJS)

fclean:	clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
