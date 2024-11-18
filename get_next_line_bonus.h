/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgastelu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:36:10 by tgastelu          #+#    #+#             */
/*   Updated: 2024/11/18 19:36:32 by tgastelu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
