# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: magouin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/12 17:02:17 by magouin           #+#    #+#              #
#    Updated: 2017/10/12 17:04:45 by magouin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make -C asm
	make -C vm

fclean:
	make fclean -C asm
	make fclean -C vm

clean:
	make clean -C asm
	make clean -C vm

re:
	make re -C asm
	make re -C vm
