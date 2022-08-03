/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:52:56 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/03 11:39:44 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "ft_printf.h"
#include <stdio.h>

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
