/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharms <fharms@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:37:47 by fharms            #+#    #+#             */
/*   Updated: 2023/11/04 19:27:38 by fharms           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (!*little)
		return ((char *)big);
	while (*big && len > 0 && len >= ft_strlen(little))
	{
		if (ft_strncmp(big, little, (ft_strlen(little))) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
