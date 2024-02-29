/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharms <fharms@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:52:34 by fharms            #+#    #+#             */
/*   Updated: 2023/11/10 23:09:35 by fharms           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **array, int i)
{
	while (i > 0)
		free(array[i-- - 1]);
	free(array);
}

static	size_t	ft_countword(const char *s, char c, size_t count, size_t i)
{
	while (s && s[i])
		if (s[i++] != c && (s[i] == c || s[i] == '\0'))
			count++;
	return (count);
}

static int	ft_copy(const char *s, char **array, char c, int i)
{
	size_t	length;

	length = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				length = ft_strlen(s);
			else
				length = ft_strchr(s, c) - s;
			array[i] = ft_substr(s, 0, length);
			if (!array[i])
			{
				ft_free(array, i);
				return (0);
			}
			s += length;
			i++;
		}
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char		**array;

	if (!s && !*s)
		return (NULL);
	array = (char **)ft_calloc((ft_countword(s, c, 0, 0) + 1), sizeof(char *));
	if (!array || !ft_copy(s, array, c, 0))
		return (NULL);
	return (array);
}
