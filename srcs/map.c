/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 08:35:31 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/03 14:06:53 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map	init_map(void)
{
	t_map	ret;

	ret.map = 0;
	ret.max_x = 0;
	ret.max_y = 0;
	return (ret);
}

int	is_free(t_map map, int x, int y)
{
	if (map.map[y][x] == WALL || map.map[y][x] == MONSTER)
		return (0);
	if (map.map[y][x] == NOTHING)
		return (404);
	return (map.map[y][x]);
}
