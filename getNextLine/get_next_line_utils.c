/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharms <fharms@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:25:30 by fharms            #+#    #+#             */
/*   Updated: 2024/01/31 14:19:48 by fharms           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_str_nl(char *str)
{
	if (!str)
		return (NULL);
	while (*str && *str != '\n')
		str++;
	if (*str == '\n')
		return (str + 1);
	return (NULL);
}

size_t	ft_strlen_nl(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && (i == 0 || str[i - 1] != '\n'))
		i++;
	return (i);
}

void	*ft_memmove(char *buffer)
{
	char	*temp;

	temp = ft_str_nl(buffer);
	if (!temp)
		return (NULL);
	while (*temp)
		*buffer++ = *temp++;
	*buffer = '\0';
	return (NULL);
}

char	*ft_calloc(ssize_t size, size_t n)
{
	char	*src;
	ssize_t	count;

	src = (char *)malloc(size * n);
	if (!src)
		return (NULL);
	count = 0;
	while (count < size)
		src[count++] = '\0';
	return (src);
}
