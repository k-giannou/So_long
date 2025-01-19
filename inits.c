/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <kgiannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:14:37 by kgiannou          #+#    #+#             */
/*   Updated: 2025/01/19 12:54:19 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_count(t_data **data)
{
	(*data)->count.one = 0;
	(*data)->count.zero = 0;
	(*data)->count.c = 0;
	(*data)->count.e = 0;
	(*data)->count.p = 0;
	(*data)->count.moves = 0;
	(*data)->count.collected = 0;
}

void	ft_init_data(t_data **data)
{
	(*data)->win = NULL;
	(*data)->mlx = NULL;
	(*data)->map = NULL;
	(*data)->px = 0;
	(*data)->py = 0;
	(*data)->img.desk = NULL;
	(*data)->img.exit = NULL;
	(*data)->img.flamingo = NULL;
	(*data)->img.floor = NULL;
	(*data)->img.minion = NULL;
	(*data)->img.minionleft = NULL;
	ft_init_path(data);
}

int	init_sum_count(t_data **data)
{
	int	x;
	int	y;

	y = 0;
	while ((*data)->map[y])
	{
		x = 0;
		while ((*data)->map[y][x])
		{
			if (!init_sum_count_helper(y, x, data))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	ft_init_img_helper(t_data **data)
{
	int	width;
	int	height;

	width = PIX;
	height = PIX;
	(*data)->img.desk = mlx_xpm_file_to_image((*data)->mlx,
			"xpm/desk.xpm", &width, &height);
	(*data)->img.floor = mlx_xpm_file_to_image((*data)->mlx,
			"xpm/floor.xpm", &width, &height);
	(*data)->img.flamingo = mlx_xpm_file_to_image((*data)->mlx,
			"xpm/flamingo.xpm", &width, &height);
	(*data)->img.exit = mlx_xpm_file_to_image((*data)->mlx,
			"xpm/exit.xpm", &width, &height);
	(*data)->img.minion = mlx_xpm_file_to_image((*data)->mlx,
			"xpm/minion.xpm", &width, &height);
	(*data)->img.minionback = mlx_xpm_file_to_image((*data)->mlx,
			"xpm/minionback.xpm", &width, &height);
	(*data)->img.minionleft = mlx_xpm_file_to_image((*data)->mlx,
			"xpm/minionleft.xpm", &width, &height);
	(*data)->img.zombie = mlx_xpm_file_to_image((*data)->mlx,
			"xpm/zombie.xpm", &width, &height);
	(*data)->img.minionright = mlx_xpm_file_to_image((*data)->mlx,
			"xpm/minionright.xpm", &width, &height);
}

int	ft_init_img(t_data **data)
{
	ft_init_img_helper(data);
	if (!(*data)->img.desk || !(*data)->img.floor
		|| !(*data)->img.flamingo || !(*data)->img.exit
		|| !(*data)->img.minion || !(*data)->img.minionback
		|| !(*data)->img.minionleft
		|| !(*data)->img.minionright || !(*data)->img.zombie)
		return (0);
	return (1);
}
