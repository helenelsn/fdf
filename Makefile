# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 23:23:23 by hlesny            #+#    #+#              #
#    Updated: 2023/02/05 19:35:50 by hlesny           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
RM = rm -f
CFLAGS = -g3

FLAGS_MINILIBX = -lXext -lX11 -lm
MLX_DIR = ./minilibx-linux/
MINILIBX= ./minilibx-linux/libmlx_Linux.a

SRCDIR = ./srcs/
SRCS = 	fdf.c get_map.c draw_map.c draw_line.c projection.c mouse_hook.c \
		get_next_line.c get_next_line_utils.c ft_atoi.c ft_calloc.c  ft_split.c

INC_DIR = ./includes/

OBJDIR = ./objs/
OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))

export C_INCLUDE_PATH = $(INC_DIR):$(MLX_DIR)
export LIBRARY_PATH = $(MLX_DIR)

all : makeminilibx $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $@ $^ $(MINILIBX) $(FLAGS_MINILIBX) 

makeminilibx : 
	make -C $(MLX_DIR)

$(OBJS) : | $(OBJDIR)

$(OBJDIR) :
	mkdir $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	$(RM) $(OBJS) -r $(OBJDIR)
	make clean -C $(MLX_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY :
	re all clean fclean makeminilibx