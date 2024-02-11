/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 13:05:33 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/01/12 15:19:10 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# if BUFFER_SIZE <= 0
#  error "BUFFER_SIZE needs to be greater than 0."
# endif
# ifndef FILE_DESCRIPTOR_MAX
#  define FILE_DESCRIPTOR_MAX 100000
# endif
# if FILE_DESCRIPTOR_MAX <= 0
#  error "FILE_DESCRIPTIOR_MAX needs to be greater than 0."
# endif
# include <stdlib.h>
# include <stdio.h>

int		set_buffer(char **buffer, int fd);
char	*create_line(char *line, char **buffer);
char	*divide_remainder(char **buffer, int chars_to_newline);
char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
int		get_chars_to_newline(char *string);
char	*ft_strjoin(char *line, char *buffer);
char	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif