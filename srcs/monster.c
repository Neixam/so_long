/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:40:08 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/03 13:51:37 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monster.h"
#include <stdlib.h>

t_monster	*init_monster(int x, int y)
{
	t_monster	*ret;

	ret = (t_monster *)malloc(sizeof(t_monster));
	if (!ret)
		return (0);
	ret->drctn = 0;
	ret->x = x;
	ret->y = y;
	return (ret);
}

t_monster	*get(t_monsters ms)
{
	return ((t_monster *)ms->content);
}

int	is_attack(t_monsters ms, int x, int y)
{
	int xdiff;
	int ydiff;

	if (get(ms)->x < x)
		xdiff = x - get(ms)->x;
	else
		xdiff = get(ms)->x - x;
	if (get(ms)->y < y)
		ydiff = y - get(ms)->y;
	else
		ydiff = get(ms)->y - y;
	if (ydiff + xdiff <= 1)
		return (1);
	return (0);
}
