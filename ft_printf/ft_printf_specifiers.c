/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharms <fharms@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:32:45 by fharms            #+#    #+#             */
/*   Updated: 2024/01/11 13:57:20 by fharms           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_int(unsigned int nbr, int u)
{
	char	*str;
	int		count;

	if (u == 1)
		str = ft_utoa(nbr);
	else
		str = ft_itoa((int)nbr);
	if (!str)
		return (-1);
	count = write(1, str, ft_strlen(str));
	return (free((char *)str), count);
}

int	ft_print_str(char *str)
{
	if (str == NULL)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_print_hexdec(unsigned int nbr, bool b)
{
	char	*hex_str;
	int		size;

	size = 0;
	hex_str = ft_htoa(nbr, b);
	if (!hex_str)
		return (write(1, "(null)", 6));
	size = write(1, hex_str, ft_strlen(hex_str));
	return (free(hex_str), size);
}

int	ft_print_ptr(unsigned long ptr_nbr)
{
	char	*ptr_str;
	int		size;

	if (!ptr_nbr)
		return (write(1, "(nil)", 5));
	ptr_str = ft_htoa(ptr_nbr, 0);
	if (ptr_str == NULL)
		return (write(1, "(nil)", 5));
	size = write(1, "0x", 2);
	size += write(1, ptr_str, ft_strlen(ptr_str));
	return (free(ptr_str), size);
}
