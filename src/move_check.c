/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:43:24 by antabord          #+#    #+#             */
/*   Updated: 2025/10/07 20:37:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_fun.h"
#include "a_structs.h"

int	move_check(t_game *game, int new_y, int new_x, char key)
{
	if (game->map.grid[new_y][new_x] == '1')
		return (0);
	move_player(game, new_y, new_x);
	write(1, &key, 1);
	write(1, "\n", 1);
	return (1);
}

void	move_player(t_game *game, int new_y, int new_x)
{
	int	old_y;
	int	old_x;
	char	new_tile;
	char	old_tile;

	old_y = game->map.player_y;
	old_x = game->map.player_x;
	new_tile = game->map.grid[new_y][new_x];
	old_tile = game->map.grid[old_y][old_x];
	if (new_tile == 'C')
	{
		game->map.coins_found--;
		game->map.grid[new_y][new_x] = 'A';
	}
	else if (new_tile == 'E')
	{
		if (!game->map.coins_found)
		{
			ft_puterr_non_exit("you win!\n");
			nuke_all(game);
			exit(0);
		}
		else
		{
			ft_puterr_non_exit("you need more coins!\n");
			game->map.grid[new_y][new_x] = 'D';
		}
	}
	else if (new_tile == 'V')
		game->map.grid[new_y][new_x] = 'S';
	else
		game->map.grid[new_y][new_x] = 'P';
	if (old_tile == 'A')
		game->map.grid[old_y][old_x] = 'V';
	else if (old_tile == 'S')
		game->map.grid[old_y][old_x] = 'V';
	else if (old_tile == 'D')
		game->map.grid[old_y][old_x] = 'E';
	else if (old_tile != 'V')
		game->map.grid[old_y][old_x] = '0';
	game->map.player_x = new_x;
	game->map.player_y = new_y;
	map_render(game);
}
