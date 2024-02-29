/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharms <fharms@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:23:34 by fharms            #+#    #+#             */
/*   Updated: 2023/11/04 19:26:36 by fharms           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigits(long int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			numdigits;
	char		*newstr;
	long int	nbr;

	numdigits = ft_countdigits((long)n);
	newstr = (char *)malloc((numdigits + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	newstr[numdigits] = '\0';
	nbr = (long)n;
	if (nbr < 0)
		nbr = -nbr;
	while (numdigits > 0)
	{
		newstr[numdigits - 1] = (nbr % 10) + '0';
		nbr /= 10;
		numdigits--;
	}
	if (n < 0)
		newstr[0] = '-';
	return (newstr);
}
