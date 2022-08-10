/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 08:35:06 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/10 11:20:00 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"
#include <stdlib.h>

t_game	init_game(void)
{
	t_game	ret;

	ret.map = init_map();
	ret.plyr = init_player();
	ret.mnstr = 0;
	ret.items = 0;
	ret.end = 0;
	ret.moves = 0;
	ret.modified = 1;
	return (ret);
}

void	move_player(t_game *game, t_direction drct)
{
	int			ret;
	t_player	ant;

	move(drct, &game->plyr.x, &game->plyr.y);
	ret = is_free(game->map, game->plyr.x, game->plyr.y);
	if (!ret)
		return (rollback(drct, &game->plyr.x, &game->plyr.y));
	ant.x = game->plyr.x;
	ant.y = game->plyr.y;
	rollback(drct, &ant.x, &ant.y);
	game->plyr.drctn = drct;
	if (ret == ITEM)
		game->items--;
	if (ret == EXIT)
		if (game->items <= 0)
			game->end = 1;
	game->moves++;
	game->modified = 1;
}

int	state_game(t_game *game)
{
	t_monsters	tmp;
	int			ret;

	ret = 2;
	if (game->end)
		return (1);
	tmp = game->mnstr;
	if (is_free(game->map, game->plyr.x, game->plyr.y) == ITEM)
	{
		ret = 3;
		game->map.map[game->plyr.y][game->plyr.x] = NOTHING;
	}
	while (tmp)
	{
		if (is_attack(tmp, game->plyr.x, game->plyr.y))
			return (0);
		tmp = tmp->next;
	}
	return (ret);
}

void	destroy_game(t_game *game)
{
	destroy_map(&game->map);
	ft_lstclear(&game->mnstr, free);
}
