/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:40:10 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/09 10:55:30 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H
# define PWALL "ressources/assets/map/wall.xpm"
# define PGROUND "ressources/assets/map/ground.xpm"
# define PO_EXIT "ressources/assets/map/open_exit.xpm"
# define PC_EXIT "ressources/assets/map/close_exit.xpm"
# define PITEM "ressources/assets/map/item.xpm"
# include "player.h"
# include "monster.h"
# include "anim.h"
# include "game.h"

typedef struct s_graphic
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	int		freeze;
	t_img	wall;
	t_img	o_exit;
	t_img	c_exit;
	t_anim	anim;
	t_img	item;
	t_img	ground;
}	t_graphic;

int		init_graph(t_graphic *graph);

int		init_graph2(t_graphic *graph);

void	destroy_graphic(t_graphic *graph);

void	put_player(t_graphic *graph, t_player p);

void	put_monster(t_graphic *graph, t_monsters ms);

void	do_attack(t_graphic *graph, t_monsters ms, t_player p);

void	do_pickup(t_graphic *graph, t_player p);

void	put_case(t_graphic *graph, t_game *game, int x, int y);

void	do_end(t_graphic *graph, char *end_msg);

#endif
