/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:48:53 by ashirzad          #+#    #+#             */
/*   Updated: 2023/11/08 12:51:09 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str)
	{
		count += write(1, str, 1);
		str++;
	}
	return (count);
}

int	ft_unsigned_nbr(unsigned int n)
{
	char	str[12];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (n == 0)
		count += ft_write('0');
	while (n != 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i > 0)
		count += ft_write(str[--i]);
	return (count);
}

int	ft_putnbr(int n)
{
	char	str[12];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n == 0)
		count += ft_write('0');
	if (n < 0)
	{
		count += ft_write('-');
		n = -n;
	}
	while (n != 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i > 0)
		count += ft_write(str[--i]);
	return (count);
}
