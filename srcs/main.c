/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:56:52 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/10 10:38:29 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "so_long.h"
#include "libft.h"

int	main(int ac, char **av)
{
	t_data	data;

	data.game = init_game();
	if (parsing(ac, av, &data.game))
		return (1);
	ft_memset(&data.graph, 0, sizeof(data.graph));
	data.graph.size_x = data.game.map.max_x * 35;
	data.graph.size_y = data.game.map.max_y * 35;
	if (init_graph(&data.graph))
	{
		destroy_data(&data);
		return (1);
	}
	start_game(&data);
	destroy_data(&data);
	return (0);
}
