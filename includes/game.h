/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 08:36:02 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/03 17:16:03 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "map.h"
# include "player.h"
# include "monster.h"
# include "direction.h"

typedef struct s_game
{
	t_map		map;
	t_player	plyr;
	t_monsters	mnstr;
	int			items;
	int			end;
	int			moves;
}		t_game;

t_game	init_game(void);

void	move_player(t_game *game, t_direction drct);

void	state_game(t_game *game);

void	destroy_game(t_game *game);

#endif
