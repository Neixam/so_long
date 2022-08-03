/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:40:16 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/03 12:44:36 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "direction.h"

void	move(t_direction d, int *x, int *y)
{
	if (d == UP)
		*y -= 1;
	if (d == DOWN)
		*y += 1;
	if (d == LEFT)
		*x -= 1;
	if (d == RIGHT)
		*x += 1;
}

void	rollback(t_direction d, int *x, int *y)
{
	if (d == UP)
		*y += 1;
	if (d == DOWN)
		*y -= 1;
	if (d == LEFT)
		*x += 1;
	if (d == RIGHT)
		*x -= 1;
}
