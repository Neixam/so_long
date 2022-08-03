/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:01:00 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/03 14:05:23 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "error.h"

int	set_case(char c, t_game *game, int i, int j)
{
	int	ret;

	ret = ft_strichr("01MPCE", c);
	if (ret == -1)
		return (0);
	if (ret == ITEM)
		game->items++;
	if (ret == PLAYER)
		set_pos_player(&game->plyr, i, j);
	if (ret == MONSTER)
		ft_lstadd_front(&game->mnstr, ft_lstnew(init_monster(j, i)));
	game->map.map[i][j] = ret;
	return (1);
}

int	last_verif(t_map *map)
{
	int	i;
	int	j;
	int	verif;

	i = -1;
	verif = 0;
	while (++i < map->max_y)
	{
		j = -1;
		while (++j < map->max_x)
		{
			if ((i == 0 || j == 0 || i == map->max_y - 1
				|| j == map->max_x - 1) && map->map[i][j] != WALL)
				return (ft_error("Missing wall"));
			if (map->map[i][j] > MONSTER)
				verif |= (1 << (map->map[i][j] - PLAYER));
		}
	}
	if (verif != 7)
		return (ft_error("Need 1 item, 1 exit and 1 initial pos"));
	return (0);
}

int create_map(t_list *file, t_map *map, t_game *game)
{
	char	*line;
	int		i;
	int		j;

	map->map = (t_case **)malloc(sizeof(t_case *) * map->max_y);
	if (!map->map)
		return (ft_ferror("malloc"));
	i = 0;
	while (file)
	{
		line = (char *)file->content;
		map->map[i] = (t_case *)malloc(sizeof(t_case) * map->max_x);
		if (!map->map[i])
			return (ft_ferror("malloc"));
		j = 0;
		while (*line && *line != '\n')
			if (!set_case(*(line++), game, i, j++))
				return (ft_error("Bad character"));
		file = file->next;
		i++;
	}
	return (last_verif(map));
}

int	reading_file(int fd, t_game *game)
{
	char	*line;
	t_list	*file;

	line = get_next_line(fd);
	if (!line)
		return (ft_error("File is empty"));
	game->map.max_x = ft_strlen(line) - 1;
	file = NULL;
	while (line)
	{
		if (ft_strlen(line) - 1 != ((unsigned long)game->map.max_x))
			return (ft_error("Map isn't rectangular"));
		game->map.max_y++;
		ft_lstadd_back(&file, ft_lstnew(line));
		line = get_next_line(fd);
	}
	if (create_map(file, &game->map, game))
	{
		ft_lstclear(&file, free);
		return (1);
	}
	ft_lstclear(&file, free);
	return (0);
}

int	parsing(int ac, char **av, t_game *game)
{
	int	fd;

	if (ac != 2)
	{
		ft_printf("Bad number of argument\n");
		return (1);
	}
	if (ft_strcmp(ft_strrchr(av[1], '.'), ".ber"))
	{
		ft_printf("%s: Bad format file\n", av[1]);
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_ferror("open"));
	if (reading_file(fd, game))
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
