/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_coordinate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:10:33 by bhugo             #+#    #+#             */
/*   Updated: 2021/04/15 21:12:41 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// static int 	calc_fot_piece()
// {
	
// }

static int	calc_sum(t_data *board, t_data *token, int y, int x)
{
	int	j;
	int	i;
	int	sum;
	int	player_counter;

	sum = 0;
	player_counter = 0;
	j = -1;
	while (++j < token->height_y)
	{
		i = -1;
		while (++i < token->width_x)
		{
			if (token->map[j][i] == '*')
			{
				if ((y + j) < 0 || (y + j) >= board->height_y
					|| (x + i) < 0 || (x + i) >= board->width_x
					|| board->heatmap[y + j][x + i] == PLAYER)
					return (-1);
				if (board->heatmap[y + j][x + i] == ENEMY)
					player_counter++;
				sum += board->heatmap[y + j][x + i];
			}
		}
	}
	if (player_counter == 1)
		return (sum);
	return (-1);
}

void	calculate_coordinates(t_filler *filler)
{
	int	j;
	int	i;
	int	sum;
	int	min_sum;

	min_sum = INT_MAX;
	j = -(filler->token->height_y);
	while (j < filler->board->height_y + filler->token->height_y)
	{
		i = -(filler->token->width_x);
		while (i < filler->board->width_x + filler->token->width_x)
		{
			sum = calc_sum(filler->board, filler->token, j, i);
			if (sum != -1 && sum < min_sum)
			{
				filler->y = j;
				filler->x = i;
				min_sum = sum;
			}
			i++;
		}
		j++;
	}
}
