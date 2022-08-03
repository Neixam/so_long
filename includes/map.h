/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 08:38:19 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/03 11:11:38 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef enum e_case
{
	NOTHING,
	WALL,
	MONSTER,
	PLAYER,
	ITEM,
	EXIT
}	t_case;

typedef struct s_map
{
	t_case	**map;
	int		max_x;
	int		max_y;
}			t_map;

int		is_free(t_map map, int x, int y);

t_map	init_map(void);

#endif
