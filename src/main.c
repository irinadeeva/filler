#include "filler.h"

void parse_player(t_filler	*filler)
{
    char *line;

    line = NULL;
    get_next_line(0, &line);
    if (line && ft_strstr(line, "$$$ exec p1") && ft_strstr(line, "bhugo.filler")) {
			filler->my_symbol = 'O';
			filler->their_symbol = 'X';
		}
    if (line && ft_strstr(line, "$$$ exec p2") && ft_strstr(line, "bhugo.filler")) {
			filler->my_symbol = 'X';
			filler->their_symbol = 'O';
		}
    ft_memdel((void **)(&line));
}


static void	init_filler(t_filler	*filler)
{
    filler->my_symbol = 0;
    filler->their_symbol = 0;
    filler->board = NULL;
    filler->token = NULL;
    filler->y = 0;
    filler->x = 0;
}


void set_zero_xy(t_filler *filler)
{
	filler->x = 0;
	filler->y = 0;
}

void print_coordinates(int x, int y)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

int			main(void)
{
    t_filler  filler;
    char *line;

    line = NULL;
    init_filler(&filler);
    parse_player(&filler);
    int i = 0;
    while (get_next_line(0, &line))
    {
        if (line && ft_strstr(line, "Plateau"))
            parse_board(&filler, line);
        if (line && ft_strstr(line, "Piece"))
        {
            parse_piece(&filler, line);
	        calculate_coordinates(&filler);
            print_coordinates(filler.x, filler.y);
	        set_zero_xy(&filler);
	        free_board(&filler);
	        free_token(&filler);
        }
	    ft_memdel((void **)(&line));
        if (i++ == 6)
	        return (0);
    }
    return (0);
}