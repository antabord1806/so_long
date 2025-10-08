/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antabord <antabord@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-27 15:26:24 by antabord          #+#    #+#             */
/*   Updated: 2025-09-27 15:26:24 by antabord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_fun.h"
#include "a_structs.h"

void	ft_puterr(char *s)
{
	int i;

	if (!s)
		return;
	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
}

void	ft_puterr_non_exit(char *s)
{
	int i;

	if (!s)
		return;
	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	return ;
}