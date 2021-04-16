/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_coordinate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:10:33 by bhugo             #+#    #+#             */
/*   Updated: 2021/04/16 16:25:15 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int 	sum_return(int player_counter, int sum)
{
	if (player_counter == 1)
		return (sum);
	return (-1);
}

int	calc_piece(t_data *board, t_point *p, int j, int i)
{
	if ((p->y + j) < 0 || (p->y + j) >= board->height_y
		|| (p->x + i) < 0 || (p->x + i) >= board->width_x
		|| board->heatmap[p->y + j][p->x + i] == PLAYER)
		return (1);
	return (0);
}

static int	calc_sum(t_data *board, t_data *token, t_point *p)
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
				if (calc_piece(board, p, j, i))
					return (-1);
				if (board->heatmap[p->y + j][p->x + i] == ENEMY)
					player_counter++;
				sum += board->heatmap[p->y + j][p->x + i];
			}
		}
	}
	return (sum_return(player_counter, sum));
}

void	calculate_coordinates(t_filler *filler)
{
	t_point	*p;
	int		sum;
	int		min_sum;

	min_sum = INT_MAX;
	p = init_point();
	p->y = -(filler->token->height_y);
	while (p->y < filler->board->height_y + filler->token->height_y)
	{
		p->x = -(filler->token->width_x);
		while (p->x < filler->board->width_x + filler->token->width_x)
		{
			sum = calc_sum(filler->board, filler->token, p);
			if (sum != -1 && sum < min_sum)
			{
				filler->y = p->y;
				filler->x = p->x;
				min_sum = sum;
			}
			p->x++;
		}
		p->y++;
	}
	free(p);
}
