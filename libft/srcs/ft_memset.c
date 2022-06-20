/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:56:36 by lmann             #+#    #+#             */
/*   Updated: 2022/03/25 14:34:34 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t				i;
	unsigned char		*src;

	i = 0;
	src = (unsigned char *)str;
	while (i < len)
	{
		src[i] = c;
		i++;
	}
	return (str = src);
}
