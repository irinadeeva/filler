//
// Created by Ирина Деева on 10.05.2020.
//


#include "filler.h"

int		error(void)
{
    write(1, "Error\n", 6);
    exit(1);
}

char **parse_map(t_filler *filler)
{
    char **plot;
    char *line;
    int i;

    line = NULL;
    get_next_line(0, &line);
    ft_strdel(&line);
    i = 0;
    if ((plot = (char **)malloc(sizeof(plot) * (filler->board ->height_y + 1))) == NULL)
        error();
    while (filler->board ->height_y > i)
    {
        if ((plot[i] = (char *)malloc(filler->board ->width_x + 1)) == NULL)
            error();
        get_next_line(0, &line);
        ft_strcpy(plot[i++], line + 4);
        ft_strdel(&line);
    }
    plot[i] = NULL;
    return (plot);
}


t_data   *init_data(void)
{
    t_data *data;

    if ((data = (t_data *)ft_memalloc(sizeof(t_data))) != NULL)
    {
        data->width_x = 0;
        data->height_y = 0;
        data->map = NULL;
        data->heatmap = NULL;
    }
    return (data);
}

void parse_board(t_filler *filler, char *line)
{
    char **split;

    split = ft_strsplit(line, ' ');
    filler->board = init_data();
    filler->board->height_y = ft_atoi(split[1]);
    filler->board->width_x = ft_atoi(split[2]);
    filler->board->map = parse_map(filler);
    calculate_heatmap(filler);
    free_array(&split);
}