/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:07:59 by lmann             #+#    #+#             */
/*   Updated: 2022/03/25 14:34:00 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_array(char *str, unsigned int n, int len_nbr)
{
	while (n != 0)
	{
		str[len_nbr-- - 1] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

static size_t	ft_len_of_int(int x)
{
	int	len;

	len = 0;
	if (x == 0)
		return (1);
	if (x < 0)
	{
		len += 1;
		x *= -1;
	}
	while (x != 0)
	{
		x = x / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t			len_nbr;
	char			*str;

	len_nbr = ft_len_of_int(n);
	str = (char *)malloc(sizeof(char) * (len_nbr + 1));
	if (str == NULL)
		return (NULL);
	str[len_nbr] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str = ft_array(str, n, len_nbr);
	return (str);
}
