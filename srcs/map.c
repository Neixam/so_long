/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 08:35:31 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/05 11:39:48 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdlib.h>

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

void	destroy_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->max_y)
		free(map->map[i]);
	free(map->map);
}
