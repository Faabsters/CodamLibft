/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharms <fharms@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:58:13 by fharms            #+#    #+#             */
/*   Updated: 2024/01/09 23:04:38 by fharms           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h> 
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include "libft/libft.h"

int		ft_print_c(int c);
int		ft_print_int(unsigned int nbr, int u);
int		ft_print_str(char *str);
int		ft_print_hexdec(unsigned int nbr, bool b);
int		ft_print_ptr(unsigned long ptr_nbr);
char	*ft_utoa(unsigned int n);
char	*ft_htoa(unsigned long n, bool b);
int		ft_printf(const char *format, ...);

#endif
