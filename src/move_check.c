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

int	move_check(t_game *game, int new_y, int new_x)
{
	if (game->map.grid[new_y][new_x] == '1')
		return (0);
	move_player(game, new_y, new_x);
	
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
		game->map.coins_found++;
		printf("%d\n", game->map.coins_found);
		printf("%d\n", game->map.coins_map);
		game->map.grid[new_y][new_x] = 'A';
	}
	else if (new_tile == 'E')
	{
		if (!game->map.coins_found)
		{
			printf("vou bazar\n");
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
	else if (new_tile == 'M')
	{
		ft_puterr_non_exit("you died!\n");
		nuke_all(game);
		exit(0);
	}
	else if (new_tile == 'V')
		game->map.grid[new_y][new_x] = 'S';
	else
	{
		game->player.moves++;
		game->map.grid[new_y][new_x] = 'P';
	}
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

void	show_counter(void *mlx, void *win, int count)
{
	char *moves_str;
	char *text;

	moves_str = ft_itoa(count);
	text = ft_strjoin("Moves: ", moves_str);
	mlx_string_put(mlx, win, 20, 20, 0x00FFFFFF, text);
	free(moves_str);
	free(text);
}
