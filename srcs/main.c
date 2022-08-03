/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:56:52 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/03 17:20:09 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "ft_printf.h"
#include "game.h"
#include "graphic.h"

static void	put_game(t_game game)
{
	for (int i = 0; i < game.map.max_y; i++)
	{
		for (int j = 0; j < game.map.max_x; j++)
		{
			if (i == game.plyr.y && j == game.plyr.x)
				ft_printf("H");
			else
				switch (game.map.map[i][j])
				{
				case NOTHING :
					ft_printf(" ");
					break;
				case WALL :
					ft_printf("#");
					break;
				case MONSTER :
					ft_printf("S");
					break;
				case PLAYER :
					ft_printf("P");
					break;
				case ITEM :
					ft_printf("*");
					break;
				case EXIT :
					ft_printf("E");
					break;
				default :
					ft_printf("?");
					break;
				}
		}
		ft_printf("\n");
	}
	ft_printf("moves:%d\nplayer:(%d,%d)\n", game.moves, game.plyr.x, game.plyr.y);
}

#include <stdio.h>

void	ascii_game(t_game game)
{
	char c;

	while (1)
	{
		put_game(game);
		scanf(" %c", &c);
		ft_printf("\033[2J");
		switch (c)
		{
		case 'W' :
		case 'w' :
			ft_printf("UP\n");
			move_player(&game, UP);
			break;
		case 'A' :
		case 'a' :
			ft_printf("LEFT\n");
			move_player(&game, LEFT);
			break;
		case 'S' :
		case 's' :
			ft_printf("DOWN\n");
			move_player(&game, DOWN);
			break;
		case 'D' :
		case 'd' :
			ft_printf("RIGHT\n");
			move_player(&game, RIGHT);
			break;
		default :
			break;
		}
		state_game(&game);
	}
}

int	main(int ac, char **av)
{
	t_game		game;
	t_graphic	graph;

	game = init_game();
	if (parsing(ac, av, &game))
		return (1);
	graph.size_x = game.map.max_x * 35;
	graph.size_y = game.map.max_y * 35;
	if (init_graph(&graph))
		return (1);
	start_game(&game, &graph);
	destroy_game(&game);
	return (0);
}
