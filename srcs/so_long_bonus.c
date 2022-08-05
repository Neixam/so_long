/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:09:50 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/05 14:10:08 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "direction.h"
#include <mlx.h>
#include <unistd.h>

void	put_game(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->game.map.max_y)
	{
		j = -1;
		while (++j < data->game.map.max_x)
			put_case(&data->graph, &data->game, j, i);
	}
	data->game.modified = 0;
}

void	destroy_data(t_data *data)
{
	destroy_game(&data->game);
	destroy_graphic(&data->graph);
}

int	main_loop(void *hand)
{
	t_data	*data;
	int		ret;

	usleep(FRAME);
	data = (t_data *)hand;
	ret = state_game(&data->game);
	if (data->game.modified)
	{
		put_game(data);
		put_hud(data);
	}
	if (ret == 1)
		mlx_loop_end(data->graph.mlx);
	put_player(&data->graph, data->game.plyr);
	put_monster(&data->graph, data->game.mnstr);
	if (ret == 0)
		do_attack(&data->graph, data->game.mnstr, data->game.plyr);
	if (ret == 3 || data->graph.freeze & (1 << 3))
		do_pickup(&data->graph, data->game.plyr);
	return (0);
}

int	handler(int key, void *hand)
{
	t_data	*data;

	data = (t_data *)hand;
	if (data->graph.freeze)
		return (0);
	if (key == W)
		move_player(&data->game, UP);
	if (key == A)
		move_player(&data->game, LEFT);
	if (key == S)
		move_player(&data->game, DOWN);
	if (key == D)
		move_player(&data->game, RIGHT);
	if (key == ESCAPE)
		mlx_loop_end(data->graph.mlx);
	return (0);
}

void	start_game(t_data *data)
{
	mlx_loop_hook(data->graph.mlx, main_loop, data);
	mlx_key_hook(data->graph.win, handler, data);
	mlx_loop(data->graph.mlx);
}
