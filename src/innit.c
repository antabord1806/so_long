/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025-10-09 15:00:56 by antabord          #+#    #+#             */
/*   Updated: 2025-10-09 15:00:56 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_fun.h"
#include "a_structs.h"


void	init_grid(t_map *map)
{
	ft_calloc(0, sizeof(t_map));
	if (!map)
		return ;
}

void	find_p_x(t_map *map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		while (x < map->width)
		{
			if (map->grid[y][x] == 'P')
			{
				map->player_x = x;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	find_p_y(t_map *map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		while (x < map->width)
		{
			if (map->grid[y][x] == 'P')
			{
				map->player_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
}