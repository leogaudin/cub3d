/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:17:40 by lgaudin           #+#    #+#             */
/*   Updated: 2023/09/06 11:32:42 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_raycast	*init_raycast(t_player *player, int x)
{
	t_raycast	*ray;

	ray = malloc(sizeof(t_raycast));
	if (!ray)
		return (ft_malloc_error());
	x = WIDTH - x;
	ray->cameraX = 2 * x / (double)WIDTH - 1;
	ray->dir.x = player->dir.x + player->plane.x * ray->cameraX;
	ray->dir.y = player->dir.y + player->plane.y * ray->cameraX;
	ray->map.x = (int)player->pos.x;
	ray->map.y = (int)player->pos.y;
	ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = fabs(1 / ray->dir.y);
	ray->hit = 0;
	return (ray);
}

void	calc_step(t_raycast *ray, t_player *player)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (player->pos.x - ray->map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - player->pos.x)
			* ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (player->pos.y - ray->map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - player->pos.y)
			* ray->delta_dist.y;
	}
}

int	perform_dda(t_raycast *ray, char **map)
{
	while (ray->hit == 0)
	{
		if (map[ray->map.y][ray->map.x] == 0)
			return (0);
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
			if (ray->step.x == 1)
				ray->color = EAST;
			else
				ray->color = WEST;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
			if (ray->step.y == 1)
				ray->color = SOUTH;
			else
				ray->color = NORTH;
		}
		if (map[ray->map.y][ray->map.x] != '0')
			ray->hit = 1;
	}
	if (ray->side == 0)
		return ((int)(HEIGHT / (ray->side_dist.x - ray->delta_dist.x)));
	else
		return ((int)(HEIGHT / (ray->side_dist.y - ray->delta_dist.y)));
}
