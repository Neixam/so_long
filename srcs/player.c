/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 08:35:19 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/05 13:21:17 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_player	init_player(void)
{
	t_player	ret;

	ret.drctn = 0;
	ret.x = 0;
	ret.y = 0;
	return (ret);
}

void	set_pos_player(t_player *p, int y, int x)
{
	p->x = x;
	p->y = y;
}
