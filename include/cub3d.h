/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:29:48 by lgaudin           #+#    #+#             */
/*   Updated: 2023/09/05 16:25:33 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BLACK "\033[0;30m"
# define DARK_GRAY "\033[1;30m"
# define RED "\033[0;31m"
# define BOLD_RED "\033[1;31m"
# define GREEN "\033[0;32m"
# define BOLD_GREEN "\033[1;32m"
# define BROWN_ORANGE "\033[0;33m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[0;34m"
# define BOLD_BLUE "\033[1;34m"
# define PURPLE "\033[0;35m"
# define BOLD_PURPLE "\033[1;35m"
# define CYAN "\033[0;36m"
# define BOLD_CYAN "\033[1;36m"
# define BOLD_WHITE "\033[0;37m"
# define RESET "\033[0;37m"

# include "../mlx/mlx.h"
# include "libft/src/libft.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 600
# define FOV 66

# define SKY 0x87CEEB
# define FLOOR 0x664228

# define NORTH 0x00FF00
# define SOUTH 0xFF0000
# define EAST 0x0000FF
# define WEST 0xFFFF00

# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

typedef struct s_pos_int
{
	int			x;
	int			y;
}				t_pos_int;

typedef struct s_pos_dbl
{
	double		x;
	double		y;
}				t_pos_dbl;

typedef struct s_player
{
	t_pos_dbl	pos;
	t_pos_dbl	dir;
	t_pos_dbl	plane;
	double		rot_speed;
	double		move_speed;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	void		*image;
	void		*pointer_to_image;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_player	*player;
	char		**map;
}				t_game;

typedef struct s_raycast
{
	double		cameraX;
	t_pos_dbl	pos;
	t_pos_dbl	dir;
	t_pos_int	map;
	t_pos_dbl	side_dist;
	t_pos_dbl	delta_dist;
	double		perp_wall_dist;
	t_pos_int	step;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_raycast;

t_game			*init_game(void);
int				exit_game(t_game *game);

void			draw_pixel(t_game *game, int x, int y, int color);
void			draw_line(t_game *game, int x, int size, int color);
void			draw_sky(t_game *game);
void			draw_floor(t_game *game);
void			update_game(t_game *game);

t_pos_dbl		init_pos_dbl(double x, double y);
t_pos_int		init_pos_int(int x, int y);

t_raycast		*init_raycast(t_player *player, int x);
void			calc_step(t_raycast *ray, t_player *player);
int				perform_dda(t_raycast *ray, char **map);

int				key_press(int keycode, t_game *game);

bool			is_in_bounds(char **map, int x, int y);
bool			can_move(char **map, double x, double y);

void			print_map(char **map);

#endif
