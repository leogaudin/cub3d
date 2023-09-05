/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:25:11 by lgaudin           #+#    #+#             */
/*   Updated: 2023/09/05 13:26:36 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_pos_dbl  init_pos_dbl(double x, double y)
{
	t_pos_dbl   pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

t_pos_int  init_pos_int(int x, int y)
{
	t_pos_int   pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}
