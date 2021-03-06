# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: magouin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/12 17:02:17 by magouin           #+#    #+#              #
#    Updated: 2017/10/12 18:25:54 by magouin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make -C assembly
	make -C vm

fclean:
	make fclean -C assembly
	make fclean -C vm

clean:
	make clean -C assembly
	make clean -C vm

re:
	make re -C assembly
	make re -C vm
