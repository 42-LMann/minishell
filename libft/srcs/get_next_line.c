/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:43:04 by lmann             #+#    #+#             */
/*   Updated: 2022/04/04 13:46:33 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* Return Values for GNL; 
 * correct behaviour; reads line and outputs read line
 * NULL: nothing else to read or an error occurred
 *
 * External functions; read, malloc, free 
 *
 * Write a function which returns a line read from the file decriptor */

char	*get_next_line(int fd)
{
	int			ret_read_val;
	static char	*fd_line;
	char		*buf;
	char		*temp;

	fd_line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!fd_line)
		return (NULL);
	ret_read_val = ft_get_buffer(fd, fd_line, BUFFER_SIZE);
	ft_free_rest(fd_line, ret_read_val);
	if (ret_read_val == 0)
		return (NULL);
	while (ret_read_val == BUFFER_SIZE)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		ret_read_val = ft_get_buffer(fd, buf, BUFFER_SIZE);
		ft_free_rest(buf, ret_read_val);
		if (ret_read_val == 0)
			break ;
		temp = fd_line;
		fd_line = ft_strjoin(temp, buf);
		free(temp);
		free(buf);
	}
	return (fd_line);
}
