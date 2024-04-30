/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:28:33 by Vyesilyu          #+#    #+#             */
/*   Updated: 2023/12/06 20:07:10 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(va_list arg, char c)
{
	int		len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		len += ft_putnbr(va_arg(arg, unsigned int));
	else if (c == 'x')
		len += ft_puthexnbr(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len += ft_puthexnbr(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_puthexnbr(va_arg(arg, unsigned long), "0123456789abcdef");
	}
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			len += ft_type(args, *(str + 1));
			str++;
		}
		else
			len += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (len);
}
