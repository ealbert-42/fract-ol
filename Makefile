# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ealbert <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/20 15:54:21 by ealbert           #+#    #+#              #
#    Updated: 2016/11/20 15:12:43 by ealbert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: re all clean fclean

SRC = src/main.c	\
	  src/parser.c

NAME = fractol

INCLUDES = -I includes -framework OpenGl -framework AppKit -lmlx

FLAGS = -Wall -Wextra -Werror

$(NAME) :
	@make re -C libft/
	@make re -C minilibx_macos/
	@gcc $(FLAGS) -o $(NAME) $(INCLUDES) $(SRC) minilibx_macos/libmlx.a \
	libft/libft.a

all : $(NAME)

clean :
	@make clean -C minilibx_macos/
	@make fclean -C libft/

fclean : clean
	@rm -f $(NAME)

re : fclean all
