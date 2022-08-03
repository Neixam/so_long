/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:39:57 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/03 17:56:25 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "graphic.h"


int		init_graph(t_graphic *graph)
{
	graph->mlx = mlx_init();
	if (!graph->mlx)
		return (1);
	graph->wall.img = mlx_xpm_file_to_image(graph->mlx, PWALL, &graph->wall.width, &graph->wall.height);
	if (!graph->wall.img)
		return (1);
	graph->o_exit.img = mlx_xpm_file_to_image(graph->mlx, PO_EXIT, &graph->o_exit.width, &graph->o_exit.height);
	if (!graph->o_exit.img) 
		return (1);
	graph->c_exit.img = mlx_xpm_file_to_image(graph->mlx, PC_EXIT, &graph->c_exit.width, &graph->c_exit.height);
	if (!graph->c_exit.img) 
		return (1);
	graph->player.img = mlx_xpm_file_to_image(graph->mlx, PPLAYER, &graph->player.width, &graph->player.height);
	if (!graph->player.img)
		return (1);
	graph->item.img = mlx_xpm_file_to_image(graph->mlx, PITEM, &graph->item.width, &graph->item.height);
	if (!graph->item.img) 
		return (1);
	graph->ground.img = mlx_xpm_file_to_image(graph->mlx, PGROUND, &graph->ground.width, &graph->ground.height);
	if (!graph->ground.img)
		return (1);
	graph->win = mlx_new_window(graph->mlx, graph->size_x, graph->size_y, "SO_LONG");
	if (!graph->win)
		return (1);
//	graph->monster.img = mlx_xpm_file_to_image(graph->mlx, PMONSTER, &graph->monster.width, &graph->monster.height);
	return (0);
}

void	put_game(t_game *game, t_graphic *graph)
{
	int i;
	int j;

	i = -1;
	while (++i < game->map.max_y)
	{
		j = -1;
		while (++j < game->map.max_x)
		{
			if (game->map.map[i][j] == NOTHING)
				mlx_put_image_to_window(graph->mlx, graph->win, graph->ground.img, j * 35, i * 35);
			if (game->map.map[i][j] == PLAYER)
				mlx_put_image_to_window(graph->mlx, graph->win, graph->player.img, j * 35, i * 35);
			if (game->map.map[i][j] == EXIT)
			{
				if (game->end)
					mlx_put_image_to_window(graph->mlx, graph->win, graph->o_exit.img, j * 35, i * 35);
				else
					mlx_put_image_to_window(graph->mlx, graph->win, graph->c_exit.img, j * 35, i * 35);
			}
		//	if (game->map.map[i][j] == MONSTER)
		//		mlx_put_image_to_window(graph->mlx, graph->win, graph->monster.img, j * 35, i * 35);
			if (game->map.map[i][j] == ITEM)
				mlx_put_image_to_window(graph->mlx, graph->win, graph->item.img, j * 35, i * 35);
			if (game->map.map[i][j] == WALL)
				mlx_put_image_to_window(graph->mlx, graph->win, graph->wall.img, j * 35, i * 35);
		}
	}
}

void	start_game(t_game *game, t_graphic *graph)
{
	put_game(game, graph);
	while (1);
}
