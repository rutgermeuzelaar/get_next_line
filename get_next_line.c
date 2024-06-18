/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 13:09:45 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/01/11 22:44:59 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	set_buffer(char **buffer, int fd)
{
	int		bytes_read;

	bytes_read = 1;
	if (*buffer == NULL)
	{
		*buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (*buffer == NULL)
			return (-1);
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(*buffer);
			*buffer = NULL;
		}
	}
	return (bytes_read);
}

char	*create_line(char *line, char **buffer)
{
	int		chars_to_newline;
	char	*string_to_append;

	chars_to_newline = get_chars_to_newline(*buffer);
	if (chars_to_newline != -1 && chars_to_newline != BUFFER_SIZE - 1)
	{
		string_to_append = divide_remainder(buffer, chars_to_newline);
		if (string_to_append == NULL)
			return (free(line), NULL);
		line = ft_strjoin(line, string_to_append);
		free(string_to_append);
	}
	else
	{
		line = ft_strjoin(line, *buffer);
		free(*buffer);
		*buffer = NULL;
	}
	if (line == NULL)
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	return (line);
}

char	*divide_remainder(char **buffer, int chars_to_newline)
{
	char	*temp_buffer;
	char	*string_to_append;

	temp_buffer = NULL;
	temp_buffer = ft_strjoin(temp_buffer, *buffer);
	free(*buffer);
	*buffer = NULL;
	if (temp_buffer == NULL)
		return (NULL);
	string_to_append = ft_substr(temp_buffer, 0, chars_to_newline + 1);
	if (string_to_append == NULL)
		return (free(temp_buffer), NULL);
	*buffer = ft_substr(temp_buffer, chars_to_newline + 1, \
	BUFFER_SIZE - chars_to_newline);
	if (*buffer == NULL)
		return (free(temp_buffer), free(string_to_append), NULL);
	if (ft_strlen(*buffer) == 0)
	{
		free(*buffer);
		*buffer = NULL;
	}
	free(temp_buffer);
	return (string_to_append);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			bytes_read;

	line = NULL;
	if (fd < 0)
		return (NULL);
	while (get_chars_to_newline(line) == -1)
	{
		bytes_read = set_buffer(&buffer, fd);
		if (bytes_read == 0)
			break ;
		if (bytes_read < 0)
			return (free(line), NULL);
		line = create_line(line, &buffer);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}

// int main(void)
// {
// 	char	*return_value;
// 	int 	fd = open("files/giant_line.txt", O_RDONLY);
// 	bool	loop_switch;

// 	loop_switch = true;
// 	while (loop_switch)
// 	{
// 		return_value = get_next_line(fd);
// 		if (return_value == NULL)
// 			loop_switch = false;
// 		printf(">%s<\n", return_value);
// 		free(return_value);
// 	}
// 	return (0);
// } 