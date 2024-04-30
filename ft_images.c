/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:11:20 by murathanelc       #+#    #+#             */
/*   Updated: 2024/04/30 20:10:12 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image(t_game *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxptr,
			"textures/ground.xpm", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlxptr,
			"textures/block.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxptr,
			"textures/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxptr,
			"textures/exit.xpm", &i, &j);
	game->item = mlx_xpm_file_to_image(game->mlxptr,
			"textures/item.xpm", &i, &j);
	if (!(game->floor) || !(game->barrier) || !(game->player)
		|| !(game->exit) || !(game->item))
		ft_error("Missing images!");
}

void	ft_add_image(t_game *game)
{
	int	i;
	int	y;

	i = -1;
	while (i++ < ft_strlen(game->map))
	{
		y = i / game->width;
		if (game->map[i] == '1')
			mlx_put_image_to_window(game->mlxptr, game->window,
				game->barrier, (i % game->width) * 40, y * 40);
		if (game->map[i] == 'C')
			mlx_put_image_to_window(game->mlxptr, game->window,
				game->item, (i % game->width) * 40, y * 40);
		if (game->map[i] == 'P')
			mlx_put_image_to_window(game->mlxptr, game->window,
				game->player, (i % game->width) * 40, y * 40);
		if (game->map[i] == 'E')
			mlx_put_image_to_window(game->mlxptr, game->window,
				game->exit, (i % game->width) * 40, y * 40);
		if (game->map[i] == '0')
			mlx_put_image_to_window(game->mlxptr, game->window,
				game->floor, (i % game->width) * 40, y * 40);
	}
}
