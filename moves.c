/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <kgiannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:06:29 by kgiannou          #+#    #+#             */
/*   Updated: 2025/01/19 12:58:50 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_c_e(int x, int y, t_data **data)
{
	void	*img;

	if ((*data)->map[y / PIX][x / PIX] == 'K')
	{
		ft_printf("     _____               \n");
		ft_printf("   /   +  \\             \n");
		ft_printf("  |   RIP  |             \n");
		close_win(*data);
	}
	if ((*data)->map[y / PIX][x / PIX] == 'C')
	{
		(*data)->count.collected += 1;
		(*data)->map[y / PIX][x / PIX] = '0';
		img = (*data)->img.floor;
		mlx_put_image_to_window((*data)->mlx, (*data)->win,
			img, (*data)->px, (*data)->py);
	}
	if ((*data)->map[y / PIX][x / PIX] == 'E'
	&& (*data)->count.collected >= (*data)->count.c)
	{
		ft_printf("==========================\n");
		ft_printf("|   Congratulations!     |\n");
		ft_printf("==========================\n");
		close_win(*data);
	}
}

void	move_up(t_data **data)//y - 50, x stable
{
	void	*img;
	int		new;
	int		x;

	new = (*data)->py - PIX;
	x = (*data)->px;
	if ((*data)->map[new / PIX][x / PIX] == '1')
		return ;
	(*data)->count.moves += 1;
	(*data)->py -= PIX;
	check_c_e(x, new, data);
	img = (*data)->img.minionback;
	mlx_put_image_to_window((*data)->mlx, (*data)->win,
		img, (*data)->px, (*data)->py);
	img = (*data)->img.floor;
	if ((*data)->map[(new + PIX) / PIX][x / PIX] == 'E')
		img = (*data)->img.exit;
	mlx_put_image_to_window((*data)->mlx, (*data)->win,
		img, (*data)->px, (*data)->py + PIX);
}

void	move_down(t_data **data)//y + 50, x stable
{
	void	*img;
	int		new;
	int		x;

	new = (*data)->py + PIX;
	x = (*data)->px;
	if ((*data)->map[new / PIX][x / PIX] == '1')
		return ;
	(*data)->count.moves += 1;
	(*data)->py += PIX;
	check_c_e(x, new, data);
	img = (*data)->img.minion;
	mlx_put_image_to_window((*data)->mlx, (*data)->win,
		img, (*data)->px, (*data)->py);
	img = (*data)->img.floor;
	if ((*data)->map[(new - PIX) / PIX][x / PIX] == 'E')
		img = (*data)->img.exit;
	mlx_put_image_to_window((*data)->mlx, (*data)->win,
		img, (*data)->px, (*data)->py - PIX);
}

void	move_left(t_data **data)//y stable, x - 50
{
	void	*img;
	int		new;
	int		y;

	new = (*data)->px - PIX;
	y = (*data)->py;
	if ((*data)->map[y / PIX][new / PIX] == '1')
		return ;
	(*data)->count.moves += 1;
	(*data)->px -= PIX;
	check_c_e(new, y, data);
	img = (*data)->img.minionleft;
	mlx_put_image_to_window((*data)->mlx, (*data)->win,
		img, (*data)->px, (*data)->py);
	img = (*data)->img.floor;
	if ((*data)->map[y / PIX][(new + PIX) / PIX] == 'E')
		img = (*data)->img.exit;
	mlx_put_image_to_window((*data)->mlx, (*data)->win,
		img, (*data)->px + PIX, (*data)->py);
}

void	move_right(t_data **data)//y stable, x + 50
{
	void	*img;
	int		new;
	int		y;

	new = (*data)->px + PIX;
	y = (*data)->py;
	if ((*data)->map[y / PIX][new / PIX] == '1')
		return ;
	(*data)->count.moves += 1;
	(*data)->px += PIX;
	check_c_e(new, y, data);
	img = (*data)->img.minionright;
	mlx_put_image_to_window((*data)->mlx, (*data)->win,
		img, (*data)->px, (*data)->py);
	img = (*data)->img.floor;
	if ((*data)->map[y / PIX][(new - PIX) / PIX] == 'E')
		img = (*data)->img.exit;
	mlx_put_image_to_window((*data)->mlx, (*data)->win,
		img, (*data)->px - PIX, (*data)->py);
}
