/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 14:54:53 by magouin           #+#    #+#             */
/*   Updated: 2016/05/16 21:30:43 by magouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10

# include <unistd.h>
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>

int		get_next_line(int const fd, char **line);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);

#endif
