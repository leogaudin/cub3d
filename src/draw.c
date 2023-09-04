/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:42:09 by lgaudin           #+#    #+#             */
/*   Updated: 2023/09/04 15:17:37 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_pixel(t_game *game, int x, int y, int color)
{
	int	*buffer;

	buffer = game->pointer_to_image;
	buffer[(y * game->size_line / 4) + x] = color;
}

void	draw_line(t_game *game, int x, int start, int end, int color)
{
	int	i;

	i = start;
	while (i < end)
	{
		draw_pixel(game, x, i, color);
		i++;
	}
}

void	draw_sky(t_game *game)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		draw_line(game, i, 0, HEIGHT / 2, SKY);
		i++;
	}
}

void	draw_floor(t_game *game)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		draw_line(game, i, HEIGHT / 2, HEIGHT, FLOOR);
		i++;
	}
}

void	update_game(t_game *game)
{
	draw_sky(game);
	draw_floor(game);
	// TODO: draw walls
	mlx_put_image_to_window(game->mlx, game->window, game->image, 0, 0);
}
