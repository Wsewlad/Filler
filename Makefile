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
SRC		=	main.c parse_map.c parse_map2.c play.c find_enemy.c
FLAGS	=	-Wall -Werror -Wextra
MYLIB	=	-L libft -lftprintf -I libft
MLX		=	-I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(SRC) visualizer.c
	make -C libft/
	gcc -o $(NAME) $(FLAG) $(SRC) $(MYLIB)
	@printf "\e[94mFiller is compiled!\n\e[0m"
	@say "Filler is compiled!"
	gcc -o visualizer $(FLAG) visualizer.c parse_map.c parse_map2.c $(MYLIB) $(MLX)

clean:
	@rm -f *.o
	@make clean -C libft/
	@printf "\e[91m*.o files have been deleted!\n\e[0m"

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re:
	make re -C libft/
	make fclean
	make all
