/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:22:16 by lgaudin           #+#    #+#             */
/*   Updated: 2023/09/05 16:30:36 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	is_in_bounds(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || (size_t)x >= ft_strlen(map[y]))
		return (false);
	return (true);
}

bool	can_move(char **map, double x, double y)
{
	if (!is_in_bounds(map, (int)x, (int)y))
		return (false);
	if (map[(int)y][(int)x] != '0')
		return (false);
	return (true);
}
