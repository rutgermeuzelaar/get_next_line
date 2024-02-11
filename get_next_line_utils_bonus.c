/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 14:57:10 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/01/12 15:24:12 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	get_chars_to_newline(char *string)
{
	int	i;

	i = 0;
	if (string == NULL)
		return (-1);
	while (string[i] != '\0')
	{
		if (string[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *line, char *buffer)
{
	size_t	line_len;
	size_t	buffer_len;
	size_t	joined_total;
	char	*joined_str;
	size_t	i;

	line_len = ft_strlen(line);
	buffer_len = ft_strlen(buffer);
	joined_total = line_len + buffer_len + 1;
	joined_str = ft_calloc(joined_total, sizeof(char));
	if (joined_str == NULL)
		return (free(line), NULL);
	i = 0;
	while (i < joined_total - 1)
	{
		if (i < line_len)
			joined_str[i] = line[i];
		else
			joined_str[i] = buffer[i - line_len];
		i++;
	}
	free(line);
	return (joined_str);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	multiplication;
	size_t	i;

	ptr = NULL;
	multiplication = nmemb * size;
	i = 0;
	if (size != 0 && multiplication / size != nmemb)
		return (NULL);
	ptr = malloc(multiplication);
	if (ptr == NULL)
		return (NULL);
	while (i < multiplication)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substring;
	size_t	substring_len;

	i = 0;
	substring = 0;
	substring_len = ft_strlen(s);
	if (start > substring_len)
		substring_len = 0;
	else
		substring_len = ft_strlen(&s[start]);
	if (len > substring_len)
		len = substring_len;
	substring = ft_calloc((len + 1), sizeof(char));
	if (substring == NULL)
		return (NULL);
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	return (substring);
}
