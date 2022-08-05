/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:55:10 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/05 12:59:19 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "map.h"
# include "libft.h"

int	ft_error(char *cause);

int	ft_ferror(char *cause);

int	ft_panic(t_map *map, char *cause, int i);

int	ft_panic_lst(t_list	**l, char *cause, char *line);

#endif
