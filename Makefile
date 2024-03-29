# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/11 11:39:30 by dzborovk          #+#    #+#              #
#    Updated: 2018/09/11 11:41:13 by dzborovk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

SRC		= src/main.c    	\
		  src/exit.c    	\
		  src/init.c   		\
		  src/draw.c    	\
		  src/julia.c   	\
		  src/mandelb.c     \
		  src/burningship.c \
		  src/hook.c 		\
		  src/mouse.c 		\

OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -Wall -Werror -Wextra -L libft/ -lft -g -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME)
	rm -rf fractol.dSYM
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Create Fractol"

obj/%.o: src/%.c
	mkdir -p obj
	gcc -Wall -Wextra -Werror -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	/bin/rm -rf obj/
	make -C libft/ clean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Libprintf"

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean Libprintf"

re: fclean all

all: $(NAME)
.PHONY: clean fclean re all
