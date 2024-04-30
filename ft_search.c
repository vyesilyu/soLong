/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murathanelcuman <murathanelcuman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:53:40 by murathanelc       #+#    #+#             */
/*   Updated: 2024/04/29 17:58:30 by murathanelc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_call_search_exit(t_game *game)
{
	char	*visited;
	int		i;
	int		result;

	result = 0;
	i = 0;
	visited = malloc(ft_strlen(game->map));
	while (i < ft_strlen(game->map))
	{
		visited[i] = '0';
		i++;
	}
	if (ft_search_e(game, game->start, visited) == 1)
		result = 1;
	free(visited);
	return (result);
}

int	ft_search_e(t_game *game, int i, char *visited)
{
	if (visited[i] == '1' || i < 0
		|| i > ft_strlen(game->map)
		|| (game->map)[i] == '1')
		return (0);
	visited[i] = '1';
	if ((game->map)[i] == 'E')
		return (1);
	return (ft_search_e(game, i + 1, visited)
		|| ft_search_e(game, i - 1, visited)
		|| ft_search_e(game, i + game->width, visited)
		|| ft_search_e(game, i - game->width, visited));
}

int	ft_call_search_item(t_game *game)
{
	char	*visited;
	int		i;
	int		result;

	result = 0;
	i = 0;
	visited = malloc(ft_strlen(game->map));
	if (!visited)
		return (0);
	while (i < ft_strlen(game->map))
	{
		visited[i] = '0';
		i++;
	}
	result = ft_search_i(game, game->start, visited);
	free(visited);
	return (result);
}

int	ft_search_i(t_game *game, int i, char *visited)
{
	int	is_coin;

	is_coin = 0;
	if (visited[i] == '1' || i < 0
		|| i > ft_strlen(game->map)
		|| (game->map)[i] == '1')
		return (0);
	visited[i] = '1';
	if ((game->map)[i] == 'C')
		is_coin = 1;
	return (ft_search_i(game, i + 1, visited)
		+ ft_search_i(game, i - 1, visited)
		+ ft_search_i(game, i + game->width, visited)
		+ ft_search_i(game, i - game->width, visited) + is_coin);
}

int	ft_get_fd(char *path)
{
	int	fd;
	int	len;

	len = ft_strlen(path);
	if (len < 5 || path[len - 1] != 'r' || path[len - 2] != 'e'
		|| path[len - 3] != 'b' || path[len - 4] != '.')
		ft_error("Invalid map name");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("Get next line error");
	return (fd);
}
