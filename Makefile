# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 23:23:23 by hlesny            #+#    #+#              #
#    Updated: 2023/01/21 20:06:18 by hlesny           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g3
SRCDIR = ./srcs/
INCDIR = ./inc/
MLX_DIR = ./minilibx-linux
OBJDIR = ./objs/
SRCS = test.c
OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))

export C_INCLUDE_PATH=$(INC_DIR):$(MLX_DIR)
export LIBRARY_PATH = $(MLX_DIR)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $@ $^ -lmlx -lXext -lX11

$(OBJS) : | $(OBJDIR)

$(OBJDIR) :
	mkdir $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	$(RM) $(OBJS) 

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY :
	all clean fclean re