/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <kgiannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:47:39 by kgiannou          #+#    #+#             */
/*   Updated: 2025/01/19 12:59:20 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ftprintf/ft_printf.h"
# include <stdio.h>
# include <stdbool.h>

# define HEIGHT 15
# define WIDTH 30
# define THEIGHT 1500
# define TWIDTH 3000
# define PIX 100
# define ESC 0xff1B
# define W 0x0077
# define A 0x0061
# define S 0x0073
# define D 0x0064

typedef struct s_path
{
	int		x;
	int		y;
	bool	visited[HEIGHT][WIDTH];
	bool	exit;
	int		items;
}	t_path;

typedef struct s_count
{
	int	one;
	int	zero;
	int	c;
	int	e;
	int	p;
	int	moves;
	int	collected;
}	t_count;

typedef struct s_img
{
	void	*desk;
	void	*exit;
	void	*flamingo;
	void	*floor;
	void	*minion;
	void	*minionleft;
	void	*minionright;
	void	*minionback;
	void	*zombie;
}	t_img;

typedef struct s_data
{
	void	*win;
	void	*mlx;
	char	**map;
	int		px;
	int		py;
	t_img	img;
	t_count	count;
	t_path	path;
}			t_data;

void		ft_init_data(t_data **data);
int			ft_map_valid(t_data **data);
int			ft_open_fd(t_data **data, char *argv);
int			ft_check_map_malloc(t_data **data, int fd);
void		ft_check_lines(t_data **data, int i);
void		ft_check_fd(int fd, t_data **data);
int			ft_init_img(t_data **data);
void		ft_init_img_helper(t_data **data);
int			ft_draw_map(t_data **data);
void		ft_init_count(t_data **data);
int			ft_free(t_data **data);
void		ft_free_map(t_data **data);
int			init_sum_count(t_data **data);
int			init_sum_count_helper(int y, int x, t_data **data);
int			check_walls(t_data **data);
int			check_rectangular(t_data **data);
int			valid_path(t_data **data);
int			close_win(void *param);
int			ft_keypress(int keycode, void *param);
void		free_images(t_data *data);
void		move_up(t_data **data);
void		move_left(t_data **data);
void		move_down(t_data **data);
void		move_right(t_data **data);
void		check_c_e(int x, int y, t_data **data);
int			ft_error(char *str);
void		ft_put_image(int y, int x, t_data **data);
void		ft_change_wall(int y, int x, t_data **data);
void		ft_init_path(t_data **data);
void		find_player(t_data **data);
void		path_rcrs(t_data **data, int x, int y);
int			valid_path(t_data **data);
#endif
