# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: magouin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 18:55:28 by magouin           #+#    #+#              #
#    Updated: 2016/05/18 13:26:53 by magouin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/

SRC_NAME = ft_atoi.c \
		   ft_strrchr.c \
		   ft_bzero.c \
		   ft_isalnum.c \
		   ft_isalpha.c \
		   ft_isascii.c \
		   ft_isdigit.c \
		   ft_isprint.c \
		   get_next_line.c \
		   ft_itoa.c \
		   ft_memalloc.c \
		   ft_memccpy.c \
		   ft_memchr.c \
		   ft_memcmp.c \
		   ft_memset.c \
		   ft_memmove.c \
		   ft_memdel.c \
		   ft_memcpy.c \
		   ft_putchar.c \
		   ft_putchar_fd.c \
		   ft_putstr.c \
		   ft_putstr_fd.c \
		   ft_strcat.c \
		   ft_itoa_base.c \
		   ft_itoa_base_long.c \
		   ft_itoa_base_u.c \
		   ft_itoa_base_u_long.c \
		   ft_itoa_long.c \
		   ft_itoa_u.c \
		   ft_itoa_u_long.c \
		   ft_strchr.c \
		   ft_strclr.c \
		   ft_strcmp.c \
		   converse.c \
		   flags.c \
		   ft_chiffre.c \
		   test1.c \
		   test2.c \
		   ft_printf.c \
		   ft_strcpy.c \
		   ft_strdel.c \
		   ft_strdup.c \
		   ft_strequ.c \
		   ft_striter.c \
		   ft_strjoin.c \
		   ft_strlcat.c \
		   ft_strlen.c \
		   ft_strmap.c \
		   ft_strmapi.c \
		   ft_strncat.c \
		   ft_strncmp.c \
		   ft_strnequ.c \
		   ft_strncpy.c \
		   ft_zero.c \
		   ft_plus.c \
		   ft_strnew.c \
		   ft_strnstr.c \
		   ft_strsplit.c \
		   ft_strstr.c \
		   ft_strsub.c \
		   ft_strtrim.c \
		   ft_tolower.c \
		   ft_toupper.c \
		   ft_putendl.c \
		   ft_putendl_fd.c \
		   ft_putnbr.c \
		   ft_putnbr_fd.c \
		   ft_striteri.c \
		   ft_lstnew.c \
		   ft_lstdel.c \
		   ft_lstdelone.c \
		   ft_lstadd.c \
		   ft_lstiter.c

OBJ_PATH = ./obj/

NAME = libftprintf.a

CC = gcc

CFLAGS = -Werror -Wextra -Wall -c -g

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ_PATH) $(OBJ)
	ar r $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

clean:
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
