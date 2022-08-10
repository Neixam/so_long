/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:07:30 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/10 10:33:27 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "anim.h"
#include "direction.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	destroy_tab(t_img *anim, void *mlx, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (anim[i].img)
			mlx_destroy_image(mlx, anim[i].img);
}

void	destroy_anim(t_anim *a, void *mlx)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		destroy_tab(a->attack_monster[i], mlx, 7);
		free(a->attack_monster[i]);
	}
	free(a->attack_monster);
	destroy_tab(a->idle_monster, mlx, 5);
	free(a->idle_monster);
	i = -1;
	while (++i < 4)
	{
		destroy_tab(a->idle_player[i], mlx, 5);
		free(a->idle_player[i]);
	}
	free(a->idle_player);
	i = -1;
	while (++i < 2)
	{
		destroy_tab(a->pickup_player[i], mlx, 5);
		free(a->pickup_player[i]);
	}
	free(a->pickup_player);
}

int	add_img(t_img *img, void *m, char *path)
{
	img->img = mlx_xpm_file_to_image(m, path, &img->width, &img->height);
	if (!img->img)
	{
		perror(path);
		return (0);
	}
	return (1);
}

int	add_anim(t_img *a, void *m, char *path, int max)
{
	int		pos;
	char	*tmp;

	pos = ft_strlen(path) - 5;
	tmp = ft_strdup(path);
	while (++tmp[pos] <= '0' + max)
	{
		if (!add_img(&a[tmp[pos] - 49], m, tmp))
		{
			free(tmp);
			return (0);
		}
	}
	free(tmp);
	return (1);
}

int	init_anim(t_anim *a, void *m)
{
	if (alloc_all_anim(a))
		return (1);
	if (!add_anim(a->attack_monster[RIGHT], m, ATT_R_MONS, 7))
		return (1);
	if (!add_anim(a->attack_monster[LEFT], m, ATT_L_MONS, 7))
		return (1);
	if (!add_anim(a->attack_monster[UP], m, ATT_U_MONS, 7))
		return (1);
	if (!add_anim(a->attack_monster[DOWN], m, ATT_D_MONS, 7))
		return (1);
	if (!add_anim(a->idle_monster, m, IDL_MONS, 5))
		return (1);
	if (!add_anim(a->idle_player[RIGHT], m, IDL_R_PLA, 5))
		return (1);
	if (!add_anim(a->idle_player[LEFT], m, IDL_L_PLA, 5))
		return (1);
	if (!add_anim(a->idle_player[UP], m, IDL_U_PLA, 5))
		return (1);
	if (!add_anim(a->idle_player[DOWN], m, IDL_D_PLA, 5))
		return (1);
	if (!add_anim(a->pickup_player[LEFT % 2], m, PUP_L_PLA, 5))
		return (1);
	if (!add_anim(a->pickup_player[RIGHT % 2], m, PUP_R_PLA, 5))
		return (1);
	return (0);
}
