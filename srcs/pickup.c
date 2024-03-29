/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pickup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:22:57 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/10 11:22:40 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "so_long.h"
#include <mlx.h>
#include <stdlib.h>
#include "libft.h"
#include <unistd.h>
#include "error.h"

void	do_end(t_graphic *graph, char *end_msg)
{
	static int	frame = 0;

	graph->freeze = 1;
	mlx_clear_window(graph->mlx, graph->win);
	mlx_string_put(graph->mlx, graph->win,
		graph->size_x / 2, graph->size_y / 2, 0xFFFFFF, end_msg);
	if (frame == 25)
		mlx_loop_end(graph->mlx);
	frame++;
}

void	do_pickup(t_graphic *graph, t_player p)
{
	static int	frame = 0;

	if (frame == 0)
		graph->freeze = (1 | (1 << 3));
	if (frame >= 5)
	{
		graph->freeze = 0;
		frame = 0;
		return ;
	}
	mlx_put_image_to_window(graph->mlx, graph->win,
		graph->anim.pickup_player[p.drctn % 2][frame].img, p.x * 35, p.y * 35);
	frame++;
}

int	init_graph2(t_graphic *graph)
{
	graph->item.img = mlx_xpm_file_to_image(graph->mlx, PITEM,
			&graph->item.width, &graph->item.height);
	if (!graph->item.img)
		return (ft_ferror("mlx_xpm_file_to_image for item"));
	graph->ground.img = mlx_xpm_file_to_image(graph->mlx, PGROUND,
			&graph->ground.width, &graph->ground.height);
	if (!graph->ground.img)
		return (ft_ferror("mlx_xpm_file_to_image for item"));
	if (init_anim(&graph->anim, graph->mlx))
		return (ft_ferror("init_anim"));
	graph->win = mlx_new_window(graph->mlx, graph->size_x,
			graph->size_y, "SO_LONG");
	if (!graph->win)
		return (ft_ferror("mlx_new_window"));
	return (0);
}

void	put_hud(t_data *data)
{
	char	*moves;
	char	*print;

	moves = ft_itoa(data->game.moves);
	print = ft_strjoin("MOVES : ", moves);
	free(moves);
	mlx_string_put(data->graph.mlx, data->graph.win,
		12, 22, 0xFFFFFF, print);
	free(print);
}

void	put_case(t_graphic *graph, t_game *game, int x, int y)
{
	if (game->map.map[y][x] == NOTHING || game->map.map[y][x] == PLAYER)
		mlx_put_image_to_window(graph->mlx, graph->win,
			graph->ground.img, x * 35, y * 35);
	if (game->map.map[y][x] == EXIT)
	{
		if (game->items == 0)
			mlx_put_image_to_window(graph->mlx, graph->win,
				graph->o_exit.img, x * 35, y * 35);
		else
			mlx_put_image_to_window(graph->mlx, graph->win,
				graph->c_exit.img, x * 35, y * 35);
	}
	if (game->map.map[y][x] == ITEM)
		mlx_put_image_to_window(graph->mlx, graph->win,
			graph->item.img, x * 35, y * 35);
	if (game->map.map[y][x] == WALL)
		mlx_put_image_to_window(graph->mlx, graph->win,
			graph->wall.img, x * 35, y * 35);
}
