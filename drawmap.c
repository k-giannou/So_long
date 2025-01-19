/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <kgiannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:59:17 by kgiannou          #+#    #+#             */
/*   Updated: 2025/01/18 19:40:02 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_valid(t_data **data)
{
	ft_init_count(data);
	if (!init_sum_count(data))
		return (0);
	if ((*data)->count.e != 1 || (*data)->count.c < 1 || (*data)->count.p != 1)
		return (0);
	if (!check_walls(data))
		return (0);
	if (!check_rectangular(data))
		return (0);
	if (!valid_path(data))
		return (0);
	return (1);
}

int	ft_open_fd(t_data **data, char *argv)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(argv, O_RDONLY);
	ft_check_fd(fd, data);
	ft_init_data(data);
	if (!ft_check_map_malloc(data, fd))
		return (0);
	while (1)
	{
		(*data)->map[i] = get_next_line(fd);
		if ((*data)->map[i] == NULL)
			break ;
		i++;
	}
	close (fd);
	ft_check_lines(data, i);
	if (!ft_map_valid(data))
		return (ft_error("ERROR IN MAP RULES"), 0);
	return (1);
}

int	ft_draw_map(t_data **data)
{
	int		y;
	int		x;

	y = 0;
	if (!ft_init_img(data))
		return (ft_error("ERROR IMAGES"), 0);
	y = 0;
	while ((*data)->map[y])
	{
		x = 0;
		while ((*data)->map[y][x])
		{
			ft_put_image(y, x, data);
			ft_change_wall(y, x, data);
			x++;
		}
		y++;
	}
	return (1);
}

void	ft_put_image(int y, int x, t_data **data)
{
	void	*img;

	img = NULL;
	if ((*data)->map[y][x] == '1')
		img = (*data)->img.desk;
	else if ((*data)->map[y][x] == '0')
		img = (*data)->img.floor;
	else if ((*data)->map[y][x] == 'C')
		img = (*data)->img.flamingo;
	else if ((*data)->map[y][x] == 'E')
		img = (*data)->img.exit;
	else if ((*data)->map[y][x] == 'P')
		img = (*data)->img.minion;
	else if ((*data)->map[y][x] == 'K')
		img = (*data)->img.zombie;
	if (img)
		mlx_put_image_to_window((*data)->mlx,
			(*data)->win, img, x * PIX, y * PIX);
}
