/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-27 15:26:11 by antabord          #+#    #+#             */
/*   Updated: 2025-09-27 15:26:11 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_structs.h"
#include "a_fun.h"

void	ft_free_all(char **arr_aloc)
{
	int	i;

	i = 0;
	while (arr_aloc[i])
	{
		free(arr_aloc[i]);
		i++;
	}
	free(arr_aloc);
}

void	free_grid(char **grid)
{
	int	i;

	if (!grid)
		return ; 

	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}


void	free_map(void *mlx, t_map *map)
{
	if (!map)
		return;
	if (mlx)
	{
		if (map->wall)
			mlx_destroy_image(mlx, map->wall);
		if (map->ground)
			mlx_destroy_image(mlx, map->ground);
		if (map->coins)
			mlx_destroy_image(mlx, map->coins);
		if (map->exit)
			mlx_destroy_image(mlx, map->exit);
		if (map->void_coin)
			mlx_destroy_image(mlx, map->void_coin);
	}
	if (map->grid)
		ft_free_all(map->grid);
	free(map);
}


void free_player(void *mlx, t_player *player)
{
	int i;

	if (!player)
		return;
	i = 0;
	while (i < 8)
	{
		if (mlx && player->player[i])
			mlx_destroy_image(mlx, player->player[i]);
		if (mlx && player->player_on_coin[i])
			mlx_destroy_image(mlx, player->player_on_coin[i]);
		if (mlx && player->player_on_exit[i])
			mlx_destroy_image(mlx, player->player_on_exit[i]);
		if (mlx && player->player_on_void[i])
			mlx_destroy_image(mlx, player->player_on_void[i]);
		i++;
	}
	free(player);
}

void	free_game(t_game *game)
{
	if (!game)
		return;
	
	// Free all images first
	if (game->player)
		free_player(game->mlx, game->player);
	if (game->map)
		free_map(game->mlx, game->map);
	
	// Destroy window
	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);

#ifdef __linux__
	if (game->mlx)
		mlx_destroy_display(game->mlx);
#endif

	if (game->mlx)
		free(game->mlx);
	free(game);
}
