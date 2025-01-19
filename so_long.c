/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <kgiannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:24:04 by kgiannou          #+#    #+#             */
/*   Updated: 2025/01/19 12:51:45 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->mlx)
		mlx_loop_end(data->mlx);
	return (0);
}

int	ft_keypress(int keycode, void *param)
{
	t_data	*data;
	char	*score;
	char	*score_str;

	score_str = "SCORE: ";
	data = (t_data *)param;
	if (keycode == ESC)
		close_win(param);
	else
	{
		if (keycode == W)
			move_up(&data);
		else if (keycode == A)
			move_left(&data);
		else if (keycode == S)
			move_down(&data);
		else if (keycode == D)
			move_right(&data);
		score = ft_itoa(data->count.moves);
		ft_printf("Moves: %s\n", score);
		mlx_string_put(data->mlx, data->win, 200, 200, 0xFFFFFF, score_str);
		mlx_string_put(data->mlx, data->win, 260, 200, 0x000000, score);
		free (score);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (ft_error("./so_long map.ber"));
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (ft_error("ERROR MALLOC"), 0);
	if (!ft_open_fd(&data, argv[1]))
		return (ft_free(&data), 0);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (ft_error("ERROR MLX CONNECTION"), ft_free(&data));
	data->win = mlx_new_window(data->mlx, TWIDTH, THEIGHT, "42Perpi");
	if (data->win == NULL)
		return (ft_error("ERROR IN WINDOW"), ft_free(&data));
	if (!ft_draw_map(&data))
		close_win(data);
	mlx_hook(data->win, 17, 0, close_win, data);
	mlx_key_hook(data->win, ft_keypress, data);
	mlx_loop(data->mlx);
	free_images(data);
	ft_free(&data);
	return (0);
}
