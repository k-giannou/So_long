/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <kgiannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:23:25 by kgiannou          #+#    #+#             */
/*   Updated: 2025/01/18 11:55:32 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_data **data)
{
	int	y;

	y = 0;
	if ((*data)->map[y])
	{
		while ((*data)->map[y] != NULL)
		{
			free((*data)->map[y]);
			(*data)->map[y] = NULL;
			y++;
		}
		free ((*data)->map);
		(*data)->map = NULL;
	}
}

int	ft_free(t_data **data)
{
	if (!data)
		return (0);
	if ((*data)->win != NULL)
	{
		mlx_destroy_window((*data)->mlx, (*data)->win);
		(*data)->win = NULL;
	}
	if ((*data)->mlx != NULL)
	{
		mlx_destroy_display((*data)->mlx);
		if ((*data)->mlx)
			free((*data)->mlx);
		(*data)->mlx = NULL;
	}
	ft_free_map(data);
	free((*data));
	*data = NULL;
	return (1);
}

void	free_images(t_data *data)
{
	if (data->img.desk)
		mlx_destroy_image(data->mlx, data->img.desk);
	if (data->img.exit)
		mlx_destroy_image(data->mlx, data->img.exit);
	if (data->img.flamingo)
		mlx_destroy_image(data->mlx, data->img.flamingo);
	if (data->img.floor)
		mlx_destroy_image(data->mlx, data->img.floor);
	if (data->img.minion)
		mlx_destroy_image(data->mlx, data->img.minion);
	if (data->img.minionleft)
		mlx_destroy_image(data->mlx, data->img.minionleft);
	if (data->img.minionright)
		mlx_destroy_image(data->mlx, data->img.minionright);
	if (data->img.minionback)
		mlx_destroy_image(data->mlx, data->img.minionback);
	if (data->img.zombie)
		mlx_destroy_image(data->mlx, data->img.zombie);
}
