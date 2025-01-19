/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <kgiannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:08:29 by kgiannou          #+#    #+#             */
/*   Updated: 2025/01/18 17:56:26 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_change_wall(int y, int x, t_data **data)
{
	void	*img;

	if (y == 0 && (*data)->map[y][x] == '1'
		|| x == 0 && (*data)->map[y][x] == '1'
		|| y == (HEIGHT - 1) && (*data)->map[y][x] == '1'
		|| x == (WIDTH - 1) && (*data)->map[y][x] == '1')
	{
		img = (*data)->img.floor;
		if (img)
			mlx_put_image_to_window((*data)->mlx,
				(*data)->win, img, x * PIX, y * PIX);
	}
}
