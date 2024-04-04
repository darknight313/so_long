/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:50:26 by ashirzad          #+#    #+#             */
/*   Updated: 2023/11/08 13:01:40 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int		ft_putstr(char *str);
int		ft_printf(const char *format, ...);
int		ft_put_address(void *ptr);
int		ft_print_hex(unsigned int nbr, char c);
int		ft_write(int c);
int		ft_unsigned_nbr(unsigned int n);
int		ft_putnbr(int n);
int		convert_and_write_hex(char *str, unsigned long long nbr);

#endif
