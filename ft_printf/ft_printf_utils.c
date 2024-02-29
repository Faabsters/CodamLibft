/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharms <fharms@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:37:48 by fharms            #+#    #+#             */
/*   Updated: 2024/01/11 13:56:38 by fharms           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits(unsigned long n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

char	*ft_utoa(unsigned int n)
{
	int		numdigits;
	char	*newstr;

	numdigits = ft_count_digits(n, 10);
	newstr = (char *)ft_calloc((numdigits + 1), sizeof(char)); // how to skip the malloc? 
	if (newstr == NULL)
		return (NULL);
	while (numdigits > 0)
	{
		newstr[--numdigits] = (n % 10) + '0';
		n /= 10;
	}
	return (newstr);
}

char	*ft_htoa(unsigned long n, bool bln)
{
	const char	hex_chars[2][16] = {"0123456789abcdef", "0123456789ABCDEF"};
	char		*hex_str;
	size_t		count;

	count = ft_count_digits(n, 16);
	hex_str = ft_calloc(count + 1, sizeof(char)); // how to skip the malloc? 
	if (!hex_str)
		return (NULL);
	hex_str[0] = '0';
	while (n > 0)
	{
		hex_str[--count] = hex_chars[(int)bln][n % 16];
		n /= 16;
	}
	return (hex_str);
}
