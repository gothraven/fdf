# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szaghban <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/29 21:53:50 by szaghban          #+#    #+#              #
#    Updated: 2018/09/29 22:07:18 by szaghban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBFTL = -L./libft -lft
MLXL = -L./minilibx_macos -lmlx

SRCS = $(addprefix $(SRCDIR), $(SRCFILES))
OBJS = $(addprefix $(OBJDIR), $(SRCFILES:.c=.o))

OBJDIR = ./objs/
SRCDIR = ./srcs/
INCDIR = ./includes/
SRCFILES = main.c

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
