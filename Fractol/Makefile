# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-ouc <yait-ouc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 18:55:41 by yait-ouc          #+#    #+#              #
#    Updated: 2022/07/02 20:43:42 by yait-ouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC=gcc
CFLAGS=-Wall -Wextra -Werror 

NAME=fractol

SRCS=	main.c utils.c events.c \
		mandelbrot.c julia.c burningship.c
HD= fractol.h

OBJCTS=$(SRCS:%.c=%.o)

$(NAME) : $(OBJCTS) $(HD)
		CC $(CFLAGS) -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit $(OBJCTS) -o $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJCTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all