/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_anim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 09:48:27 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/05 13:20:54 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anim.h"
#include <stdlib.h>

t_img	*alloc_anim(int size)
{
	t_img	*ret;

	ret = (t_img *)malloc(sizeof(t_img) * size);
	if (!ret)
		return (0);
	return (ret);
}

t_img	**alloc_anim_tab(int size_1, int size_2)
{
	t_img	**ret;
	int		i;

	ret = (t_img **)malloc(sizeof(t_img *) * size_1);
	if (!ret)
		return (0);
	i = -1;
	while (++i < size_1)
	{
		ret[i] = alloc_anim(size_2);
		if (!ret[i])
			return (0);
	}
	return (ret);
}

int	alloc_all_anim(t_anim *a)
{
	a->attack_monster = alloc_anim_tab(4, 7);
	if (!a->attack_monster)
		return (1);
	a->idle_monster = alloc_anim(5);
	if (!a->idle_monster)
		return (1);
	a->idle_player = alloc_anim_tab(4, 5);
	if (!a->idle_player)
		return (1);
	a->pickup_player = alloc_anim_tab(2, 5);
	if (!a->pickup_player)
		return (1);
	return (0);
}
