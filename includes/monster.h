/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:40:35 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/05 13:20:04 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONSTER_H
# define MONSTER_H
# include "direction.h"
# include "libft.h"
# include "player.h"

typedef struct s_monster
{
	t_direction	drctn;
	int			x;
	int			y;
}				t_monster;

typedef t_list	*t_monsters;

t_monster		*init_monster(int x, int y);

t_monster		*get(t_monsters ms);

int				is_attack(t_monsters ms, int x, int y);

t_direction		where_attack(t_monster m, t_player p);

#endif
