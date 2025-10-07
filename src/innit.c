/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-29 10:43:45 by antabord          #+#    #+#             */
/*   Updated: 2025-09-29 10:43:45 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_structs.h"
#include "a_fun.h"


t_map	*init_grid(void)
{
	t_map *map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = NULL;
	map->height = 0;
	map->width = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->coins_map = 0;
	map->coins_found = 0;
	map->player_on_coin = NULL;
	map->player_on_exit = NULL;
	map->void_coin = NULL;
	map->player = NULL;
	map->wall = NULL;
	map->coins = NULL;
	map->ground = NULL;
	map->exit = NULL;
	return (map);
}

t_player    *player_init(void)
{
	int i;

	i = 0;
    t_player *player = ft_calloc(1, sizeof(t_player));
    if (!player)
        return (NULL);
    player->frames_player = 1;
	player->frames_on_void = 1;
	player->frames_on_coin = 1;
	player->frames_on_exit = 1;
	while (i < 9)
	{
		player->player [i] = NULL;
		player->player_on_coin [i] = NULL;
		player->player_on_exit [i] = NULL;
		player->player_on_void [i] = NULL;
		i++;
	}
	return (player);
}

t_game	*game_init(t_map *map, t_player *player)
{
	t_game *game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->win = NULL;
	game->mlx = NULL;
	game->player = player;
	game->map = map;
	return (game);
}

void	find_p_x(t_map *map)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		while (x < map->width)
		{
			if (map->grid[y][x] == 'P')
			{
				map->player_x = x;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	find_p_y(t_map *map)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		while (x < map->width)
		{
			if (map->grid[y][x] == 'P')
			{
				map->player_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
}