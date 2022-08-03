/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 08:35:06 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/03 14:12:03 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

t_game	init_game(void)
{
	t_game	ret;

	ret.map = init_map();
	ret.plyr = init_player();
	ret.mnstr = 0;
	ret.items = 0;
	ret.end = 0;
	ret.moves = 0;
	return (ret);
}

void	move_player(t_game *game, t_direction drct)
{
	int	ret;

	move(drct, &game->plyr.x, &game->plyr.y);
	ret = is_free(game->map, game->plyr.x, game->plyr.y);
	if (!ret)
		return (rollback(drct, &game->plyr.x, &game->plyr.y));
	if (ret == ITEM)
		game->items--;
	if (ret == EXIT)
		if (game->items <= 0)
			game->end = 1;
	game->moves++;
}

#include "ft_printf.h"

void	state_game(t_game *game)
{
	t_monsters	tmp;

	if (game->end)
		ft_printf("VICTORY\n"); // VICTORY END
	tmp = game->mnstr;
	if (is_free(game->map, game->plyr.x, game->plyr.y) == ITEM)
	{
		ft_printf("CATCH\n"); // DO ANIM RECUP ITEM
		game->map.map[game->plyr.y][game->plyr.x] = NOTHING;
	}
	while (tmp)
	{
		if (is_attack(tmp, game->plyr.x, game->plyr.y))
			ft_printf("DEAD\n"); // DEAD
		tmp = tmp->next;
	}
}

void	destroy_game(t_game *game)
{
	(void)game;
}
