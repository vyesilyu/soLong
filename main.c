/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murathanelcuman <murathanelcuman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:18:28 by murathanelc       #+#    #+#             */
/*   Updated: 2024/04/29 18:23:13 by murathanelc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

void	ft_solong(t_game *game)
{
	game->mlxptr = mlx_init();
	game->window = mlx_new_window(game->mlxptr, ((game-> width - 1) * 40),
			(game->height * 40), "so_long");
	ft_put_image(game);
	ft_add_image(game);
	mlx_key_hook(game->window, ft_key, game);
	mlx_hook(game->window, 17, 0, (void *)exit, 0);
	mlx_loop(game->mlxptr);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (argc != 2)
		ft_error("Number of arguments should be 2");
	ft_map(game, argv[1]);
	ft_solong(game);
	return (0);
}
