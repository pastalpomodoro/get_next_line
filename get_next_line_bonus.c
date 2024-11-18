/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgastelu <tgastelu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:35:37 by tgastelu          #+#    #+#             */
/*   Updated: 2024/11/18 19:57:21 by tgastelu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *str)
{
	int		size;
	char	*new_str;

	size = 0;
	while (str[size])
		size++;
	new_str = malloc(sizeof(char) * size + 2);
	if (!new_str)
		return (NULL);
	size = 0;
	while (str[size])
	{
		new_str[size] = str[size];
		size++;
	}
	new_str[size] = '\0';
	new_str[size + 1] = '\0';
	free(str);
	return (new_str);
}

char	*mal_str_addchar(char *line, char c)
{
	int	size;

	size = 0;
	line = ft_realloc(line);
	if (!line)
		return (NULL);
	while (line[size])
		size++;
	line[size] = c;
	return (line);
}

void	decale_buffer(char *buffer)
{
	int	i;

	i = 1;
	while (buffer[i])
	{
		buffer[i - 1] = buffer[i];
		i++;
	}
	buffer[i - 1] = '\0';
}

char	*find_line(char *line, char *buffer, int fd)
{
	if (!buffer[0])
	{
		if (if_read(buffer, line, fd) == -1)
			return (line);
	}
	while (buffer[0])
	{
		line = mal_str_addchar(line, buffer[0]);
		if (!line)
			return (NULL);
		if (buffer[0] == '\n')
		{
			decale_buffer(buffer);
			break ;
		}
		decale_buffer(buffer);
		if (!buffer[0])
		{
			if (if_read(buffer, line, fd) == -1)
				return (line);
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE] = {0};
	char		*line;

	line = malloc(1);
	if (!line)
		return (NULL);
	*line = '\0';
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free (line);
		return (NULL);
	}
	line = find_line(line, buffer[fd], fd);
	if (!line[0])
	{
		free (line);
		return (NULL);
	}
	return (line);
}
int	main()
{
	char	*line;
	int fd1 = open("file1.txt", O_RDONLY);
	int	fd2 = open("file2.txt", O_RDONLY);
	line = get_next_line(fd1);
	line = get_next_line(fd2);
	line = get_next_line(fd1);
	line = get_next_line(fd2);
}