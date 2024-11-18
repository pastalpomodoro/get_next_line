/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgastelu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:36:48 by tgastelu          #+#    #+#             */
/*   Updated: 2024/11/18 19:36:49 by tgastelu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	char_set(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
}

int	if_read(char *buffer, char *line, int fd)
{
	if (read(fd, buffer, BUFFER_SIZE) < 0)
	{
		char_set(line);
		return (-1);
	}
	return (1);
}
