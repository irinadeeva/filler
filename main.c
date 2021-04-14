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

int			main(void)
{
    t_filler  filler;
    char *line;

    line = NULL;
    init_filler(&filler);
    parse_player(&filler);
    while (get_next_line(0, &line))
    {
        if (line && ft_strstr(line, "Plateau"))
            parse_board(&filler, line);
        if (line && ft_strstr(line, "Piece"))
        {
            parse_piece(&filler, line);
            calc_coords(&filler);
	        ft_putnbr(filler.y);
	        ft_putchar(' ');
	        ft_putnbr(filler.x);
	        ft_putchar('\n');
        }
    }

    return (0);
}