/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:26:32 by antabord          #+#    #+#             */
/*   Updated: 2025/10/07 20:35:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../a_fun.h"
#include "../a_structs.h"

int	top_bottom_walls(char *st_line, char *lst_line)
{
	int	i;

	i = 0;
	while (st_line[i] && lst_line[i])
	{
		if (st_line[i] != '1' || lst_line[i] != '1')
		{
			ft_puterr_non_exit("Error: Map walls invalid\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	flood_fill_st(t_map *map, int x, int y, int height)
{
	char	**copy;
	int		i;

	i = 0;
	copy = ft_calloc(sizeof(char *), (height + 1));
	if (!copy)
		return ;
	while (i < height)
	{
		copy[i] = ft_strdup(map->grid[i]);
		if (!copy[i])
		{
			ft_free_all(copy);
			return ;
		}
		i++;
	}
	copy[i] = NULL;
	flood_filled(copy, x, y, map);
	ft_free_all(copy);
}

void	flood_filled(char **copy, int x, int y, t_map *map)
{
	if (y < 0 || x < 0 || !copy[y] || x >= ft_strlen(copy[y]))
		return ;
	if (copy[y][x] == '1' || copy[y][x] == 'V' || copy[y][x] == 'M')
		return ;
	if (copy[y][x] == 'C')
		map->coins_found++;
	if (copy[y][x] == 'E')
		map->exit_nbr++;
	copy[y][x] = 'V';
	flood_filled(copy, x + 1, y, map);
	flood_filled(copy, x - 1, y, map);
	flood_filled(copy, x, y + 1, map);
	flood_filled(copy, x, y - 1, map);
}

