/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:12:21 by lmann             #+#    #+#             */
/*   Updated: 2022/04/04 13:46:28 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* Protection;
 * frees the allocation of buf if read_val is 0 
 * 		(defined by nothing was read). 
 * or frees the allocation of memory in terms of fd_line
 * 		if nothing was read.*/

void	ft_free_rest(char *mem, int read_val)
{
	if (read_val == 0 && mem)
		free(mem);
}

/* return Values for Get_buffer;
 * correct behaviour; number of bytes 
 * 		read (length of string or up to buffer size)
 * 0; nothing else to be read */

int	ft_get_buffer(int fd, char *buf, int buf_size)
{
	int		read_val;
	int		t_read_val;

	t_read_val = 1;
	read_val = read(fd, buf, 1);
	if (read_val < 1)
	{
		buf = NULL;
		return (0);
	}
	while (buf[t_read_val - 1] != '\n' && read_val > 0 && t_read_val < buf_size)
	{
		read_val = read(fd, buf + t_read_val, 1);
		if (read_val > 0)
			t_read_val++;
	}
	buf[t_read_val] = '\0';
	if (buf[t_read_val - 1] == '\n' && t_read_val == buf_size)
		t_read_val++;
	return (t_read_val);
}
