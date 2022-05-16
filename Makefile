# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hejang <hejang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 20:15:46 by hejang            #+#    #+#              #
#    Updated: 2022/05/16 13:07:41 by hejang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c\
		check_map.c\
		error.c\
		exit.c\
		key.c\
		map.c\
		mlx_window.c\
		position.c\
		put_image.c\

OBJS = $(SRCS:.c=.o)

LIB_DIR = ./libft
MLX_DIR = ./mlx

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm 
RMFLAGS = -f

all : $(NAME)

$(NAME) : $(OBJS)
		$(MAKE) -C ./libft
		$(MAKE) -C ./mlx 
		$(CC) $(CFLAGS) -Llibft -lft -Lmlx -lmlx -framework OpenGl -framework AppKit -Imlx $(OBJS) -o $(NAME)

clean :
		$(MAKE) -C ./libft clean
		$(MAKE) -C ./mlx clean
		$(RM) $(RMFLAG) $(OBJS)

fclean : clean
		$(MAKE) -C ./libft fclean
		$(MAKE) -C ./mlx fclean
		$(RM) $(RMFLAG) $(NAME)

re : fclean all

 .PHONY : all clean fclean re