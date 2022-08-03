/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 08:39:02 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/03 12:43:28 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIRECTION_H
# define DIRECTION_H

typedef enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}	t_direction;

void	move(t_direction d, int *x, int *y);

void	rollback(t_direction d, int *x, int *y);

#endif
