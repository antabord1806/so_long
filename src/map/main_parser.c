/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025-09-27 15:26:37 by antabord          #+#    #+#             */
/*   Updated: 2025-09-27 15:26:37 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../a_fun.h"
#include "../a_structs.h"


void	main_parser(t_map *map, int argc, char **argv)
{
	int fd;
	char *line;

	if (argc != 2)
		ft_puterr("Error: too many arguments!\n");
	if (ft_strlen(argv[1]) < 4 || ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4,
			".ber", 4))
		ft_puterr("Error: Invalid file extension\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_puterr("Error: Can't open file\n");
	line = line_reader(fd);
	close(fd);
	if (!line)
		return (free(line), exit(1));
	map->grid = line_check(line);
	if (!map || !map->grid)
		return (free(line), exit(1));
	fd = n_lines(map->grid);
	if (!create_map(map, map->grid, fd))
		return (free(line), exit(1));
	free(line);
	second_main_parser(map);
}

void	second_main_parser(t_map *map)
{
	flood_fill_st(map, map->player_x, map->player_y, map->height);
	if (!coin_count(map))
	{
		ft_free_all(map->grid);
		exit(1);
	}
}

int	n_lines(char **grid)
{
	int i;

	i = 0;
	while (grid[i])
		i++;
	return (i);
}
