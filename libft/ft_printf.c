/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:15:46 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/22 15:54:14 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	if (n >= 0 && n <= 9)
		return (ft_putchar(n + '0'));
	return (ft_putnbr(n / 10) + ft_putchar((n % 10) + '0'));
}

int	ft_printf_calls(va_list args, char type)
{
	int	total;

	total = 0;
	if (type == 'c')
		total += ft_putchar(va_arg(args, int));
	else if (type == 's')
		total += ft_putstr(va_arg(args, char *));
	else if (type == 'p')
		total += ft_printaddress(va_arg(args, void *));
	else if (type == 'd')
		total += ft_putnbr(va_arg(args, int));
	else if (type == 'i')
		total += ft_putnbr(va_arg(args, int));
	else if (type == 'u')
		total += ft_putnbr_unsigned(va_arg(args, int));
	else if (type == 'x')
		total += ft_base("0123456789abcdef", va_arg(args, int));
	else if (type == 'X')
		total += ft_base("0123456789ABCDEF", va_arg(args, int));
	else if (type == '%')
		total += ft_putchar('%');
	else
		total += ft_putchar(type);
	return (total);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		total;

	va_start(args, s);
	i = 0;
	total = 0;
	if (write(1, 0, 0) == -1)
	{
		return (-1);
		va_end(args);
	}
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
			total += ft_printf_calls(args, s[++i]);
		else
			total += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (total);
}
