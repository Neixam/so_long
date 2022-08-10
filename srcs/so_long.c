/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 08:31:41 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/09 11:16:17 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "direction.h"
#include "ft_printf.h"
#include <mlx.h>

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

	data = (t_data *)hand;
	ret = state_game(&data->game);
	if (data->game.modified)
	{
		put_game(data);
		ft_printf("moves : %d\n", data->game.moves);
	}
	put_player(&data->graph, data->game.plyr);
	if (ret == 1)
	{
		ft_printf("VICTORY !\n");
		mlx_loop_end(data->graph.mlx);
	}
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
