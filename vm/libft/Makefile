# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: magouin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/27 13:21:11 by magouin           #+#    #+#              #
#    Updated: 2016/06/15 12:04:13 by magouin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Main
NAME	=	libft.a
AR		=	ar -rcs
CC		=	gcc

ifeq ($(DEBUG), yes)
	FDEBUG	=	-Wextra -Wall -Werror
endif

WFLAGS	=	-Wall -Wextra -Werror
OPTI	=	-I
LS		=	ls -1
GREP	=	grep
MKDIR	=	mkdir -p
RM		=	rm -rf

# Directory
DSRC	=	src
DOBJ	=	obj
DINC	=	includes

# File
FSRC	:=	$(shell $(LS) $(DSRC) | $(GREP) \.c$)
FOBJ	:=	$(FSRC:.c=.o)

# Transform
FSRC	:=	$(addprefix $(DSRC)/, $(FSRC))
FOBJ	:=	$(addprefix $(DOBJ)/, $(FOBJ))
FINC	:=	$(addprefix $(OPTI) , $(DINC))

all: $(FOBJ) $(NAME)

$(NAME): $(FOBJ)
	$(AR) $@ $(FOBJ)

$(DOBJ)/%.o: $(DSRC)/%.c $(DINC)
	@$(MKDIR) $(DOBJ)
	$(CC) $(FDEBUG) $(WFLAGS) -c $< $(FINC) -o $@

clean:
	$(RM) $(DOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all begin clean fclean r
