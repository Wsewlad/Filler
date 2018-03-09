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
VISUAL	=	visualizer.c vis_parser.c vis_printer.c vis_parser2.c vis_printer2.c
FLAGS	=	-Wall -Werror -Wextra
MYLIB	=	-L libft -lftprintf -I libft
MLX		=	-I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(SRC) $(VISUAL)
	make -C libft/
	gcc -o $(NAME) $(FLAG) $(SRC) $(MYLIB)
	@printf "\e[94mFiller is compiled!\n\e[0m"
	@say "Filler is compiled!"
	gcc -o visualizer $(FLAG) $(VISUAL) $(MYLIB) $(MLX)

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
