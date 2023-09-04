/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:29:48 by lgaudin           #+#    #+#             */
/*   Updated: 2023/09/04 15:05:49 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "libft/src/libft.h"
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 600
# define SKY 0x87CEEB
# define FLOOR 0x664228

typedef struct s_player
{
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
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
	int			**map;
}				t_game;

t_game			*init_game(void);
int				exit_game(t_game *game);

void			draw_pixel(t_game *game, int x, int y, int color);
void			draw_line(t_game *game, int x, int start, int end, int color);
void			draw_sky(t_game *game);
void			draw_floor(t_game *game);
void			update_game(t_game *game);

#endif
