/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharms <fharms@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:52:54 by fharms            #+#    #+#             */
/*   Updated: 2024/01/11 13:59:46 by fharms           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_switch(va_list args, int type)
{
	if (type == '%')
		return (ft_print_c('%'));
	else if (type == 'c')
		return (ft_print_c(va_arg(args, int)));
	else if (type == 'd' || type == 'i' || type == 'u')
		return (ft_print_int(va_arg(args, int), (type == 'u')));
	else if (type == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (type == 'x' || type == 'X')
		return (ft_print_hexdec(va_arg(args, unsigned int), (type == 'X')));
	else if (type == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long)));
	return (-1);
}

int	ft_printf_loop(va_list args, const char *format, int *i)
{
	if (format[*i] == '%' && format[*i + 1] != '\0')
		return (ft_switch(args, format[++*i]));
	if (format[*i] == '%' && format[*i + 1] == '\0')
		return (-1);
	return (write(1, &format[*i], 1));
}

int	ft_printf(const char *format, ...)
{
	int	rtn_value;
	int	count;
	int	i;

	if (!format)
		return (-1);
	va_list(args);
	va_start(args, format);
	i = 0;
	count = 0;
	rtn_value = 0;
	while (format[i])
	{
		rtn_value = ft_printf_loop(args, format, &i);
		if (rtn_value == -1)
			return (va_end(args), -1); // change this?
		count += rtn_value;
		i++;
	}
	return (va_end(args), count);
}