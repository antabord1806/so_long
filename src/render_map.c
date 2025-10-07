/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:25:57 by antabord          #+#    #+#             */
/*   Updated: 2025/10/05 11:49:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_fun.h"
#include "a_structs.h"

void	map_render(t_game *game)
{
	int x;
	int y;
	void *img_draw;

	x = 0;
	y = 0;
	while (y < game->map->height)
	{
		while (x < game->map->width)
		{
			if (game->map->grid[y][x] == '0')
				img_draw = game->map->ground;
			else if (game->map->grid[y][x] == '1')
				img_draw = game->map->wall;
			else if (game->map->grid[y][x] == 'P')
				img_draw = player_drawing(game, y, x);
			else if (game->map->grid[y][x] == 'C')
				img_draw = game->map->coins;
			else if (game->map->grid[y][x] == 'E')
				img_draw = game->map->exit;
			else if (game->map->grid[y][x] == 'A')
				img_draw = void_drawing(game, y, x);
			else if (game->map->grid[y][x] == 'D')
				img_draw = exit_drawing(game, y, x);
			else if (game->map->grid[y][x] == 'S')
				img_draw = game->player->player_on_void[0];
			else if (game->map->grid[y][x] == 'V')
				img_draw = game->map->void_coin;
			else
				img_draw = game->map->wall;
			mlx_put_image_to_window(game->mlx, game->win, img_draw, TILE_SIZE * x, TILE_SIZE * y);
			x++;
		}
		y++;
		x = 0;
	}
}

void	*player_drawing(t_game *game, int y, int x)
{
	void *img;
	img= game->player->player[game->player->frames_player];
	game->map->player_x = x;
	game->map->player_y = y;
	return (img);
}

void	*void_drawing(t_game *game, int y, int x)
{
	void *img;
	img= game->player->player_on_void[game->player->frames_on_void];
	game->map->player_x = x;
	game->map->player_y = y;
	return (img);
}

void	*exit_drawing(t_game *game, int y, int x)
{
	void *img;
	img= game->player->player_on_exit[game->player->frames_on_exit];
	game->map->player_x = x;
	game->map->player_y = y;
	return (img);
}
