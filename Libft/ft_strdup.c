/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharms <fharms@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:32:12 by fharms            #+#    #+#             */
/*   Updated: 2023/10/26 14:47:41 by fharms           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		org_size;
	char	*dup;
	char	*dup_offset;

	org_size = ft_strlen(s);
	dup = ft_calloc(sizeof(char), org_size + 1);
	if (dup == NULL)
		return ((char *) NULL);
	dup_offset = dup;
	while (*s)
	{
		*dup_offset = *s;
		dup_offset++;
		s++;
	}
	return (dup);
}
