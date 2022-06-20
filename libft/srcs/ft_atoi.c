/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:03:58 by lmann             #+#    #+#             */
/*   Updated: 2022/03/25 14:32:55 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	val;

	sign = 1;
	val = 0;
	while (*str == ' ' || *str == '\t' || *str == '\r'
		|| *str == '\f' || *str == '\v' || *str == '\n')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		val = val * 10 + (*str - '0');
		str++;
	}
	if (val > 9223372036854775808ULL)
	{	
		if (sign == -1 && val > 9223372036854775808ULL)
			return (0);
		return (-1);
	}
	return (val * sign);
}
