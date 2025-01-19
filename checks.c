/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <kgiannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:30:18 by kgiannou          #+#    #+#             */
/*   Updated: 2025/01/18 12:40:27 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_data **data)
{
	int	y;
	int	x_end;

	x_end = 0;
	while ((*data)->map[0][x_end] != '\n')
	{
		if ((*data)->map[0][x_end] != '1')
			return (0);
		x_end++;
	}
	y = 0;
	while ((*data)->map[++y])
	{
		if ((*data)->map[y][0] != '1' || (*data)->map[y][x_end - 1] != '1')
			return (0);
	}
	y--;
	x_end = 0;
	while ((*data)->map[y][x_end] != '\n')
	{
		if ((*data)->map[y][x_end] != '1')
			return (0);
		x_end++;
	}
	return (1);
}

int	check_rectangular(t_data **data)
{
	int	linesum;
	int	height;
	int	width;

	linesum = 0;
	height = 0;
	width = 1;
	while ((*data)->map[height][linesum] != '\n')
		linesum++;
	while ((*data)->map[height])
	{
		width = 0;
		while ((*data)->map[height][width] != '\n')
			width++;
		if (width != linesum)
			return (0);
		height++;
	}
	if (height == width)
		return (0);
	return (1);
}

int	ft_check_map_malloc(t_data **data, int fd)
{
	(*data)->map = (char **)malloc(sizeof(char *) * (HEIGHT + 1));
	if (!(*data)->map)
	{
		close(fd);
		return (ft_error("ERROR MALLOC"), 0);
	}
	return (1);
}

void	ft_check_lines(t_data **data, int i)
{
	if (i == 0)
	{
		free ((*data)->map);
		free(*data);
		exit (1);
	}
}

void	ft_check_fd(int fd, t_data **data)
{
	if (fd == -1)
	{
		free (*data);
		write(2, "FD_FILE_ERROR\n", 14);
		exit (1);
	}
}
