/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:30:56 by lgaudin           #+#    #+#             */
/*   Updated: 2023/09/05 16:01:22 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (ft_malloc_error());
	player->pos.x = 10;
	player->pos.y = 3;
	player->dir.x = -1;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = 0.66;
	player->move_speed = 1;
	player->rot_speed = 0.25;
	return (player);
}

// void modify_player(t_player *player)
// {
// 	player->pos.x = 31;
// 	player->pos.y = 12;
// 	player->dir.x = -1;
// 	player->dir.y = 0;
// 	player->plane.x = 0;
// 	player->plane.y = 0.66;
// }

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->player = init_player();
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
