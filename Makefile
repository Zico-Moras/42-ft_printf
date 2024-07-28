# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francima <francima@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 18:30:39 by francima          #+#    #+#              #
#    Updated: 2024/07/23 22:39:38 by francima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ./libft/libft.a
LIBFTDIR = ./libft

SRC = ./files

PRINTF_SRCS = ft_printf.c ft_put_func.c ft_hex.c

OBJS = $(PRINTF_SRCS:.c=.o)

CC = cc
AR = ar rcs
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
CP = cp

all:	$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
	$(CP) $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)

$(LIBFT):	$(LIBFTDIR)
		@$(MAKE) -C $(LIBFTDIR)

%.o:	$(SRC)/%.c
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@$(RM) $(OBJS)

fclean:	clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	@$(RM) $(NAME)

re:	fclean all

main: 
	cc -Wall -Werror -Wextra test.c -L. libftprintf.a
	./a.out

.PHONY:	all clean fclean re
