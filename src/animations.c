#include "a_fun.h"
#include "a_structs.h"


int	game_loop(t_game *game)
{
	player_animation(game);
	void_animation(game);
	exit_animation(game);
	map_render(game);
	show_counter(game->mlx, game->win, game->player.moves);
	return (0);
}

int	player_animation(t_game *game)
{
	static int counter = 0;

	counter++;
	if (counter >= 100)
	{
		game->player.frames_player++;
		if (game->player.frames_player >= 8)
			game->player.frames_player = 0;
		map_render(game);
		counter = 0;
	}
	return (0);
}

int	void_animation(t_game *game)
{
	static int counter = 0;

	counter++;
	if (counter >= 100)
	{
		game->player.frames_on_void++;
		if (game->player.frames_on_void >= 8)
			game->player.frames_on_void = 0;
		map_render(game);
		counter = 0;
	}
	return (0);
}

int	exit_animation(t_game *game)
{
	static int counter = 0;

	counter++;
	if (counter >= 100)
	{
		game->player.frames_on_exit++;
		if (game->player.frames_on_exit >= 8)
			game->player.frames_on_exit = 0;
		map_render(game);
		counter = 0;
	}
	return (0);
}
