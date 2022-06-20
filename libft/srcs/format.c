/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:19:08 by lmann             #+#    #+#             */
/*   Updated: 2022/03/25 16:40:01 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_eval_conversion(t_printf *tab, const char character)
{	
	if (character == 'c' || character == '%' || character == 's')
		ft_charstr(tab, character);
	else if (character == 'p' || character == 'x' || character == 'X')
	{
		if (character == 'p')
			ft_putstr_fd("0x", 1);
		if (character == 'p')
			tab->t_len += 2;
		ft_hex(tab, character);
	}
	else if (character == 'd' || character == 'i' || character == 'u')
		ft_unint(tab, character);
	else if (character != '\0')
	{
		ft_putchar_fd(character, 1);
		tab->t_len++;
	}
}

/* Sets the conversion type of printf based on what const
 * character is and feeds it in to the three key functions.*/

char	*ft_nbrlen(unsigned long nbr, int *len)
{
	char	*str;

	while (nbr >= 16)
	{
		nbr = nbr / 16;
		*len += 1;
	}
	str = (char *)malloc((*len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[*len] = '\0';
	return (str);
}

/* determines the memory alloaction length based on the nbr 
 * interger divided by 16 */

void	ft_hex(t_printf *tab, char character)
{
	unsigned long	nbr;
	int				len;
	char			*str;

	if (character == 'p')
		nbr = va_arg(tab->args, unsigned long);
	else
		nbr = va_arg(tab->args, unsigned int);
	len = 1;
	str = ft_nbrlen(nbr, &len);
	len--;
	while (len >= 0)
	{
		if (nbr % 16 < 10)
			str[len] = '0' + (nbr % 16);
		else if (character == 'X')
			str[len] = 'A' - 10 + (nbr % 16);
		else
			str[len] = 'a' - 10 + (nbr % 16);
		len--;
		tab->t_len++;
		nbr = nbr / 16;
	}
	ft_putstr_fd(str, 1);
	free(str);
}

/* first determines whether it is a pointer address or a hexadecimal
 * interger then feeds it into ft_nbr to determine allocation length
 * and then fills the string backwards with the necessary characters
 * until len is 0 while increasing tab->t_len and then prints you
 * the string using ft_putstr_fd. */
