/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025-10-09 15:00:20 by antabord          #+#    #+#             */
/*   Updated: 2025-10-09 15:00:20 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../a_fun.h"
#include "../a_structs.h"


int	create_map(t_map *map, char **line, int height)
{
	map->grid = line;
	map->width = ft_strlen(line[0]);
	map->height = height;
	if (!check_counts(line) || !top_bottom_walls(line[0], line[map->height - 1])
		|| !is_square(line, height))
	{
		ft_free_all(line);
		return (0);
	}
	find_p_x(map);
	find_p_y(map);
	return (1);
}

int	coin_count(t_map *map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		while (x < map->width)
		{
			if (map->grid[y][x] == 'C')
				map->coins_map++;
			x++;
		}
		x = 0;
		y++;
	}
	if (map->coins_map != map->coins_found)
	{
		ft_puterr_non_exit("Invalid coin or enemy placement\n");
		return (0);
	}
	else if (map->exit_nbr != 1)
	{
		ft_puterr_non_exit("Invalid exit placement\n");
		return (0);
	}
	else
		return (1);
}

int	count_c(char *str)
{
	int i;
	int p;

	i = 0;
	p = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			p++;
		i++;
	}
	return (p);
}