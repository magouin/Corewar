# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/17 12:09:34 by jnaddef           #+#    #+#              #
#    Updated: 2017/10/12 17:06:15 by magouin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm
SRCS = main.c \
	   parse.c \
	   parse_name_comment.c \
	   parse_operation.c \
	   check_params_nb.c \
	   error_handler.c \
	   extract_label.c \
	   extract_opcode.c \
	   extract_parameters.c \
	   get_curr_operation.c \
	   line_format.c \
	   op.c \
	   fill_bytes.c \
	   fill_header.c \
	   fill_operations.c \
	   fill_parameter.c \
	   create_output.c \
	   calculate_prog_size.c \
	   has_coding_byte.c \
	   label_format.c \
	   check_valid.c \
	   check_value.c \
	   contains_label.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB_DIR = libft

.PHONY: all, clean, fclean, re, $(LIB_DIR)

all: $(LIB_DIR) $(NAME)

$(LIB_DIR):
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L./$(LIB_DIR) -lft -I$(LIB_DIR) -o $(NAME)

$(OBJS): asm.h libft/libft.h

clean:
	$(MAKE) clean -C $(LIB_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIB_DIR)
	rm -f $(NAME)

re: fclean all
