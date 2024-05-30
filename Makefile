# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 19:09:47 by dmusulas          #+#    #+#              #
#    Updated: 2024/05/28 18:11:04 by dmusulas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC           = cc
CFLAGS       = -Wall -Wextra -Werror -g -Iinclude -Isrc
NAME         = fractol 
MAKE_LIB     = make -C
RM			 = rm -rf

# Libraries
LIBFT_DIR    = ./lib/libft
LIBFT_FILENAME = libft.a
LIBFT        = $(LIBFT_DIR)/$(LIBFT_FILENAME)
CFLAGS		+= -I$(LIBFT_DIR)/include

LIBMLX_DIR    = ./lib/MLX42
LIBMLX_FILENAME = libmlx42.a
LIBMLX			= $(LIBMLX_DIR)/$(LIBMLX_FILENAME)
CFLAGS		+= -I$(LIBMLX_DIR)/include
MLX_LIBS	    := $(LIBMLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

# Sources
VPATH        = src:include
INCLUDES     = fractol.h
FRACTOL_SRCS  = main.c
FRACTOL_OBJS = $(FRACTOL_SRCS:%.c=obj/%.o)

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build -DDEBUG=1 && make -C $(LIBMLX_DIR)/build -j4

libft:
	@make -C $(LIBFT_DIR)

$(NAME): $(FRACTOL_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(FRACTOL_OBJS) $(MLX_LIBS) $(LIBFT) -o $@


$(FRACTOL_OBJS): obj/%.o : src/%.c
				@mkdir -p obj
				$(CC) $(CFLAGS) -c $< -o $@ && printf "Compiling: $(notdir $<)"

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -rf obj
	@rm -rf $(LIBMLX_DIR)/build

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(NAME)

re: fclean all

bonus: $(NAME)

.PHONY: clean fclean all re
