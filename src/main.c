/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-10 11:55:10 by antabord          #+#    #+#             */
/*   Updated: 2025-10-10 11:55:10 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_fun.h"
#include "a_structs.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	main_parser(&game.map, argc, argv);
	validate_map_size(&game.map);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.width * TILE_SIZE,
			game.map.height * TILE_SIZE, "so_long");
	if (!game.win || !game.mlx)
	{
		nuke_all(&game);
		ft_puterr("Error: mlx init failed\n");
		return (1);
	}
	key_hooks(game.win, &game);
	if (!load_images(game.mlx, &game))
		return (ft_puterr_non_exit("Error: Invalid assets\n"), nuke_all(&game), 1);
	map_render(&game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	nuke_all(&game);
	return (0);
}

void	validate_map_size(t_map *map)
{
	if (map->width > MAX_TILE_WIDTH)
	{
		ft_puterr_non_exit("Error: Map width invalid!\n");
		ft_free_all(map->grid);
		exit(1);
	}
	if (map->height > MAX_TILE_HEIGHT)
	{
		ft_puterr_non_exit("Error: Map height invalid!\n");
		ft_free_all(map->grid);
		exit(1);
	}
}
