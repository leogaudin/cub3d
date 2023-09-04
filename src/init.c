/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:30:56 by lgaudin           #+#    #+#             */
/*   Updated: 2023/09/04 15:16:42 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->player = malloc(sizeof(t_player));
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3D");
	game->image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->pointer_to_image = mlx_get_data_addr(game->image,
			&game->bits_per_pixel,
			&game->size_line,
			&game->endian);
	return (game);
}

int	exit_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->image);
	mlx_destroy_window(game->mlx, game->window);
	free(game->player);
	free(game);
	exit(EXIT_SUCCESS);
	return (0);
}
