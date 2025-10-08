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

void	nuke_all(t_game *game)
{
	int	i;

	i = 0;
	if (!game)
		return ;
	while (i < 8)
	{
		if (game->player.player[i])
			mlx_destroy_image(game->mlx, game->player.player[i]);
		if (game->player.player_on_coin[i])
			mlx_destroy_image(game->mlx, game->player.player_on_coin[i]);
		if (game->player.player_on_exit[i])
			mlx_destroy_image(game->mlx, game->player.player_on_exit[i]);
		if (game->player.player_on_void[i])
			mlx_destroy_image(game->mlx, game->player.player_on_void[i]);
		i++;
	}
	if (game->map.wall)
		mlx_destroy_image(game->mlx, game->map.wall);
	if (game->map.ground)
		mlx_destroy_image(game->mlx, game->map.ground);
	if (game->map.coins)
		mlx_destroy_image(game->mlx, game->map.coins);
	if (game->map.exit)
		mlx_destroy_image(game->mlx, game->map.exit);
	if (game->map.void_coin)
		mlx_destroy_image(game->mlx, game->map.void_coin);
	if (game->map.grid)
		ft_free_all(game->map.grid);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
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
