/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:16:15 by lmann             #+#    #+#             */
/*   Updated: 2022/03/31 14:33:14 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_charstr(t_printf *tab, char character)
{
	char	*str;

	if (character == '%' || character == 'c')
	{
		if (character == '%')
			ft_putchar_fd('%', 1);
		else if (character == 'c')
			ft_putchar_fd(va_arg(tab->args, int), 1);
		tab->t_len++;
	}
	if (character == 's')
	{
		str = va_arg(tab->args, char *);
		if (!str)
		{
			ft_putstr_fd("(null)", 1);
			tab->t_len += 6;
		}
		else
		{
			ft_putstr_fd(str, 1);
			tab->t_len += ft_strlen(str);
		}
	}
}

/* determines if it is a '%', character or a string first and uses
 * the appropriate function (putchar for '%' or 'c' or ft_putstr_fd
 * for 's') and implements the length to t_len by manually adding it 
 * or using ft_strlen.*/
