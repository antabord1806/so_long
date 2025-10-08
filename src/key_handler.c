/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-29 10:43:35 by antabord          #+#    #+#             */
/*   Updated: 2025-09-29 10:43:35 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_fun.h"
#include "a_structs.h"

int handle_keypress(int key, t_game *game)
{

    if (key == KEY_ESC)
        destroy_win(game);
    else if (key == KEY_W)
        move_check(game, game->map.player_y - 1, game->map.player_x, 'w');
    else if (key == KEY_A)
        move_check(game, game->map.player_y, game->map.player_x - 1, 'a');
    else if (key == KEY_S)
        move_check(game, game->map.player_y + 1, game->map.player_x, 's');
    else if (key == KEY_D)
        move_check(game, game->map.player_y, game->map.player_x + 1, 'd');
    return (0);
}
int destroy_win(t_game *game)
{
    ft_puterr("window closed\n");
    nuke_all(game);
    //mlx_destroy_window(game->mlx, game->win);
    exit(0);
    return (0);
}

int minimizer()
{
    ft_puterr("window minimized\n");
    return (0);
}

int maximizer()
{
    ft_puterr("window maximized\n");
    return (0);
}

int ressizer()
{
    ft_puterr("window ressized\n");
    return (0);
}