/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:33:38 by murathanelc       #+#    #+#             */
/*   Updated: 2024/04/30 20:12:31 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit_game(t_game *game)
{
	mlx_destroy_window(game->mlxptr, game->window);
	free(game->mlxptr);
	free(game->map);
	exit(0);
}

int	ft_move(int direction, t_game *game)
{
	if ((game->start) + direction < 0
		|| (game->start) + direction >= ft_strlen(game->map))
		return (0);
	if ((game->map)[(game->start) + direction] != '1')
	{
		game->start += direction;
		if ((game->map)[(game->start)] == 'C')
			game->coin--;
		(game->map)[game->start] = 'P';
		if ((game->start) - direction == game->end)
			(game->map)[(game->start) - direction] = 'E';
		else
			(game->map)[(game->start) - direction] = '0';
	}
	else
		return (0);
	game->counter += 1;
	ft_printf("Movements: %d\n", game->counter);
	return (1);
}

int	ft_key(int command, t_game *game)
{
	if (command == 53)
		ft_exit_game(game);
	else if (command == 0 || command == 123)
		ft_move(-1, game);
	else if (command == 2 || command == 124)
		ft_move(1, game);
	else if (command == 13 || command == 126)
		ft_move(-1 * (game->width), game);
	else if (command == 1 || command == 125)
		ft_move(game->width, game);
	if (game->start == game->end && game->coin == 0)
	{
		ft_printf("CONGRATS!! YOU FINISHED GAME\n");
		ft_exit_game(game);
	}
	ft_add_image(game);
	return (1);
}
