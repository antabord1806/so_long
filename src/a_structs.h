#ifndef A_STRUCTS_H
#define A_STRUCTS_H

#ifndef __KEYS__
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307
#endif


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <fcntl.h>

#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include "a_fun.h"

//assets
typedef struct s_map {
    char    **grid;
    int     width;
    int     height;
    int     coins_map;
    int     coins_found;
    int     player_x;
    int     player_y;
    void    *player;
    void    *wall;
    void    *coins;
    void    *player_on_coin;
    void    *player_on_void;
    void    *void_coin;
    void    *player_on_exit;
    void    *ground;
    void    *exit;
}   t_map;

typedef struct s_player {
    int     moves;
    int     frames_player;
    void    *player[8];
    int     frames_on_coin;
    void    *player_on_coin[8];
    int     frames_on_exit;
    void    *player_on_exit[8];
    int     frames_on_void;
    void    *player_on_void[8];
    void    *walking;
}   t_player;


typedef struct s_game {
    void    *win;
    void    *mlx;
    t_player    *player;
    t_map       *map;
}   t_game;

#endif