/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:52:56 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/05 12:59:40 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_error(char *cause)
{
	ft_printf("Error\n%s\n", cause);
	return (1);
}

int	ft_ferror(char *cause)
{
	perror(cause);
	return (1);
}

int	ft_panic(t_map *map, char *cause, int i)
{
	while (i >= 0)
	{
		free(map->map[i]);
		i--;
	}
	free(map->map);
	return (ft_error(cause));
}

int	ft_panic_lst(t_list	**l, char *cause, char *line)
{
	ft_lstclear(l, free);
	free(line);
	return (ft_error(cause));
}
