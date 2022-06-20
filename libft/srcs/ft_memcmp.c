/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:52:59 by lmann             #+#    #+#             */
/*   Updated: 2022/03/25 14:34:20 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)str1;
	b = (unsigned char *)str2;
	if (n == 0 || str1 == str2)
		return (0);
	while (i < n - 1)
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
		i++;
	}
	return (*a - *b);
}
