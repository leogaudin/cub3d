/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:42:09 by lgaudin           #+#    #+#             */
/*   Updated: 2023/09/05 16:20:23 by lgaudin          ###   ########.fr       */
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

void	update_game(t_game *game)
{
	int x;
	int line_height;
	t_raycast *ray;
	int color;

	draw_sky(game);
	draw_floor(game);
	x = 0;
	printf(RED"Player pos x: %f\n", game->player->pos.x);
	printf("Player pos y: %f\n\n", game->player->pos.y);
	printf("Player dir x: %f\n", game->player->dir.x);
	printf("Player dir y: %f\n\n", game->player->dir.y);
	printf("Player plane x: %f\n", game->player->plane.x);
	printf("Player plane y: %f\n\n"RESET, game->player->plane.y);
	while (x < WIDTH)
	{
		ray = init_raycast(game->player, x);
		calc_step(ray, game->player);
		line_height = perform_dda(ray, game->map);
		color = SOUTH;
		if (ray->side == 1)
			color = (color >> 1) & 8355711;
		draw_line(game, x, line_height, color);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->image, 0, 0);
	mlx_string_put(game->mlx, game->window, 10, 20, 0x00FFFFFF, ft_itoa(game->player->pos.x));
	mlx_string_put(game->mlx, game->window, 10, 40, 0x00FFFFFF, ft_itoa(game->player->pos.y));
}
