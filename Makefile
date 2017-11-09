#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/12 17:05:44 by ddufour           #+#    #+#              #
#    Updated: 2016/11/29 11:28:30 by ddufour          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

RM = rm -f

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBS = -LLibs/libft/ -LLibs/minilibx_macos2/

SRCS =	srcs/main.c \
		srcs/fractol.c \
		srcs/ptr_fonc.c \
		srcs/utils.c \
		srcs/utils2.c \
		srcs/utils3.c \
		srcs/utils4.c \
		srcs/utils5.c \
		srcs/fractal1.c \
		srcs/fractal2.c \
		srcs/fractal3.c	\
		srcs/fractal4.c

OBJ = $(SRCS:.c=.o)

$(NAME) : $(OBJ)
	@make -s -C libs/libft
	@echo "Libft Compiled"
	@make  -C libs/minilibx_macos2
	@echo "Minilibx Compiled"
	@$(CC) $(CFLAGS) $(LIBS) -lft -lmlx -framework OpenGL -framework AppKit -o $@ $^
	@echo "Fract'ol Compiled"

all : $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean :
	@make clean -s -C libs/libft
	@echo ".o Libft delete"
	@make clean -s -C libs/minilibx_macos2
	@echo ".o Minilibx delete"
	@$(RM) $(OBJ)
	@echo ".o Fract'ol delete"

fclean : clean
	@$(RM) libs/libft/libft.a
	@echo "libft.a delete"
	@$(RM) libs/minilibx_macos2/libmlx.a
	@echo "libmlx.a delete"
	@$(RM) $(NAME)
	@echo "fractol delete"

re : fclean all