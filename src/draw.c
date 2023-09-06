/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:42:09 by lgaudin           #+#    #+#             */
/*   Updated: 2023/09/06 11:37:29 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_pixel(t_game *game, int x, int y, int color)
{
	int	*buffer;

	buffer = game->pointer_to_image;
	buffer[(y * game->size_line / 4) + x] = color;
}

void	draw_line(t_game *game, int x, int size, int color)
{
	int	i;

	if (size < 0)
		return ;
	else if (size > HEIGHT)
		size = HEIGHT;
	i = (HEIGHT - size) / 2;
	while (i < (HEIGHT + size) / 2)
	{
		draw_pixel(game, x, i, color);
		i++;
	}
}

void	draw_sky(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < WIDTH)
	{
		while (j < HEIGHT / 2)
		{
			draw_pixel(game, i, j, SKY);
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_floor(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < WIDTH)
	{
		while (j < HEIGHT / 2)
		{
			draw_pixel(game, i, j + HEIGHT / 2, FLOOR);
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_rectangle(t_game *game, t_pos_int top_left, t_pos_int bottom_right,
		int color)
{
	int	i;
	int	j;

	i = top_left.x;
	j = top_left.y;
	while (i < bottom_right.x)
	{
		while (j < bottom_right.y)
		{
			draw_pixel(game, i, j, color);
			j++;
		}
		j = top_left.y;
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	int			i;
	int			j;
	int			color;
	t_pos_int	top_left;
	t_pos_int	bottom_right;

	i = 0;
	color = 0x000000;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				color = 0x000000;
			else if (i == (int)floor(game->player->pos.y)
					&& j == (int)floor(game->player->pos.x))
				color = 0xFF0000;
			else if (game->map[i][j] == '0')
				color = 0xFFFFFF;
			top_left.x = j * 10 + 10;
			top_left.y = i * 10 + 10;
			bottom_right.x = top_left.x + 10;
			bottom_right.y = top_left.y + 10;
			draw_rectangle(game, top_left, bottom_right, color);
			j++;
		}
		i++;
	}
}

void	update_game(t_game *game)
{
	int			x;
	int			line_height;
	t_raycast	*ray;
	int			color;

	draw_sky(game);
	draw_floor(game);
	x = 0;
	while (x < WIDTH)
	{
		ray = init_raycast(game->player, x);
		calc_step(ray, game->player);
		line_height = perform_dda(ray, game->map);
		color = ray->color;
		draw_line(game, x, line_height, color);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->image, 0, 0);
	draw_minimap(game);
	mlx_string_put(game->mlx, game->window, 15, 25, 0xFFFFFF,
			ft_itoa(game->player->pos.x));
	mlx_string_put(game->mlx, game->window, 15, 45, 0xFFFFFF,
			ft_itoa(game->player->pos.y));
}
