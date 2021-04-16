/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <bhugo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:10:27 by bhugo             #+#    #+#             */
/*   Updated: 2021/04/16 16:11:43 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"
# include <limits.h>

# define ENEMY -2
# define PLAYER -1

typedef struct s_data
{
	int			width_x;
	int			height_y;
	char		**map;
	int			**heatmap;
}				t_data;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

/*
** my_symbol     — player symbol ['O' or 'X']
** their_symbol  — enemy symbol ['O' or 'X']
** map           — map information
** piece         — piece information
** y             — y coordinate on the map where a piece will be placed
** x             — x coordinate on the map where a piece will be placed
*/

typedef struct s_filler
{
	char		my_symbol;
	char		their_symbol;
	t_data		*board;
	t_data		*token;
	int			y;
	int			x;
}				t_filler;

void			parse_board(t_filler *filler, char *line);
void			calculate_heatmap(t_filler *filler);
t_data			*init_data(void);
void			parse_piece(t_filler *filler, char *line);
int				error(void);
void			calculate_coordinates(t_filler *filler);
void			free_array(char ***array);
void			free_board(t_filler *filler);
void			free_token(t_filler *filler);
void			init_filler(t_filler *filler);
t_data			*init_data(void);
int				**init_heatmap(int height_y, int width_x);
t_point			*init_point(void);

#endif