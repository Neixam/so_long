/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:56:52 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/05 11:14:14 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "ft_printf.h"
#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	data.game = init_game();
	if (parsing(ac, av, &data.game))
		return (1);
	data.graph.size_x = data.game.map.max_x * 35;
	data.graph.size_y = data.game.map.max_y * 35;
	if (init_graph(&data.graph))
		return (1);
	start_game(&data);
	destroy_data(&data);
	return (0);
}
