/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:39:57 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/10 10:44:34 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "graphic.h"
#include "map.h"
#include "libft.h"
#include "direction.h"
#include <stdlib.h>
#include "error.h"

int	init_graph(t_graphic *graph)
{
	graph->mlx = mlx_init();
	graph->freeze = 0;
	if (!graph->mlx)
		return (ft_ferror("mlx_init"));
	graph->wall.img = mlx_xpm_file_to_image(graph->mlx, PWALL,
			&graph->wall.width, &graph->wall.height);
	if (!graph->wall.img)
		return (ft_ferror("mlx_xpm_file_to_image for wall"));
	graph->o_exit.img = mlx_xpm_file_to_image(graph->mlx, PO_EXIT,
			&graph->o_exit.width, &graph->o_exit.height);
	if (!graph->o_exit.img)
		return (ft_ferror("mlx_xpm_file_to_image for o_exit"));
	graph->c_exit.img = mlx_xpm_file_to_image(graph->mlx, PC_EXIT,
			&graph->c_exit.width, &graph->c_exit.height);
	if (!graph->c_exit.img)
		return (ft_ferror("mlx_xpm_file_to_image for c_exit"));
	return (init_graph2(graph));
}

void	destroy_graphic(t_graphic *graph)
{
	if (graph->wall.img)
		mlx_destroy_image(graph->mlx, graph->wall.img);
	if (graph->o_exit.img)
		mlx_destroy_image(graph->mlx, graph->o_exit.img);
	if (graph->c_exit.img)
		mlx_destroy_image(graph->mlx, graph->c_exit.img);
	if (graph->item.img)
		mlx_destroy_image(graph->mlx, graph->item.img);
	if (graph->ground.img)
		mlx_destroy_image(graph->mlx, graph->ground.img);
	if (graph->anim.attack_monster)
		destroy_anim(&graph->anim, graph->mlx);
	if (graph->win)
		mlx_destroy_window(graph->mlx, graph->win);
	if (graph->mlx)
	{
		mlx_destroy_display(graph->mlx);
		free(graph->mlx);
	}
}

void	put_player(t_graphic *graph, t_player p)
{
	mlx_put_image_to_window(graph->mlx, graph->win,
		graph->anim.idle_player[p.drctn][0].img, p.x * 35, p.y * 35);
}

void	put_monster(t_graphic *graph, t_monsters ms)
{
	t_monster	*m;

	while (ms)
	{
		m = (t_monster *)ms->content;
		mlx_put_image_to_window(graph->mlx, graph->win,
			graph->anim.idle_monster[0].img, m->x * 35, m->y * 35);
		ms = ms->next;
	}
}

void	do_attack(t_graphic *graph, t_monsters ms, t_player p)
{
	static t_monster	*m = 0;
	static int			i = 0;

	if (!m)
	{
		graph->freeze = 1;
		while (ms)
		{
			if (is_attack(ms, p.x, p.y))
			{
				m = (t_monster *)ms->content;
				break ;
			}
			ms = ms->next;
		}
	}
	if (i >= 7)
	{
		mlx_loop_end(graph->mlx);
		return ;
	}
	mlx_put_image_to_window(graph->mlx, graph->win,
		graph->anim.attack_monster[where_attack(*m, p)][i].img,
		m->x * 35, m->y * 35);
	i++;
}
