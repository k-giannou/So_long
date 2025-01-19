/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <kgiannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:55:52 by kgiannou          #+#    #+#             */
/*   Updated: 2025/01/19 12:59:40 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_path(t_data **data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	(*data)->path.items = 0;
	(*data)->path.x = 0;
	(*data)->path.y = 0;
	(*data)->path.exit = false;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			(*data)->path.visited[y][x] = false;
			x++;
		}
		y++;
	}
}

void	find_player(t_data **data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if ((*data)->map[y][x] == 'P')
			{
				(*data)->path.y = y;
				(*data)->path.x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	path_rcrs(t_data **data, int x, int y)
{
	if ((*data)->path.visited[y][x] == true
		|| y < 0 || x < 0 || y > HEIGHT || x > WIDTH
		|| (*data)->map[y][x] == '1')
		return ;
	else if ((*data)->map[y][x] == 'C' || (*data)->map[y][x] == 'E')
	{
		if ((*data)->map[y][x] == 'C')
			(*data)->path.items += 1;
		else
			(*data)->path.exit = true;
		if ((*data)->path.items == (*data)->count.collected)
			return ;
	}
	(*data)->path.visited[y][x] = true;
	path_rcrs(data, x - 1, y);
	path_rcrs(data, x + 1, y);
	path_rcrs(data, x, y - 1);
	path_rcrs(data, x, y + 1);
}

int	valid_path(t_data **data)
{
	int	x;
	int	y;

	find_player(data);
	x = (*data)->path.x;
	y = (*data)->path.y;
	path_rcrs(data, x, y);
	if ((*data)->path.exit
		&& (((*data)->path.items == (*data)->count.c)))
		return (1);
	return (0);
}
