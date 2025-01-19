/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:44:05 by kgiannou          #+#    #+#             */
/*   Updated: 2024/11/27 16:50:30 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

char	*get_next_line(int fd);
char	*line_and_rest(int fd, char *rest);
char	*ft_join(char *rest, char *cup_buffer);
int		ft_check(char *cup_buffer, char c);
//int		ft_strlen(char *str);
char	*ft_find_rest(char *rest);
char	*ft_find_line(char *rest);

#endif
