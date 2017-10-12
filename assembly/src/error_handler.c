/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 13:51:30 by jnaddef           #+#    #+#             */
/*   Updated: 2016/05/20 14:51:34 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	throw_error(int err_code)
{
	ft_puterr("ERROR line ");
	ft_putnbr_err(g_line_nb);
	ft_puterr("\n");
	if (err_code == 1)
		ft_puterr("Bad format\n");
	else if (err_code == 2)
		ft_puterr("Element described twice\n");
	else if (err_code == 3)
		ft_puterr("Element outranges limits\n");
	else if (err_code == 4)
		ft_puterr("Program name or comment missing\n");
	else if (err_code == 5)
		ft_puterr("Program contains no operation\n");
	else if (err_code == 6)
		ft_puterr("One or more referenced label non existing\n");
	exit(0);
}
