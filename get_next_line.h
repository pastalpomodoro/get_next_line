/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgastelu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:30:55 by tgastelu          #+#    #+#             */
/*   Updated: 2024/11/18 17:33:55 by tgastelu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include<fcntl.h>
# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>

void	char_set(char *str);
char	*get_next_line(int fd);
int		if_read(char *buffer, char *line, int fd);

#endif
