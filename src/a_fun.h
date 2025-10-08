#ifndef A_FUN_H
#define A_FUN_H

#include "a_structs.h"
#include "../minilibx-linux/minilibx-linux/mlx.h"
#include "../libft/libft.h"

#ifndef TILE_SIZE
#define TILE_SIZE 64
#endif

#ifndef MAX_TILE_WIDTH
#define MAX_TILE_WIDTH 30
#endif

#ifndef MAX_TILE_HEIGHT
#define MAX_TILE_HEIGHT 16
#endif

typedef struct s_map t_map;
typedef struct s_game t_game;
typedef struct s_player t_player;

int	main(int argc, char **argv);

//error + free
void	ft_puterr(char *s);
void	ft_puterr_non_exit(char *s);
void	ft_free_all(char **arr_aloc);
void	nuke_all(t_game *game);

//map
    //parsing
    void	main_parser(t_map *map, int argc, char **argv);
    char    *read_block(int fd);
    char    *line_reader(int fd);
    char    **line_check(char *str);
    int     n_lines(char **grid);
    int     validate_chars(char *s);
    int     check_walls(char *line);
    int     check_counts(char **lines);
    int     line_parser(char *str);
    int     count_e(char *str);
    int     count_p(char *str);
    int     count_c(char *str);
    int     is_square(char **lines, int n_lines);
    int     top_bottom_walls(char *st_line, char *lst_line);
    int     e_p_finder(char **lines, int max_y, int max_x);
    void	flood_fill_st(t_map *map, int x, int y, int height);
    void	flood_filled(char **copy, int x, int y, int *coins);
    int     coin_count(t_map *map);
    void	print_map(char **grid, int height);
    void	validate_map_size(t_map *map);
    
    //to_struct
    void   create_map(t_map *map, char **lines, int n_lines);
    void	init_grid(t_map *map);
    t_game  *game_init(t_map *map, t_player *player);
    t_player    *player_init();
    void    find_p_x(t_map *map);
    void    find_p_y(t_map *map);

    //render
    void    load_images(void *mlx, t_map *map, t_player *player);
    void	load_img_animation(void *mlx, t_player *player, int	x, int y);
    void	map_render(t_game *game);
    int	game_loop(t_game *game);
    void    *player_drawing(t_game *game, int y, int x);
    void	*exit_drawing(t_game *game, int y, int x);
    void	*void_drawing(t_game *game, int y, int x);
    int	    player_animation(t_game *game);
    int	void_animation(t_game *game);
    int	exit_animation(t_game *game);
    
    //keys & hooks
    void	key_hooks(void *win, t_game *game);
    int     handle_keypress(int key, t_game *game);
    int     move_check(t_game *game, int new_y, int new_x, char key);
    char    restore_tile(char tile);
    void	coin_collected_check(t_game	*game);
    void	update_coins(t_game *game);
    void	move_player(t_game *game, int new_y, int new_x);
    int     destroy_win(t_game *game);
    int     minimizer();
    int     maximizer();
    int     ressizer();

#endif