/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:00:54 by kgiannou          #+#    #+#             */
/*   Updated: 2024/11/27 16:57:03 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_find_rest(char *rest)
{
	int		i;
	int		k;
	char	*new;

	i = 0;
	k = 0;
	while (rest[i] != '\n' && rest[i] != '\0')
		i++;
	if (!rest[i])
	{
		free(rest);
		return (NULL);
	}
	new = malloc(ft_strlen(rest) - i + 1);
	if (!new)
		return (NULL);
	i++;
	while (rest[i])
		new[k++] = rest[i++];
	new[k] = '\0';
	free(rest);
	return (new);
}

char	*ft_find_line(char *rest)
{
	char	*new;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!rest[i])
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
		i++;
	new = malloc(i + 1);
	if (!new)
		return (NULL);
	while (i > 0)
	{
		new[k] = rest[k];
		k++;
		i--;
	}
	new[k] = '\0';
	return (new);
}

char	*line_and_rest(int fd, char *rest)
{
	int		bytes_read;
	char	*cup_buffer;

	bytes_read = 1;
	cup_buffer = malloc(BUFFER_SIZE + 1);
	if (!cup_buffer)
		return (NULL);
	while (bytes_read != 0)
	{
		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(cup_buffer);
			free (rest);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		cup_buffer[bytes_read] = '\0';
		rest = ft_join(rest, cup_buffer);
		if (ft_check(cup_buffer, '\n') == -1)
			break ;
	}
	free (cup_buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char		*rest;
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	rest = line_and_rest(fd, rest);
	if (!rest)
		return (NULL);
	line = ft_find_line(rest);
	rest = ft_find_rest(rest);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
//	fd = open("text.txt", O_RDWR | O_CREAT, 0777);
//	if (fd != -1)
//		write(fd, "first lines\nsecond lines\nthird lines\nlast lines.", 45);
//	else
//	{
//		write(2, "error text.txt\n", 15);
//		return(1);
//	}
//	close (fd);
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		write(2, "error text.txt\n", 15);
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		printf("%d.%s", count, line);
		free(line);
		line = NULL;
	}
	close(fd);
	return (0);
}*/
