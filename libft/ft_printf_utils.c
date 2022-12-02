/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:27:00 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/18 20:01:27 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	total;

	total = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s)
		total += ft_putchar(*s++);
	return (total);
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
		return (ft_putchar('-') + ft_putnbr(-n));
	if (n >= 0 && n <= 9)
		return (ft_putchar(n + '0'));
	return (ft_putnbr(n / 10) + ft_putchar((n % 10) + '0'));
}

int	ft_printaddress(void *address)
{
	unsigned long	address_long;
	int				i;
	char			str[17];
	char			*base;
	int				total;

	if (!address)
		return (ft_putstr("0x0"));
	address_long = (long int)address;
	i = 0;
	base = "0123456789abcdef";
	total = 0;
	while (address_long)
	{
		str[i] = base[address_long % 16];
		address_long /= 16;
		i++;
	}
	total += ft_putstr("0x");
	while (--i >= 0)
		total += ft_putchar(str[i]);
	return (total);
}

int	ft_base(char *base, long int nbr)
{
	if (nbr < 0)
		return (ft_base(base, 4294967296 + nbr));
	if (nbr < 16)
		return (ft_putchar(base[nbr % 16]));
	return (ft_base(base, nbr / 16) + ft_putchar(base[nbr % 16]));
}
