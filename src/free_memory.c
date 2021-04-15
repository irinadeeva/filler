//
// Created by Brandy Hugo on 4/15/21.
//

#include "filler.h"

void free_array(char ***array)
{
	char	**current;

	if (array && *array)
	{
		current = ((*array));
		while ((*current))
			free((*(current++)));
		free((*array));
		(*array) = NULL;
	}
}


void get_array(char **array)
{
	//free_array(&array);
	int i;

	i = 0;
	while(array[i])
	{
		i++;
	}
	ft_massive_free(array,i);
}


void	free_heatmap(t_data *data)
{
	int	y;

	y = 0;
		while (y < data->height_y) {
			free(data->heatmap[y]);
			y++;
		}
		free(data->heatmap);
		free(data);
		data = NULL;
}

void    free_board(t_filler *filler)
{
	get_array(filler->board->map);
	free_heatmap(filler->board);
	//free(filler->board);
}

void    free_token(t_filler *filler)
{
	get_array(filler->token->map);
	free(filler->token);
}
