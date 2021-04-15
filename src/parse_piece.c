#include "filler.h"


char **parse_token(t_data *piece)
{
    char **plot;
    char *line;
    int i;

    i = 0;
    if ((plot = (char **)malloc(sizeof(plot) * (piece->height_y + 1))) == NULL)
        error();
    while (piece->height_y > i)
    {
        if ((plot[i] = (char *)malloc(piece->width_x + 1)) == NULL)
            error();
        (get_next_line(0, &line)== -1) ? error() : 0;
        ft_strcpy(plot[i++], line);
        ft_strdel(&line);
    }
    plot[i] = NULL;
    return (plot);
}

void  parse_piece(t_filler *filler, char *line)
{
    char **split;

    split = ft_strsplit(line, ' ');
    filler->token = init_data();
    filler->token->height_y = ft_atoi(split[1]);
    filler->token->width_x = ft_atoi(split[2]);
    filler->token->map = parse_token(filler->token);
	free_array(&split);
}