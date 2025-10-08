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
	if (ft_strlen(argv[1]) < 4 || ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4,".ber", 4))
		ft_puterr("Error: Invalid file extension\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_puterr("Error: Can't open file\n");
	line = line_reader(fd);
	close(fd);
	if (!line)
		return ;
	map->grid = line_check(line);
	fd = n_lines(map->grid);
	create_map(map, map->grid, fd);
	if (!map)
	{
		free(line);
		return ;
	}
	flood_fill_st(map, map->player_x, map->player_y, map->height);
	if (!coin_count(map))
	{
		free(line);
		return ;
	}
	free(line);
}

int	n_lines(char **grid)
{
	int i;

	i = 0;
	while (grid[i])
		i++;
	return (i);
}

/* void	print_map(char **grid, int height)
{
	int i = 0;

	while (i < height)
	{
		printf("%s\n", grid[i]);
		i++;
	}
} */
