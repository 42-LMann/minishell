/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:36:17 by lmann             #+#    #+#             */
/*   Updated: 2022/03/31 14:33:30 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* %c print a single character */
/* %s print a string of characters */
/* %p The void * pointer argument is printed in hexadecimal */
/* %d print a decimal (base 10) number */
/* %i print an integer in base 10 */
/* %u print an unsigned decimal (base 10) number */
/* %x print a number in hexadecimal (base 16), with lower case. */
/* %X print a number in hexadecimal (base 16), with upper case. */
/* %% print a percent sign */

static t_printf	*initiate(void)
{
	t_printf	*tab;

	tab = (t_printf *)malloc(sizeof(t_printf));
	if (tab == NULL)
		return (NULL);
	tab->t_len = 0;
	return (tab);
}

/* allocate memory size based on the values obtained from t_printf
 * (under the variable of "tab") which contains va_list(args) and
 * int(t_len). More on this in format.c, charstr.c and interger.c */

int	ft_printf(const char *format, ...)
{
	int			i;
	int			r_len;
	t_printf	*tab;

	i = -1;
	r_len = 0;
	tab = initiate();
	va_start(tab->args, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
				ft_eval_conversion(tab, format[i++ + 1]);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			r_len++;
		}
	}
	r_len += tab->t_len;
	va_end(tab->args);
	free(tab);
	return (r_len);
}
