/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:14:11 by murathanelc       #+#    #+#             */
/*   Updated: 2024/04/30 19:51:19 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_read_map(t_game *game, char *path)
{
	char	*line;
	int		fd;
	int		height;

	height = 0;
	fd = ft_get_fd(path);
	line = get_next_line(fd);
	game->map = 0;
	game->width = ft_strlen(line);
	while (line)
	{
		if (ft_strlen(line) != game->width)
			ft_error("Line does not fit the length of game");
		game->map = ft_strjoin(game->map, line);
		height++;
		free(line);
		line = get_next_line(fd);
		if (line && line[ft_strlen(line) - 1] != '\n')
			line = ft_strjoin(line, "\n");
	}
	game->height = height;
	close(fd);
	free(line);
	return (0);
}

int	ft_check_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!(game->map))
		ft_error("Empty Map!");
	while (i < game->height)
	{
		if ((game->map)[j] != '1'
			|| (game->map)[j + game->width - 2] != '1')
			ft_error("Wall Error!");
		i++;
		j += game->width;
	}
	i = 0;
	while (i < game-> width - 1)
	{
		if ((game->map)[i] != '1'
			|| (game->map)[i + (game->width) * (game->height - 1)] != '1')
			ft_error("Wall Error!");
		i++;
	}
	return (1);
}

void	ft_start_exit(t_game *game)
{
	int	i;

	i = 0;
	while ((game->map)[i])
	{
		if ((game->map)[i] == 'P')
		{
			game->start = i;
			game->counter = 0;
		}
		else if ((game->map)[i] == 'E')
			game->end = i;
		i++;
	}
}

int	ft_map(t_game *game, char *argv)
{
	ft_read_map(game, argv);
	ft_check_map(game);
	ft_check_counts(game);
	ft_start_exit(game);
	if (ft_call_search_exit(game) == 0)
		ft_error("Error");
	if (ft_call_search_item(game) != game->coin)
		ft_error("Error");
	return (1);
}
