/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharms <fharms@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:10:26 by fharms            #+#    #+#             */
/*   Updated: 2023/11/08 12:38:16 by fharms           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		temp;
	char	*dest;
	int		slen;

	i = 0;
	temp = 0;
	slen = ft_strlen(s1);
	if (!*s1 && !*set)
		return (ft_strdup(""));
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	temp = i;
	i = 0;
	while (s1[slen - i - 1] && ft_strchr(set, s1[slen - i - 1]))
		i++;
	if ((size_t)temp == ft_strlen(s1))
		return (ft_strdup(""));
	dest = ft_substr((char *)s1 + temp, 0, slen - temp - i);
	return (dest);
}
