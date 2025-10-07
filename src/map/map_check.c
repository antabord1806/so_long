/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-27 15:26:45 by antabord          #+#    #+#             */
/*   Updated: 2025-09-27 15:26:45 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../a_structs.h"
#include "../a_fun.h"

int check_walls(char *line)
{
    size_t len;
    
    len = ft_strlen(line);
    if (len == 0)
        return 0;
    if (line[len - 1] == '\r')
        len--;
    if (line[0] != '1' || line[len - 1] != '1')
    {
        ft_puterr("Error: Map walls invalid\n");
        return (0);
    }
    return 1;
}

int is_square(char **lines, int n_lines)
{
    int i;
    int len;

    if (!lines || n_lines <= 0)
        return 0;
    i = 1;
    len = ft_strlen(lines[0]);
    while(i < n_lines)
    {
        if (ft_strlen(lines[i]) != len)
        {
            ft_puterr("Error: The map is not rectangular\n");
            return 0;
        }
        i++;
    }
    return 1;
}

int count_e(char *str)
{
    int i;
    int e;

    i = 0;
    e = 0;
    while (str[i])
    {
        if (str[i] == 'E')
            e++;
        i++;
    }
    return (e);
}

int count_p(char *str)
{
    int i;
    int p;

    i = 0;
    p = 0;
    while (str[i])
    {
        if (str[i] == 'P')
            p++;
        i++;
    }
    return (p);
}

int check_counts(char **lines)
{
    int i;
    int e;
    int p;
    int c;

    i = 0;
    e = 0;
    p = 0;
    c = 0;
    while (lines[i])
    {
        e += count_e(lines[i]);
        p += count_p(lines[i]);
        c += count_c(lines[i]);
        i++;
    }
    if (c < 1)
    {
        ft_puterr("Error: No coins!\n");
        return (0);
    }
    if (e != 1 || p != 1)
    {
        ft_puterr("Error: Invalid spawn or exit\n");
        return (0);
    }
    return (1);
}

