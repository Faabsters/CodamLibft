/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharms <fharms@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:41:36 by fharms            #+#    #+#             */
/*   Updated: 2023/11/29 18:21:57 by fharms           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

# define MAX_FD 1000

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_str_nl(char *str);
size_t	ft_strlen_nl(char *str);
void	*ft_memmove(char *buffer);
char	*ft_calloc(ssize_t size, size_t n);
void	*ft_free(char **str);
char	*ft_get_buffer(char *rtn_line, char *buffer);
char	*get_next_line(int fd);

#endif
