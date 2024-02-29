/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharms <fharms@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:41:24 by fharms            #+#    #+#             */
/*   Updated: 2023/11/30 11:24:15 by fharms           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	*ft_free(char **str)
{
	if (str)
		free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_get_buffer(char *rtn_line, char *buffer)
{
	char			*newstr;
	char			*temp;
	const size_t	r_len = ft_strlen_nl(rtn_line);
	const size_t	b_len = ft_strlen_nl(buffer);
	size_t			i;

	newstr = (char *)ft_calloc((r_len + b_len + 1), sizeof(char));
	if (!newstr)
		return (ft_free(&rtn_line));
	i = 0;
	temp = rtn_line;
	while (i < r_len)
		newstr[i++] = *temp++;
	temp = buffer;
	while (i < r_len + b_len)
		newstr[i++] = *temp++;
	newstr[i] = '\0';
	ft_free(&rtn_line);
	ft_memmove(buffer);
	return (newstr);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*rtn_line;
	ssize_t		rd_bytes;

	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer || fd < 0 || BUFFER_SIZE < 0 || fd > MAX_FD + 1)
		return (ft_free(&buffer));
	rtn_line = NULL;
	rtn_line = ft_get_buffer(rtn_line, buffer);
	rd_bytes = 1;
	while (rtn_line && rd_bytes > 0 && !ft_str_nl(rtn_line))
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if ((int)rd_bytes == -1)
			return (ft_free(&buffer), ft_free(&rtn_line));
		buffer[rd_bytes] = '\0';
		rtn_line = ft_get_buffer(rtn_line, buffer);
		if (rtn_line && rd_bytes == 0 && !*rtn_line)
			return (ft_free(&buffer), ft_free(&rtn_line));
	}
	if (!rtn_line)
		return (ft_free(&buffer));
	return (rtn_line);
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *str;
	if (fd == -1)
		return (0);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		ft_free(&str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}