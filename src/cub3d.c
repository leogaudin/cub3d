/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 14:06:50 by lgaudin           #+#    #+#             */
/*   Updated: 2023/09/04 15:17:41 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdio.h>

int	main(void)
{
	t_game	*game;

	game = init_game();
	mlx_hook(game->window, 17, 0, exit_game, game);
	update_game(game);
	mlx_loop(game->mlx);
	return (0);
}
