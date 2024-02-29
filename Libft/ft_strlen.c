/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharms <fharms@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:49:57 by fharms            #+#    #+#             */
/*   Updated: 2024/02/06 12:53:15 by fharms           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *t)
{
	size_t	count;

	count = 0;
	while (t && t[count])
		count++;
	return (count);
}

/*
size_t	ft_strlen(const char *t, size_t i)
{
	printf("%zu %s\n", i, t);
	return (*t && ft_strlen((char *)(t + 1), ++i), i);
}
int main (void)
{
	char *t;
	t = "blablablaaaan";
	printf("ahahahah %zu", ft_strlen(t, 0));
	
	return (0);
}
*/
