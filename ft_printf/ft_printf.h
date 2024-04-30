/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:28:13 by Vyesilyu          #+#    #+#             */
/*   Updated: 2023/12/06 19:49:52 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_type(va_list arg, char c);
int		ft_printf(char const *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(long n);
int		ft_puthexnbr(unsigned long a, char *s);

#endif
