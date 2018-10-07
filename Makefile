# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gothraven <gothraven@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/29 21:53:50 by szaghban          #+#    #+#              #
#    Updated: 2018/10/07 19:17:11 by szaghban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -g3 -fsanitize=address -Wall -Werror -Wextra
LIBFTL = -L./libft -lft
MLXL = -L./minilibx_macos -lmlx

SRCS = $(addprefix $(SRCDIR), $(SRCFILES))
OBJS = $(addprefix $(OBJDIR), $(SRCFILES:.c=.o))

OBJDIR = ./objs/
SRCDIR = ./srcs/
INCDIR = ./includes/
SRCFILES = main.c ft_file_to_image.c ft_image_init.c ft_storgb.c\
			ft_matrice.c ft_paint.c ft_engine.c ft_rotation.c\

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJS)
	make -C ./minilibx_macos
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTL) $(MLXL) -o $(NAME) -framework OpenGL -framework AppKit

clean:
	make -C ./libft clean
	make -C ./minilibx_macos clean
	rm -fr $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
