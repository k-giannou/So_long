/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:33:46 by kgiannou          #+#    #+#             */
/*   Updated: 2025/01/17 19:37:17 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_sum_count_helper(int y, int x, t_data **data)
{
	if ((*data)->map[y][x] == '1')
		(*data)->count.one += 1;
	else if ((*data)->map[y][x] == '0')
		(*data)->count.zero += 1;
	else if ((*data)->map[y][x] == 'C')
		(*data)->count.c += 1;
	else if ((*data)->map[y][x] == 'E')
		(*data)->count.e += 1;
	else if ((*data)->map[y][x] == 'P')
	{
		(*data)->px = x * PIX;
		(*data)->py = y * PIX;
		(*data)->count.p += 1;
	}
	else if ((*data)->map[y][x] != '\n' && (*data)->map[y][x] != 'K')
		return (0);
	return (1);
}
