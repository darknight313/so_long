/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:13:25 by ashirzad          #+#    #+#             */
/*   Updated: 2024/03/22 12:23:00 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*ptr;

	ptr = dest;
	while (n > 0 && *src)
	{
		*dest++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*dest++ = '\0';
		n--;
	}
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ptr;

	if (s1 != NULL)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	if (s2 != NULL)
		len2 = ft_strlen(s2);
	else
		len2 = 0;
	ptr = (char *)malloc(len1 + len2 + 1);
	if (ptr == NULL)
		return (NULL);
	if (s1 != NULL)
		ft_strncpy(ptr, s1, len1);
	if (s2 != NULL)
		ft_strncpy(ptr + len1, s2, len2);
	ptr[len1 + len2] = '\0';
	return (ptr);
}
