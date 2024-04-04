/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:00:28 by ashirzad          #+#    #+#             */
/*   Updated: 2023/11/09 11:30:02 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_address(void *ptr)
{
	char				*str;
	unsigned long long	nbr;

	if (ptr == NULL)
		return (write(1, "0x0", 3));
	nbr = (unsigned long long) ptr;
	str = "0123456789abcdef";
	return (write(1, "0x", 2) + convert_and_write_hex(str, nbr));
}

int	ft_print_hex(unsigned int nbr, char c)
{
	char	*str;

	if (c == 'x')
		str = "0123456789abcdef";
	else if (c == 'X')
		str = "0123456789ABCDEF";
	if (nbr == 0)
		return (ft_write('0'));
	return (convert_and_write_hex(str, nbr));
}

int	convert_and_write_hex(char *str, unsigned long long nbr)
{
	int		digit;
	int		count;
	char	c;

	if (nbr == 0)
		return (0);
	digit = nbr % 16;
	count = convert_and_write_hex(str, nbr / 16);
	c = str[digit];
	return (ft_write(c) + count);
}
