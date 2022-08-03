/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:40:10 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/03 17:39:31 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H
# include "game.h"
# define PPLAYER "ressources/assets/character/down-idle-1.xpm"
# define PWALL "ressources/assets/map/wall.xpm"
# define PGROUND "ressources/assets/map/ground.xpm"
# define PO_EXIT "ressources/assets/map/open_exit.xpm"
# define PC_EXIT "ressources/assets/map/close_exit.xpm"
# define PITEM "ressources/assets/map/item.xpm"
# define PMONSTER ""

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}			t_img;

typedef struct s_graphic
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	t_img	wall;
	t_img	o_exit;
	t_img	c_exit;
	t_img	player;
	t_img	monster;
	t_img	item;
	t_img	ground;
}	t_graphic;

int		init_graph(t_graphic *graph);

void	start_game(t_game *game, t_graphic *graph);

#endif
