/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:35:43 by lgaudin           #+#    #+#             */
/*   Updated: 2023/09/06 11:41:37 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	move_up(t_player *player, char **map)
{
	if (!can_move(map, (int)(player->pos.x + player->dir.x
				* player->move_speed), (int)(player->pos.y)) || !can_move(map,
			(int)(player->pos.x), (int)(player->pos.y + player->dir.y
				* player->move_speed)))
		return ;
	if (map[(int)(player->pos.y)][(int)(player->pos.x + player->dir.x
			* player->move_speed)] != 0)
		player->pos.x += player->dir.x * player->move_speed;
	if (map[(int)(player->pos.y + player->dir.y
			* player->move_speed)][(int)(player->pos.x)] != 0)
		player->pos.y += player->dir.y * player->move_speed;
}

static void	move_down(t_player *player, char **map)
{
	if (!can_move(map, (int)(player->pos.x - player->dir.x
				* player->move_speed), (int)(player->pos.y)) || !can_move(map,
			(int)(player->pos.x), (int)(player->pos.y - player->dir.y
				* player->move_speed)))
		return ;
	if (map[(int)(player->pos.y)][(int)(player->pos.x - player->dir.x
			* player->move_speed)] != 0)
		player->pos.x -= player->dir.x * player->move_speed;
	if (map[(int)(player->pos.y - player->dir.y
			* player->move_speed)][(int)(player->pos.x)] != 0)
		player->pos.y -= player->dir.y * player->move_speed;
}

static void	move_left(t_player *player)
{
	double	tmp_dir;
	double	tmp_plane;

	tmp_dir = player->dir.x;
	player->dir.x = player->dir.x * cos(-player->rot_speed) - player->dir.y
		* sin(-player->rot_speed);
	player->dir.y = tmp_dir * sin(-player->rot_speed) + player->dir.y
		* cos(-player->rot_speed);
	tmp_plane = player->plane.x;
	player->plane.x = player->plane.x * cos(-player->rot_speed)
		- player->plane.y * sin(-player->rot_speed);
	player->plane.y = tmp_plane * sin(-player->rot_speed) + player->plane.y
		* cos(-player->rot_speed);
}

static void	move_right(t_player *player)
{
	double	tmp_dir;
	double	tmp_plane;

	tmp_dir = player->dir.x;
	player->dir.x = player->dir.x * cos(player->rot_speed) - player->dir.y
		* sin(player->rot_speed);
	player->dir.y = tmp_dir * sin(player->rot_speed) + player->dir.y
		* cos(player->rot_speed);
	tmp_plane = player->plane.x;
	player->plane.x = player->plane.x * cos(player->rot_speed) - player->plane.y
		* sin(player->rot_speed);
	player->plane.y = tmp_plane * sin(player->rot_speed) + player->plane.y
		* cos(player->rot_speed);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_up(game->player, game->map);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(game->player, game->map);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(game->player);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(game->player);
	update_game(game);
	return (0);
}
