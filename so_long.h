/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:14:55 by murathanelc       #+#    #+#             */
/*   Updated: 2024/04/30 18:37:51 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "minilibx/mlx.h"

typedef struct s_game
{
	char	*map;
	void	*item;
	void	*player;
	void	*exit;
	void	*floor;
	void	*barrier;
	void	*mlxptr;
	void	*window;
	int		height;
	int		width;
	int		start;
	int		end;
	int		coin;
	int		counter;
}	t_game;

void	ft_error(char *str);
void	ft_solong(t_game *game);
int		ft_map(t_game *game, char *argv);
int		ft_check_map(t_game *game);
int		ft_read_map(t_game *game, char *path);
int		ft_count(char *str, char c);
int		ft_check_counts(t_game *game);
void	ft_start_exit(t_game *game);
int		ft_search_e(t_game *game, int i, char *visited);
int		ft_search_i(t_game *game, int i, char *visited);
int		ft_call_search_exit(t_game *game);
int		ft_call_search_item(t_game *game);
void	ft_put_image(t_game *game);
void	ft_add_image(t_game *game);
int		ft_exit_game(t_game *game);
int		ft_move(int direction, t_game *game);
int		ft_key(int command, t_game *game);
int		ft_get_fd(char *path);

#endif