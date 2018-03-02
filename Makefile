# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/01 16:08:25 by vfil              #+#    #+#              #
#    Updated: 2018/03/01 16:08:26 by vfil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	vfil.filler
SRC		=	main.c parse_map.c parse_map2.c
FLAGS	=	-Wall -Werror -Wextra
MYLIB	=	-L libft -lftprintf -I libft

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(SRC)
	make -C libft/
	gcc -o $(NAME) $(FLAG) $(SRC) $(MYLIB)

clean:
	rm -f *.o
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all make re -C libft/
