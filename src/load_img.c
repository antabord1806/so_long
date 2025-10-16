/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:26:05 by antabord          #+#    #+#             */
/*   Updated: 2025/10/07 20:31:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_fun.h"
#include "a_structs.h"

void	load_images(void *mlx, t_map *map, t_player *player)
{
	int		x;
	int		y;

	x = TILE_SIZE;
	y = TILE_SIZE;
	map->ground = mlx_xpm_file_to_image(mlx, "assets/raw/xpm/map.xpm", &x, &y);
	map->wall = mlx_xpm_file_to_image(mlx, "assets/raw/xpm/water.xpm", &x, &y);
	map->exit = mlx_xpm_file_to_image(mlx, "assets/raw/xpm/exit.xpm", &x, &y);
	map->coins = mlx_xpm_file_to_image(mlx, "assets/raw/xpm/chest1.xpm", &x,
			&y);
	map->void_coin = mlx_xpm_file_to_image(mlx, "assets/raw/xpm/chest2.xpm", &x,
			&y);
	load_img_animation_player(mlx, player, x, y);
}

void	load_img_animation_player(void *mlx, t_player *player, int x, int y)
{
	player->player[0] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm/xpm the second/idle1.xpm", &x, &y);
	player->player[1] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm/xpm the second/idle2.xpm", &x, &y);
	player->player[2] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm/xpm the second/idle3.xpm", &x, &y);
	player->player[3] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm/xpm the second/idle4.xpm", &x, &y);
	player->player[4] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm/xpm the second/idle5.xpm", &x, &y);
	player->player[5] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm/xpm the second/idle6.xpm", &x, &y);
	player->player[6] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm/xpm the second/idle7.xpm", &x, &y);
	player->player[7] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm/xpm the second/idle8.xpm", &x, &y);
	load_img_animation_player_on_coin(mlx, player, x, y);
}

void	load_img_animation_player_on_coin(void *mlx, t_player *player, int x,
		int y)
{
	player->player_on_coin[0] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm2/pl+chest1.xpm", &x, &y);
	player->player_on_coin[1] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm2/pl+chest2.xpm", &x, &y);
	player->player_on_coin[2] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm2/pl+chest3.xpm", &x, &y);
	player->player_on_coin[3] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm2/pl+chest4.xpm", &x, &y);
	player->player_on_coin[4] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm2/pl+chest5.xpm", &x, &y);
	player->player_on_coin[5] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm2/pl+chest6.xpm", &x, &y);
	player->player_on_coin[6] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm2/pl+chest7.xpm", &x, &y);
	player->player_on_coin[7] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm2/pl+chest8.xpm", &x, &y);
	load_img_animation_exit(mlx, player, x, y);
}

void	load_img_animation_exit(void *mlx, t_player *player, int x, int y)
{
	player->player_on_exit[0] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm3/pl_on_exit1.xpm", &x, &y);
	player->player_on_exit[1] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm3/pl_on_exit2.xpm", &x, &y);
	player->player_on_exit[2] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm3/pl_on_exit3.xpm", &x, &y);
	player->player_on_exit[3] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm3/pl_on_exit4.xpm", &x, &y);
	player->player_on_exit[4] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm3/pl_on_exit5.xpm", &x, &y);
	player->player_on_exit[5] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm3/pl_on_exit6.xpm", &x, &y);
	player->player_on_exit[6] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm3/pl_on_exit7.xpm", &x, &y);
	player->player_on_exit[7] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm3/pl_on_exit8.xpm", &x, &y);
	load_img_player_on_void_coin(mlx, player, x, y);
}

void	load_img_player_on_void_coin(void *mlx, t_player *player, int x, int y)
{
	player->player_on_void[0] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm4/pl_on_voidcoin1.xpm", &x, &y);
	player->player_on_void[1] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm4/pl_on_voidcoin2.xpm", &x, &y);
	player->player_on_void[2] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm4/pl_on_voidcoin3.xpm", &x, &y);
	player->player_on_void[3] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm4/pl_on_voidcoin4.xpm", &x, &y);
	player->player_on_void[4] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm4/pl_on_voidcoin5.xpm", &x, &y);
	player->player_on_void[5] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm4/pl_on_voidcoin6.xpm", &x, &y);
	player->player_on_void[6] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm4/pl_on_voidcoin7.xpm", &x, &y);
	player->player_on_void[7] = mlx_xpm_file_to_image(mlx,
			"assets/raw/xpm4/pl_on_voidcoin8.xpm", &x, &y);
}
