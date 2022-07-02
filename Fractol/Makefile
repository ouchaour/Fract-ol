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


NAME = fractol
HD = fractol.h
all : $(NAME)
$(NAME) : $(HD)
	gcc -c *.c
	gcc -Wall -Wextra -Werror -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit  *.o  -o $(NAME)
clean :
	rm -rf *.o
fclean : clean
	rm -rf $(NAME)
re : fclean all