/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:37:10 by ashirzad          #+#    #+#             */
/*   Updated: 2024/01/09 15:51:10 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_execute(va_list args, char c)
{
	int					global_count;
	void				*str;

	global_count = 0;
	if (c == 's')
		global_count += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		global_count += ft_putnbr(va_arg(args, int));
	else if (c == 'c')
		global_count += ft_write(va_arg(args, int));
	else if (c == 'u')
		global_count += ft_unsigned_nbr(va_arg(args, unsigned int));
	else if (c == '%')
		global_count += write(1, "%%", 1);
	else if (c == 'p')
	{
		str = va_arg(args, void *);
		global_count += ft_put_address(str);
	}
	else if (c == 'x' || c == 'X')
		global_count += ft_print_hex(va_arg(args, unsigned int), c);
	return (global_count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		global_count;

	va_start(args, format);
	global_count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			while (*(format) == ' ')
				format++;
			global_count += ft_execute(args, *format);
		}
		else
			global_count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (global_count);
}
