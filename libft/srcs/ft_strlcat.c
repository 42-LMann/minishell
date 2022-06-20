/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:59:50 by lmann             #+#    #+#             */
/*   Updated: 2022/03/25 14:35:22 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = ft_strlen(dest);
	j = 0;
	if (n == 0)
		len = ft_strlen(src);
	else if (n < ft_strlen(dest))
		len = (ft_strlen(src) + n);
	else
		len = (ft_strlen(src) + ft_strlen(dest));
	while (src[j] != '\0' && i < n - 1 && n != 0)
	{	
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (len);
}
