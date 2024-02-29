/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharms <fharms@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:49:06 by fharms            #+#    #+#             */
/*   Updated: 2023/11/08 12:46:38 by fharms           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	int		strlen;
	char	*newstr;

	i = 0;
	strlen = ft_strlen(s);
	newstr = (char *)ft_calloc((strlen + 1), sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (i < strlen)
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	return (newstr);
}
