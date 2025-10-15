/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025-10-09 15:02:34 by antabord          #+#    #+#             */
/*   Updated: 2025-10-09 15:02:34 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_fun.h"
#include "a_structs.h"


int	handle_keypress(int key, t_game *game)
{
	if (key == KEY_ESC)
		destroy_win(game);
	else if (key == KEY_W)
		move_check(game, game->map.player_y - 1, game->map.player_x);
	else if (key == KEY_A)
		move_check(game, game->map.player_y, game->map.player_x - 1);
	else if (key == KEY_S)
		move_check(game, game->map.player_y + 1, game->map.player_x);
	else if (key == KEY_D)
		move_check(game, game->map.player_y, game->map.player_x + 1);
	return (0);
}

int	destroy_win(t_game *game)
{
	ft_puterr_non_exit("window closed\n");
	nuke_all(game);
	return (0);
}

void	key_hooks(void *win, t_game *game)
{
	mlx_hook(win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(win, 17, 0, destroy_win, game);
}