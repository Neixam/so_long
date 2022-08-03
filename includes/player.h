/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 08:36:41 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/03 12:37:42 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include "direction.h"

typedef struct s_player
{
	t_direction	drctn;
	int			x;
	int			y;
}	t_player;

t_player init_player(void);

void	set_pos_player(t_player *p, int y, int x);

#endif
