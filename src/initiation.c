/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:50:34 by bhugo             #+#    #+#             */
/*   Updated: 2021/04/15 20:52:09 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_filler(t_filler	*filler)
{
	filler->my_symbol = 0;
	filler->their_symbol = 0;
	filler->board = NULL;
	filler->token = NULL;
	filler->y = 0;
	filler->x = 0;
}

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *)ft_memalloc(sizeof(t_data));
	if (data != NULL)
	{
		data->width_x = 0;
		data->height_y = 0;
		data->map = NULL;
		data->heatmap = NULL;
	}
	return (data);
}

int	**init_heatmap(int height_y, int width_x)
{
	int	**plot;
	int	i;
	int	j;

	i = 0;
	plot = (int **)malloc(sizeof(int *) * height_y);
	if (plot == NULL)
		error();
	while (height_y > i)
	{
		plot[i] = (int *)malloc(sizeof(int) * width_x);
		if (plot[i] == NULL)
			error();
		j = 0;
		while (width_x > j)
			plot[i][j++] = 0;
		i++;
	}
	return (plot);
}
