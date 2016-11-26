#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: rhabib <moongamingpp@hotmail.fr>           +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/11 19:03:04 by rhabib            #+#    #+#             *#
#*   Updated: 2016/11/26 16:50:35 by rhabib           ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = fdf
CFLAGS = -Wall -Werror -Wextra
SRC =  main.c color.c command.c display.c draw.c draw_triangle.c env.c \
      eventkey.c height.c isometric.c parallel.c

OBJ = $(SRC:.c=.o)
	LIBX = -lm -I/usr/X11/include -L/usr/X11/lib -lX11 -lXext -lmlx -L./libft/ -lft
	LIBXL = -lm -L libft/ -lft -L/usr/lib/X11 -lmlx -lXext -lX11


all : $(NAME)

.PHONY : linux libft clean fclean re norme

$(NAME) : libft
	@echo "MAC $(NAME) ..."
	@gcc $(CFLAGS) -c $(SRC)
	@gcc -o $(NAME) $(OBJ) $(LIBX)

linux: libft
	@echo "LINUX $(NAME) ..."
	@gcc $(CFLAGS) -c $(SRC)
	@gcc -o $(NAME) $(OBJ) $(LIBXL)

libft:
	@make -C libft fclean
	@make -C libft

clean :
	@echo "Cleaning object files ..."
	@rm -f $(OBJ)

fclean : clean
	@echo "Cleaning $(NAME) ..."
	@rm -f $(NAME)

re : fclean all
