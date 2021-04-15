#include "filler.h"

int ft_abs(int i)
{
    return (i > 0 ? i : -i);
}


void calculate_manhattan_distance(t_data *map, int y, int x)
{
    int i;
    int j;
    int k;

    i = 0;
    while (map->height_y > i)
    {
        j = 0;
        while (map->width_x > j)
        {
            if (map->heatmap[i][j] != -2 && map->heatmap[i][j] != -1 )
                k = ft_abs( y - i) + ft_abs(x - j);
            if (map->heatmap[i][j] > k || map->heatmap[i][j] == 0)
                map->heatmap[i][j] = k;
            j++;
        }
        i++;
    }
}

void manhattan_distance(t_data *map)
{
    int i;
    int j;

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

void    convert_input(t_data *map, char my_symbol, char their_symbol)
{
    int i;
    int j;

    i = 0;
    while (map->height_y > i)
    {
        j = 0;
        while (map->width_x > j)
        {
            if (map->map[i][j] == my_symbol || map->map[i][j] == my_symbol + 'a' - 'A')
                map->heatmap[i][j] = ENEMY;
            if (map->map[i][j] == their_symbol || map->map[i][j] == their_symbol + 'a' - 'A')
                map->heatmap[i][j] = PLAYER;
            j++;
        }
        i++;
    }
}

int **init_heatmap(int height_y, int width_x)
{
    int **plot;
    int i;
    int j;

    i = 0;
    if ((plot = (int **)malloc(sizeof(int *) * height_y)) == NULL)
        error();
    while (height_y > i)
    {
        if ((plot[i] = (int *)malloc(sizeof(int) * width_x)) == NULL)
            error();
        j = 0;
        while (width_x > j)
            plot[i][j++] = 0;
        i++;
    }
    return(plot);
}

void calculate_heatmap(t_filler *filler)
{
    filler->board->heatmap = init_heatmap(filler->board->height_y, filler->board->width_x);
    convert_input(filler->board, filler->my_symbol, filler->their_symbol);
    manhattan_distance(filler->board);

}