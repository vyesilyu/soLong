/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:28:54 by Vyesilyu          #+#    #+#             */
/*   Updated: 2023/12/06 20:16:33 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int		i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long n)
{
	long	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
		i++;
	}
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}

int	ft_puthexnbr(unsigned long a, char *s)
{
	int		len;

	len = 0;
	if (a > 15)
		len += ft_puthexnbr(a / 16, s);
	len += ft_putchar(*(s + (a % 16)));
	return (len);
}
