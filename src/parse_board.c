/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:10:50 by bhugo             #+#    #+#             */
/*   Updated: 2021/04/15 20:51:18 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

char	**parse_map(t_filler *filler)
{
	char	**plot;
	char	*line;
	int		i;

	line = NULL;
	get_next_line(0, &line);
	ft_strdel(&line);
	i = 0;
	plot = (char **)malloc(sizeof(plot) * (filler->board ->height_y + 1));
	if (plot == NULL)
		error();
	while (filler->board ->height_y > i)
	{
		plot[i] = (char *)malloc(filler->board ->width_x + 1);
		if (plot[i] == NULL)
			error();
		get_next_line(0, &line);
		ft_strcpy(plot[i++], line + 4);
		ft_strdel(&line);
	}
	plot[i] = NULL;
	return (plot);
}

void	parse_board(t_filler *filler, char *line)
{
	char	**split;

	split = ft_strsplit(line, ' ');
	filler->board = init_data();
	filler->board->height_y = ft_atoi(split[1]);
	filler->board->width_x = ft_atoi(split[2]);
	filler->board->map = parse_map(filler);
	calculate_heatmap(filler);
	free_array(&split);
}
