/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 08:31:50 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/05 10:52:13 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "graphic.h"
# include "game.h"
# define W 119
# define A 97
# define S 115
# define D 100
# define ESCAPE 65307
# define FRAME 120000

typedef struct s_data
{
	t_game		game;
	t_graphic	graph;
}				t_data;

void	start_game(t_data *data);

void	destroy_data(t_data *data);

void	put_hud(t_data *data);

#endif
