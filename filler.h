#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"

# define ENEMY -2
# define PLAYER -1


typedef struct	s_data
{
    int			width_x;
    int			height_y;
    char		**map;
    int			**heatmap;
}				t_data;

/*
** my_symbol     — player symbol ['O' or 'X']
** their_symbol  — enemy symbol ['O' or 'X']
** map           — map information
** piece         — piece information
** y             — y coordinate on the map where a piece will be placed
** x             — x coordinate on the map where a piece will be placed
*/

typedef struct	s_filler
{
	char		my_symbol;
    char		their_symbol;
    t_data	    *board;
    t_data		*token;
    int			y;
    int			x;
}				t_filler;

void            parse_board(t_filler *filler, char *line);
void            calculate_heatmap(t_filler *filler);
t_data          *init_data(void);
void            parse_piece(t_filler *filler, char *line);
int		        error(void);
void            calc_coords(t_filler *filler);
#endif