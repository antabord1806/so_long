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
/*   Created: 2025-09-27 15:26:58 by antabord          #+#    #+#             */
/*   Updated: 2025-09-27 15:26:58 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../a_fun.h"
#include "../a_structs.h"


void	create_map(t_map *map, char **line, int height)
{
	map->grid = line;
	map->width = ft_strlen(line[0]);
	map->height = height;
	if (!check_counts(line) || !top_bottom_walls(line[0], line[map->height - 1]) || !is_square(line, height))
	{
		ft_free_all(line);
		return ;
	}
	find_p_x(map);
	find_p_y(map);
}

int	coin_count(t_map *map)
{
	int x;
	int y;
	int coins;

	coins = 0;
	x = 0;
	y = 0;
	while (y < map->height)
	{
		while (x < map->width)
		{
			if (map->grid[y][x] == 'C')
				coins++;
			x++;
		}
		x = 0;
		y++;
	}
	map->coins_map = coins;
	if (coins != map->coins_found)
	{
		ft_puterr("Invalid coin placement\n");
		return (0);
	}
	return (1);
}

int count_c(char *str)
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