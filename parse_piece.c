#include "filler.h"

void print_token(char **map, int height_y, int width_x)
{
    int i;
    int j;

    i = 0;
    while (height_y > i)
    {
        j = 0;
        while (width_x > j)
        {
            printf(" %c", map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}


char **parse_token(t_data *piece)
{
    char **plot;
    char *line;
    char **split;
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
    ft_strdel(&line);
    filler->token = init_data();
    filler->token->height_y = ft_atoi(split[1]);
    filler->token->width_x = ft_atoi(split[2]);
    filler->token->map = parse_token(filler->token);
    //print_token(filler->token->map, filler->token->height_y, filler->token->width_x);
}