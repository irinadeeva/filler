/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:10:45 by bhugo             #+#    #+#             */
/*   Updated: 2021/04/15 21:06:29 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_abs(int i)
{
	if (i > 0)
	{
		return (i);
	}
	else
	{
		return (-i);
	}
}

void	calculate_manhattan_distance(t_data *map, int y, int x)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (map->height_y > i)
	{
		j = 0;
		while (map->width_x > j)
		{
			if (map->heatmap[i][j] != -2 && map->heatmap[i][j] != -1)
				k = ft_abs(y - i) + ft_abs(x - j);
			if (map->heatmap[i][j] > k || map->heatmap[i][j] == 0)
				map->heatmap[i][j] = k;
			j++;
		}
		i++;
	}
}

void	manhattan_distance(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->height_y > i)
	{
		j = 0;
		while (map->width_x > j)
		{
			if (map->heatmap[i][j] == PLAYER)
				calculate_manhattan_distance(map, i, j);
			j++;
		}
		i++;
	}
}

void	convert_input(t_data *map, char my_symbol, char their_symbol)
{
	int	i;
	int	j;

	i = 0;
	while (map->height_y > i)
	{
		j = 0;
		while (map->width_x > j)
		{
			if (map->map[i][j] == my_symbol
				|| map->map[i][j] == my_symbol + 'a' - 'A')
				map->heatmap[i][j] = ENEMY;
			if (map->map[i][j] == their_symbol
				|| map->map[i][j] == their_symbol + 'a' - 'A')
				map->heatmap[i][j] = PLAYER;
			j++;
		}
		i++;
	}
}

void	calculate_heatmap(t_filler *f)
{
	f->board->heatmap = init_heatmap(f->board->height_y, f->board->width_x);
	convert_input(f->board, f->my_symbol, f->their_symbol);
	manhattan_distance(f->board);
}
