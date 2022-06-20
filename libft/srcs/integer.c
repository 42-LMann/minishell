/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:16:07 by lmann             #+#    #+#             */
/*   Updated: 2022/03/31 14:33:26 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_unint(t_printf *tab, char character)
{
	int				n;
	unsigned int	un;

	if (character == 'd' || character == 'i')
	{
		n = va_arg(tab->args, int);
		ft_putnbr_fd(n, 1);
		if (n < 0)
			tab->t_len++;
		ft_nbrcount(tab, n);
	}
	if (character == 'u')
	{
		un = va_arg(tab->args, unsigned int);
		ft_put_unsign_nbr_fd(un, 1);
		ft_nbrcount(tab, un);
	}
}

/* first determines if the integer is signed or unsigned then put 
 * either integer throught the necessary print number function 
 * and finally increments t_len based on the length of n or un.*/

void	ft_put_unsign_nbr_fd(unsigned int n, int fd)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr >= 10)
		ft_put_unsign_nbr_fd(nbr / 10, fd);
	ft_putchar_fd((nbr % 10) + '0', fd);
}

/* The equivalent of ft_putnbr_fd except for unsigned integers */

void	ft_nbrcount(t_printf *tab, long n)
{
	unsigned long	nbr;

	nbr = n;
	if (n == 0)
		tab->t_len++;
	while (n != 0)
	{
		n = n / 10;
		tab->t_len++;
	}
}

/* increments t_len based on how long n is.*/
